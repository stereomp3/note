provider "aws" {
  region = var.region
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
    tags = {
        Name = "testvpc-web"
    }
}