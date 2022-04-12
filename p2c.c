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
#include<time.h>
 int p2c()
 {
    struct sockaddr_un p2;
    int p2data_socket;
    int b,n,ret;
    char buff[51][6];
    p2data_socket=socket(AF_UNIX,SOCK_STREAM,0);
   if(p2data_socket==-1)
   {
       printf("\n UNABLE TO CREATE TO SOCKE \n");
       exit(0);
   }
   p2.sun_family=AF_UNIX;
   strncpy(p2.sun_path,"IIITD.txt",sizeof(p2.sun_path));
   ret=connect(p2data_socket,(const struct sockaddr *) &p2,sizeof(struct sockaddr_un));
   if(ret==-1)
   {
      printf("\n P1 IS NOT RUNNIMG\n");
      exit(0);
   }
   b=0;
   for(int i=0;i<10;i++)
   {

      n=b;   
            for(int a=n;a<=n+4;a++)
           {
             read(p2data_socket,buff[a],sizeof(buff[a]));
             printf("\n The string received from P1 is %s and index is %d ",buff[a],b);
             b++;
           }  
              int x = b-1;
              write(p2data_socket,&x,sizeof(int));
              printf("\n");
    }     
   printf("\n");
   close(p2data_socket);
   return 0;
}