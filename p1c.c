#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include<time.h>
int p1c()
{
  /* RANDOM ARRAY GENERATION */
char rdnm[10][5][6];
    memset(rdnm,0,300);
    srand(time(0));
    for (int i=0; i<10; i++)
    {
        for (int j = 0; j<5;j++)
        {
            rdnm[i][j][0]=  (rand()%26)+65;
            rdnm[i][j][1]=  (rand()%26)+65;
            rdnm[i][j][2]=  (rand()%26)+65;
            rdnm[i][j][3]=  (rand()%26)+65;
            rdnm[i][j][4]=  (rand()%26)+65;

        }
    }

    struct sockaddr_un p1; 
    char buff[50][6];  
    int x;
    int b,ret; 
    int p1data_socket; 
    int p1connection_socket; 
    unlink("IIITD.txt");
    /*attaching values to socket address identifier */
    p1.sun_family=AF_UNIX;
    strncpy(p1.sun_path,"IIITD.txt",sizeof(p1.sun_path)); 
    p1connection_socket=socket(AF_UNIX,SOCK_STREAM,0); // socket is created
    if(p1connection_socket==-1)
    {
      printf("\n UNABLE TO CREATE SOCKET \n");
      exit(0);
    }
    p1.sun_family=AF_UNIX;
    strncpy(p1.sun_path,"IIITD.txt",sizeof(p1.sun_path)); 
    ret=bind(p1connection_socket,(const struct sockaddr *) &p1,sizeof(struct sockaddr_un)); //binding a socket with values
     if(ret==-1)
    {
      printf("\n CONNECTION FAILED \n");
      exit(0);
    }
    ret=listen(p1connection_socket,1);
    if(ret==-1)
    {
      printf("\n UNABLE TO LISTEN \n");
      exit(0);
    }
   p1data_socket=accept(p1connection_socket,NULL,NULL);
   if(p1data_socket==-1)
   {
     printf("\n UNABLE TO ACCEPT REQUEST \n ");
     exit(0);
   }
                for(int i=0;i<10;i++)
                {
                      sleep(1);
                      for(int j=0;j<5;j++)
                      {
                        write(p1data_socket,rdnm[i][j],sizeof(rdnm[i][j]));
                       }
                read(p1data_socket,&x,sizeof(int));
                sleep(1);
                printf("\n index received from p2 is %d \n",x);
                printf("\n");
                }
  close(p1data_socket);
  close(p1connection_socket);
  unlink("IIITD.txt");
  exit(0);
}