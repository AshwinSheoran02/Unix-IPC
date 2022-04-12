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
int p2b()
{    
    int n,a,res,h,fd;
    char buff[5][6];
    int b=0;
                for(int i=0;i<=9;i++)
                {
					        fd=open("fifo_p1",O_RDONLY);
                  if(fd==-1)
                  {
                    printf("\n p1 is not running \n");
                    exit(1);
                  }
                  n=b;
					        sleep(1);
                      for(a=n;a<=n+4;a++)
                      {
                        memset(buff[a],0,500);
                        read(fd,buff[a],sizeof(buff[a]));
                        printf("\n The String : %s and its index : %d received  from P1",buff[a],b);
                        b++;
                       }
 		 printf("\n ==============================================================\n");
  	sleep(1);
 		close(fd);
 		fd=open("fifo_p1",O_WRONLY);
  	int x = b-1;          
 		write(fd,&x,sizeof(int));
		  close(fd);
      }
 exit(0);    
     }
    