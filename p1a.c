#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/socket.h>
#include <sys/un.h>
#include<sys/stat.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
struct mesg_buffer
{
    long mesg_type;
    char mesg_text[6];
    int ret;
};
int p1a()
{   
 int msgid;
remove("IIITD.txt");
msgctl(msgid,IPC_RMID,NULL);
unlink("IIITD.txt");
struct mesg_buffer message;
system("touch IIITD.txt");// a file is created to be used as key
key_t key;
key=ftok("IIITD.txt",'A'); // a key is created and A is ID ,the same key to be used in process communication
if(key==-1)
{
    perror("ftok");
    exit(1);
}
msgid =msgget(key,0666|IPC_CREAT);
 if(msgid==-1)
{
    perror("msgget");
    exit(1);
}
    /* CODE FOR CREATING RANDOM STRINGS */
    char rdnm[10][5][6];
    memset(rdnm,0,310);
    srand(time(0));
    for (int i =0 ; i<10; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            rdnm[i][j][0]=  (rand()%26)+65;
            rdnm[i][j][1]=  (rand()%26)+65;
            rdnm[i][j][2]=  (rand()%26)+65;
            rdnm[i][j][3]=  (rand()%26)+65;
            rdnm[i][j][4]=  (rand()%26)+65;
        }
     }
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<5;j++)
        {
            strcpy(message.mesg_text,rdnm[i][j]);
            message.mesg_type=1;
            
            msgsnd(msgid,&message,sizeof(rdnm[i][j]),0);//send message of type 1 to p2
            sleep(1);
        }
        msgrcv(msgid,&message,sizeof(message),2,0); //receive message of type 2 from p2
        printf("\n The index value received from p2 is %d \n",message.ret);
    }
        msgctl(msgid,IPC_RMID,NULL);
        //remove("IIITD.txt");
    
    return 0;
}