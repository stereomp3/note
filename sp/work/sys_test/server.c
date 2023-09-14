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

#define SMAX 80  // 個人傳輸的容量上限，一次可以接收80個character

const char *name = "OS";  // name of share memory obj
char *myMsg, *yourMsg;

void *receiver(void *argu) {
    while (1) {
        if (yourMsg[0] != '\0') {
            printf("receive: %s", yourMsg);
            yourMsg[0] = '\0';
        }
    }
    return NULL;
}


int main(int argc, char *argv[]) {
    int id = argv[1][0]-'0';
    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    char *buf = mmap(NULL, 2*SMAX, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    
    if (id == 0) {
        myMsg = buf;
        yourMsg = buf + SMAX;
    } else {
        myMsg = buf + SMAX;
        yourMsg = buf;
    }
    // use thread to receive message and print 
    pthread_t thread1;     // 宣告執行緒
    pthread_create(&thread1, NULL, &receiver, NULL);  

    // read input and put into myMsg in buf
    while (1) {
        fgets(myMsg, SMAX, stdin);
    }

    munmap(buf, 2*SMAX);
    close(fd);
    return 0;
}
