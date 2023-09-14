#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>

#define CMAX 10  // client limit

const char *name = "OS";  // name of share memory obj

int main(int argc, char *argv[]) {
    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    const int KEY_BASE = 1001;
    const int LISTEN = 5;
    // set Message Passing queue id adress
    int *qid = mmap(NULL, 2*CMAX, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    // init share memory
    int count = 0;
    for(;count <= LISTEN+1; count++){
        qid[count] = msgget((key_t) KEY_BASE+count, 0666|IPC_CREAT);
    }
    count = CMAX;
    for(;count < 2*CMAX; count++){  // init sit
        qid[count] = 0;
    }
    printf("success init share memory and qid !\n");

    // close
    munmap(qid, 2*CMAX);
    close(fd);
    return 0;
}
