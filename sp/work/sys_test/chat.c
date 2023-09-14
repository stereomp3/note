#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

#define SMAX 80  // 個人傳輸的容量上限，一次可以接收80個character

struct msg_t {
    long mtype; // type 指定要哪一種消息, 0:取第一個, >0:消息類型為 type 的第一個, <0:消息類型 <=abs(type) 的第一個。
    char mtext[SMAX];
};

struct msg_t msg = {.mtype=1};
int ClientQ, ServerQ;

void *receiver(void *argu) {
    while (1) {
        msgrcv(ServerQ, &msg, SMAX, 0, 0);
        printf("receive: %s", msg.mtext);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int id = argv[1][0]-'0';
    int q0 = msgget((key_t) 1235, 0666|IPC_CREAT);
    int q1 = msgget((key_t) 1236, 0666|IPC_CREAT);
    
    if (id == 0) {
        ClientQ = q0;
        ServerQ = q1;
    } else {
        ClientQ = q1;
        ServerQ = q0;
    }
    printf("%d", ClientQ);
    printf("%d", ServerQ);
    // use thread to receive message and print 
    pthread_t thread1;     // 宣告執行緒
    pthread_create(&thread1, NULL, &receiver, NULL);  

    // read input and put into myMsg in buf
    while (1) {
        fgets(msg.mtext, SMAX, stdin);
        msgsnd(ClientQ, &msg, SMAX, 0);
    }

    return 0;
}