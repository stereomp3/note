#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(){
    const int SIZE = 4096;  // size(in bytes) of share memory obj
    const char *name = "OS";  // name of share memory obj
    const char *message_0 = "Hello";
    const char *message_1 = "World!";

    int fd;  // share memery file descriptor
    char *ptr;  // pointer to shared memory obj

    // create share memery obj
    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);  // configure the size of shared memory obj

    // memory map the shared memory obj
    ptr = mmap(0, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    

    // write to the shared memory obj
    sprintf(ptr, "%s", message_0);
    printf(ptr);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0;
}