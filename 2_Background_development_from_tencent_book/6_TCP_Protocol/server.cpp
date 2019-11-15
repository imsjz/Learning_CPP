/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-08-07 14:49:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 4096

int main(int argc, char *argv[]){
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    int n;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("create socket error: %s(errno: %d) \n", strerror(errno), errno);
        return 0;
    }

    //清空servaddr
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // servaddr.sin_addr.s_addr = inet_addr("192.168.1.192");
    servaddr.sin_port = htons(6666);

    //绑定地址
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error\n");
        return 0;
    }

    //监听
    if(listen(listenfd, 10) == -1){
        printf("listen socket error\n");
        return 0;
    }

    printf("============waiting for client's request============\n");
    while(1){
        //循环等待连接
        if((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
            printf("accept socket error\n");
            continue;
        }
        n = recv(connfd, buff, MAXLINE, 0);
        buff[n] = '\0';
        printf("recv msg from client: %s\n", buff);
        close(connfd);
    }
    close(listenfd);
    return 0;
}