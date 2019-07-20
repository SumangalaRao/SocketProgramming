#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
 
	int main()
	{
    	    int sockinclient,con;
	    unsigned int len;
    	    char msgc[1024];
   	    sockinclient=socket(AF_INET, SOCK_STREAM, 0);
            char msg[]="success";
 
    	    struct sockaddr_in server;
    	    server.sin_family=AF_INET;
            server.sin_port=htons(10000);
            server.sin_addr.s_addr=INADDR_ANY;
	    bzero(&server.sin_zero,8);
 
	    len=sizeof(struct sockaddr_in);

     	    con=connect(sockinclient,(struct sockaddr*)&server,len);
    	    if(con==-1)
    	    {
                perror("generated from connect:");
        	exit(1);
            }
 
 	  recv(sockinclient, &msgc, sizeof(msgc), 0);

	  printf("The recieved data from the server is: %s ",msgc);
		
 	  	
			
 	  send(sockinclient,msg,strlen(msg),0);
	 
     
	  
           close(sockinclient);
return 0;
}   
