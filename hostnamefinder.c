#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <indirizzo IP>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(target_ip);

    struct hostent *host_info = gethostbyaddr((char *)&target.sin_addr, sizeof(struct in_addr), AF_INET);

    if (host_info) {
        printf("Indirizzo IP: %s\n", target_ip);
        printf("Nome host: %s\n", host_info->h_name);
    } else {
        printf("Impossibile ottenere informazioni sul dispositivo.\n");
    }

    return 0;
}
