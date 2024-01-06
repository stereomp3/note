variable "availability_zones" {
  default = ["us-east-1a", "us-east-1b"]
}

variable "ips" {
  default = ["192.168.1.0/24", "192.168.2.0/24"]
}


resource "aws_vpc" "vpc" {
  cidr_block="192.168.0.0/16"

  tags = {
    Name = "vpc"
  }
}

resource "aws_internet_gateway" "igw" {
    vpc_id="${aws_vpc.vpc.id}"
    tags = {
        Name = "igw"
    }
}

resource "aws_route_table" "rt" {
    vpc_id="${aws_vpc.vpc.id}"

    route {
        cidr_block="0.0.0.0/0"
        gateway_id = "${aws_internet_gateway.igw.id}"
    }

    tags = {
        Name = "rt"
    }
}

resource "aws_subnet" "subnets" {
  count             = length(var.availability_zones)
  vpc_id            = aws_vpc.vpc.id
  cidr_block        = var.ips[count.index]
  availability_zone = var.availability_zones[count.index]

  tags = {
    Name = "subnet${count.index}"
  }
}

resource "aws_route_table_association" "rt" {
    count = length(var.availability_zones)
    subnet_id = aws_subnet.subnets[count.index].id
    route_table_id = aws_route_table.rt.id
}