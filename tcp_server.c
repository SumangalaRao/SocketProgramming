#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
    {
	int sock,sock_cli,sent;
	unsigned int len;
	struct sockaddr_in server,client;
	char msgs[]="all set from server_side@@@";
	char msg[1024];

	
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1)
	{
	   perror("generated from socket:");
	   exit(-1);
	}


	server.sin_family=AF_INET;
	server.sin_port=htons(10000);
	server.sin_addr.s_addr=INADDR_ANY;
	bzero(&server.sin_zero,8);
	
	len=sizeof(struct sockaddr_in);
	

	if(bind(sock,(struct sockaddr *)&server,len)==-1)
	{
	    perror("generated from bind:");
	    exit(-1);
	}
	
	
	if(listen(sock,5)==-1)
	{
	    perror("generated from listen:");
	    exit(-1);
	}
	
	
	while(1)
	{
	    sock_cli=accept(sock,(struct sockaddr *)&client,&len);
	    
	    if(sock_cli==-1)
	    {
	       perror("generated from accept while trying to connect:");
	       exit(-1);
	    }
            

	    sent=send(sock_cli,msgs,strlen(msgs),0);

	    printf("NO OF BYTES SENT= %d ",sent);
	    printf("FROM---- : %s ",inet_ntoa(server.sin_addr));
	    printf("----SENT TO: %s ",inet_ntoa(client.sin_addr));
		
	    if(recv(sock_cli, &msg, sizeof(msg), 0))
	    {
 	    printf("The data from the client is: %s ",msg);
	    exit(0);
	   }
 	   // gets(msgs);
	    
	  
	    close(sock_cli);	

	}

	return 0;
    }
