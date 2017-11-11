#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<sys/socket.h> 
#include<sys/types.h> 
#include<netinet/in.h> 
int main() 
{ 
	int sfd,lfd,len,choice; 
	char str[20],str1[20],err[20];  
	struct sockaddr_in saddr,caddr;   
	/* #include <netinet/in.h>  
	struct sockaddr_in 
	{     
		short            sin_family;   // e.g. AF_INET     
		unsigned short   sin_port;     // e.g. htons(3490)     
		struct in_addr   sin_addr;     // see struct in_addr, below     char             
		sin_zero[8];  // zero this if you want to }; 
	*/  
	
	sfd=socket(AF_INET,SOCK_STREAM,0);  
	if(sfd<0) 
		perror("FdError");  
	bzero(&saddr,sizeof(saddr)); //copy zeros in address) 
	saddr.sin_family=AF_INET;  
	saddr.sin_addr.s_addr=INADDR_ANY;  
	saddr.sin_port=htons(5465); 
	connect(sfd,(struct sockaddr*)&saddr,sizeof(saddr)); 
	for(;;) 	
	{ 
		read(sfd,str,20); 
		if(!strcmp(str,"exit")) 
		{ 
			printf("Exiting\n"); 
			break; 
		} 
		printf("\n\nReceived%s\n\n1.Do u want to report an error(1Yes 0-No)",str); 
		scanf("%d",&choice); 
		if(!choice) 
			write(sfd,"-1",sizeof("-1")); 
		else 
		{ 
			printf("Enter the sequence no of the frame where error has occured\n"); 
			scanf("%s",err); 
			write(sfd,err,sizeof(err)); 
			read(sfd,str,20); 
			printf("\n\nReceived the re-transmitted frames%s\n\n",str); 
		} 
	} 
}