#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <unistd.h>

#include "protocols/ethernet.h"
#include "protocols/icmp.h"
#include "protocols/ipv4.h"
#include "protocols/tcp.h"
#include "utils/types.h"

int main(void) {
    int sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        std::cerr << "Couldn't create socket (try with sudo)" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Socket successfully created!" << std::endl;

    close(sockfd);
	return EXIT_SUCCESS;
}
