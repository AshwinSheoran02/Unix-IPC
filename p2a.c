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
/*struct mesg_buffer
{
    long mesg_type;
    char mesg_text[6];
    int ret;
    };*/
int p2a()
{  
int b,a,n;
struct mesg_buffer message;
int msgid;
key_t key;  // variable for storing key
key=ftok("IIITD.txt",'A'); // a key is created and A is ID ,the same key to be used in p1
 if(key==-1)
{
    perror("P1");
    exit(1);
}
msgctl(msgid,IPC_RMID,NULL);
msgid =msgget(key,0666|IPC_CREAT); // creating a message queue
if(msgid==-1)
{
    perror("msgget");
    exit(1);
}
                b=0;
                for(int i=0;i<10;i++)
                {
                      n=b;
                      sleep(2);
                      for(a=n;a<n+5;a++)
                      {
                        msgrcv(msgid,&message,sizeof(message),1,0); //receiving data of type 1 from p1
                        printf("\n The String received from p1 is: %s The index is %d",message.mesg_text , b);
                        b++;
                     }
                     printf("\n ============================================ \n ");
                     sleep(1);  
                     message.ret=b-1;
                     message.mesg_type=2;  // message type modified
                     msgsnd(msgid,&message,sizeof(message),0);  // send message of type 2 to p1

                }    
msgctl(msgid,IPC_RMID,NULL); // message queue is closed
unlink("IIITD.txt");
   return 0;
}                             