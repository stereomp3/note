provider "aws" {
  region = "us-east-1"
}

resource "aws_vpc" "testvpc"{
    cidr_block="192.168.0.0/16"
    tags = {
        Name = "testvpc"
    }
}

resource "aws_subnet" "testvpc-web" {
    vpc_id = "${aws_vpc.testvpc.id}"
    cidr_block = "192.168.1.0/24"
    availability_zone = "us-east-1a"
    tags = {
        Name = "testvpc-web"
    }
}

resource "aws_internet_gateway" "igw" {
    vpc_id="${aws_vpc.testvpc.id}"
    tags = {
        Name = "testvpc-igw"
    }
}

resource "aws_route_table" "myrt" {
    vpc_id="${aws_vpc.testvpc.id}"

    route {
        cidr_block="0.0.0.0/0"
        gateway_id = "${aws_internet_gateway.igw.id}"
    }

    tags = {
        Name = "testvpc-rt"
    }
}

resource "aws_route_table_association" "myrt_assoc" {
    subnet_id = aws_subnet.testvpc-web.id
    route_table_id = aws_route_table.myrt.id
}

resource "aws_security_group" "sg_testvpc" {
    name = "sg_testvpc"
    description="security group for testvpc"
    vpc_id="${aws_vpc.testvpc.id}"

    ingress {
       description = "HTTPS traffic"
       from_port = 443
       to_port = 443
       protocol ="tcp"
       cidr_blocks = ["0.0.0.0/0"]   
    }

    ingress {
       description = "HTTP traffic"
       from_port = 80
       to_port = 80
       protocol ="tcp"
       cidr_blocks = ["0.0.0.0/0"]   
    }

    ingress {
       description = "SSH traffic"
       from_port = 22
       to_port = 22
       protocol ="tcp"
       cidr_blocks = ["0.0.0.0/0"]   
    }

    egress {
        from_port = 0
        to_port = 0
        protocol ="-1"
        cidr_blocks= ["0.0.0.0/0"]  
    }

    tags = {
        Name = "sg_testvpc"
    }
}

resource "aws_network_interface" "webserver-nic" {
    subnet_id = aws_subnet.testvpc-web.id
    private_ips=["192.168.1.100"]
    security_groups = ["${aws_security_group.sg_testvpc.id}"]  
}

resource "aws_eip" "web-eip" {
    vpc = true
    network_interface = aws_network_interface.webserver-nic.id
    associate_with_private_ip = "192.168.1.100"
    depends_on = [aws_internet_gateway.igw] 
}

resource "aws_instance" "webserver" {
  ami="ami-0261755bbcb8c4a84"
  instance_type = "t2.micro"
  availability_zone = "us-east-1a"
  key_name = "myAWS"

  network_interface {
    device_index = 0
    network_interface_id = aws_network_interface.webserver-nic.id
  }
  
  user_data = <<-EOF
              #!/bin/bash
              sudo apt update -y
              sudo apt install apache2 -y
              sudo systemctl start apache2
              sudo bash -c 'echo your very first web server > /var/www/html/index.html'
              EOF   
  tags ={
    Name = "web-server"
  }
}
