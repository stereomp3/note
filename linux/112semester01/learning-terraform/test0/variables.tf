variable "region" {
    type = string
    default = "us-east-1"
    description="aws region"
}

variable "amis" {
    type=map
    default = {
        us-east-1 = "ami-06b09bfacae1453cb"
    }
    description = "ami id"

}

variable "instance_type" {
    type=string
    default = "t2.micro"
    description = "EC2 instance type"
}


