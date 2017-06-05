#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>

int main(int argc,char **argv)
{
    int sockfd;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof servaddr);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22011);

    inet_aton(argv[1],&(servaddr.sin_addr));

    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));


    bzero( sendline, 100);
    bzero( recvline, 100);
    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[2],"m") == 0 && i == 3)
        {
            if (strlen(argv[i]) < 2) {
                strcat(sendline, " ");
            }
        }
        strcat(sendline, argv[i]);
    }

    write(sockfd,sendline,strlen(sendline)+1);
    read(sockfd,recvline,100);
    printf("%s",recvline);


}