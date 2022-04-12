#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <time.h>
#include "p1a.c"
#include "p2a.c"
#include "p1b.c"
#include "p2b.c"
#include "p1c.c"
#include "p2c.c"

int main()
{
    int choiceq;
    printf("\nSelect the program you wan to run\n");
    printf("1.P1 Unix Domain Sockets\n2.P2 Unix Domain Socket\n3.P1 FIFOs\n4.P2 FIFOs\n5.P1 Message Passing Queues\n6.P2 Messag Passing Queues\n");
    scanf("%d",&choiceq);
    if(choiceq==1){
        printf("\nP1 UNIX DOMAIN SOCKETS\n");
        p1c();
    }
    if(choiceq==2){
        printf("\nP2 UNIX DOMAIN SOCKETS\n");
        p2c();
    }
    if(choiceq==3){
        printf("\nP1 FIFO\n");
        p1b();
    }
    if(choiceq==4){
        printf("\nP2 FIFO\n");
        p2b();
    }
    if(choiceq==5){
        printf("\nP1 Message Passing queues\n");
        p1a();
    }
    if(choiceq==6){
        printf("\nP2 Message Passing queues\n");
        p2a();
    }
}