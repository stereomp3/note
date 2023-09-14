#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
    /*int a = 122323;
    char *buf;
    
    sprintf(buf, "%d", a); 

    printf("%s \n", buf);
    printf("%c \n", buf[0]);
    printf("%c \n", buf[5]);*/

    /*
    int a[17];
    size_t n = sizeof(a) / sizeof(int);
    */
    char id = argv[1][0];
    char Tid = argv[2][0];  // Target id
    int ID = id - '0';
    int TID = Tid - '0';
    printf("%d\n", ID);
    printf("%d", TID);
    return 0;
}