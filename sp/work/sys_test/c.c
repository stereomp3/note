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

#define SMAX 5*1024  // 個人傳輸的容量上限，一次可以接收5K
#define CMAX 10  // client上限
struct msg_t {
    long mtype; // type 指定要哪一種消息, 0:取第一個, >0:消息類型為 type 的第一個, <0:消息類型 <=abs(type) 的第一個。
    char mtext[SMAX];
};

const char *name = "OS";  // name of share memory obj
struct msg_t msg = {.mtype=1};
int SelfQ = -1, TargetQ = -1;
int ID = -1, TID = -1;

void *receiver(void *argu) {
    while (1) {
        msgrcv(TargetQ, &msg, SMAX, 0, 0);
        if(msg.mtext[0] == 's' && msg.mtext[1] == 'w' && msg.mtext[2] == 'i' && msg.mtext[3] == 't' && msg.mtext[4] == 'c' && msg.mtext[5] == 'h' && msg.mtext[6] == '('){
            printf("target: %d is connect to others...", TID);
            sprintf(msg.mtext, "%s", "hi~\n");
            msgsnd(SelfQ, &msg, SMAX, 0);
        }
        else{
            printf("receive from %d: %s", TID, msg.mtext);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    char id = argv[1][0];
    char Tid = argv[2][0];  // Target id
    ID = id - '0';
    TID = Tid - '0';
    if(ID < 0 || ID >= CMAX || TID < 0 || TID >= CMAX || ID==TID){
        printf("id error or target id error.");
        return;
    } 
    
    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    // set Message Passing queue id adress
    int *qid = mmap(NULL, 2*CMAX, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    
    SelfQ = qid[ID];  // ./c 0 -->qid[0]
    TargetQ = qid[TID];  // ./c 0 ->qid[0]

    qid[2*CMAX-ID] = 1; // active sit

    pthread_t thread1;     // declear thread
    pthread_create(&thread1, NULL, &receiver, NULL);  // chat with target

    // read input and put into Msg in qid
    while (1) {
        fgets(msg.mtext, SMAX, stdin);
        // exit()
        if(msg.mtext[0] == 'e' && msg.mtext[1] == 'x' && msg.mtext[2] == 'i' && msg.mtext[3] == 't' && msg.mtext[4] == '(' && msg.mtext[5] == ')') break;
        // look(target)  // 查看對象是否在線上
        if(msg.mtext[0] == 'l' && msg.mtext[1] == 'o' && msg.mtext[2] == 'o' && msg.mtext[3] == 'k' && msg.mtext[4] == '(') {
            int targetID = msg.mtext[5] - '0';
            if(targetID < 0 || targetID >= CMAX){
                printf("target id error. \n");
                continue;
            }
            if(qid[2*CMAX-targetID] == 1) printf("target is Online \n");
            else printf("target is not Online \n");
        }
        // switch()  // 切換訊息傳送對象
        else if(msg.mtext[0] == 's' && msg.mtext[1] == 'w' && msg.mtext[2] == 'i' && msg.mtext[3] == 't' && msg.mtext[4] == 'c' && msg.mtext[5] == 'h' && msg.mtext[6] == '('){
            int targetID = msg.mtext[7] - '0';
            if(targetID < 0 || targetID >= CMAX){
                printf("target id error. \n");
                continue;
            }
            TargetQ = qid[targetID];
            TID = targetID;
            msgsnd(SelfQ, &msg, SMAX, 0);
            printf("success to switch target:%d ! \n", targetID);
        }
        else{
            msgsnd(SelfQ, &msg, SMAX, 0);
        }
    }
    qid[2*CMAX-ID] = 0;  // exit(), unactive sit
    munmap(qid, 2*CMAX);
    close(fd);
    return 0;
}
