#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket create");
        return -1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8181);
    inet_aton("127.0.0.1", &server_address.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("connect");
    }

    char buff[4];
    if (read(sockfd, &buff, 4) == -1) {
        perror("read");
    }
    puts(buff);

    write(sockfd, "bbb", 4);

    close(sockfd);
    return 0;
}