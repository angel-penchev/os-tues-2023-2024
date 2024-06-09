#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

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

    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }

    if(listen(sockfd, 3) == -1) {
        perror("listen");
        return 1;
    }

    struct sockaddr_in client_address;
    socklen_t client_address_len;
    int clientfd = accept(sockfd, (struct sockaddr *) &client_address, &client_address_len);
    if (clientfd == -1) {
        perror("accept");
        return 1;
    }

    int filefd = open("example.txt", O_RDONLY);
    if (filefd == -1) {
        perror("open file");
        return 1;
    }

    char buff[10];
    int read_bytes;
    while (read_bytes = read(filefd, &buff, 5) > 0)
    {
        if (read_bytes == -1) {
            perror("read");
            return 1;
        }
        printf("%d", read_bytes);

        write(clientfd, &buff, read_bytes);
    } 

    printf("File sent successfully.");

    close(clientfd);
    close(sockfd);
    return 0;
}