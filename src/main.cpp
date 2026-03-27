#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <iomanip>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <sys/types.h>
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
    std::cout 
        << "Socket successfully created! Press <C-c> to stop running"
    << std::endl;

    uint8_t buf[65536];

    while (true) {
        // Wait for packets
        ssize_t size = recvfrom(sockfd, buf, sizeof(buf), 0, nullptr, nullptr);
        if (size < 0) break;

        EthernetHeader* eth = (EthernetHeader*)buf;
        auto src_oct_1 = eth->src_mac[0];
        auto src_oct_2 = eth->src_mac[1];
        auto src_oct_3 = eth->src_mac[2];
        auto src_oct_4 = eth->src_mac[3];
        auto src_oct_5 = eth->src_mac[4];
        auto src_oct_6 = eth->src_mac[5];

        std::cout << std::hex << std::setfill('0')
            << "MAC: "
            << std::setw(2) << (int)src_oct_1 << ":"
            << std::setw(2) << (int)src_oct_2 << ":"
            << std::setw(2) << (int)src_oct_3 << ":"
            << std::setw(2) << (int)src_oct_4 << ":"
            << std::setw(2) << (int)src_oct_5 << ":"
            << std::setw(2) << (int)src_oct_6
        << std::dec << std::endl;
    }

    close(sockfd);
	return EXIT_SUCCESS;
}
