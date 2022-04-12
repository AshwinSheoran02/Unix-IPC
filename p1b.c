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
#include<fcntl.h>
#include<time.h>
int p1b()
{   
    int ret,fd,a;
    char randarr[10][5][6];
    srand(time(0));
    ret=mkfifo("fifo_p1",0666);
    if(ret==-1)
    {
        perror("ret");
        exit(1);
    }
        memset(randarr,0,300);
   /* FOR GENERATING RANDOM STRING*/ 
    for (int i =0 ; i<10; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            randarr[i][j][0]=  (rand()%26)+65;
            randarr[i][j][1]=  (rand()%26)+65;
            randarr[i][j][2]=  (rand()%26)+65;
            randarr[i][j][3]=  (rand()%26)+65;
            randarr[i][j][4]=  (rand()%26)+65;
        }
    }   
/* for sending strings to process 2*/
    for(int i=0;i<=9;i++)
   {
           fd=open("fifo_p1",O_WRONLY);
           if(fd==-1)
           {
               printf("fifo is not opened");
               exit(1);
           }
            for(int j=0;j<=4;j++)
            {
              write(fd,randarr[i][j],sizeof(randarr[i][j]));
            }
            sleep(1);
            close(fd);
            fd=open("fifo_p1",O_RDONLY);
            read(fd,&a,sizeof(int));
            printf("\n The returned index from P2 is %d \n",a);
 close(fd);
  } 
unlink("fifo_p1");
    return 0;
}
