/* 
 * Socket Programming in Windows using
 * Windows Socket API (WSA)
 */

#include <stdio.h>
#include <winsock2.h>

/* 
 * #pragma comment(lib, libname)
 * Directs VS linker to add $libname library to the list of library dependencies
 */
#pragma comment(lib, "ws2_32.lib") /* Winsock lib */

int main(int argc, char* argv[]) {
    WSADATA wsa;
    SOCKET s;

    printf("\nInitializing winsock... ");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Failed to init winsock.\nERROR: %d", WSAGetLastError());
        return 1;
    }

    if (LOBYTE(wsa.wVersion) != 2 || HIBYTE(wsa.wVersion) != 2) {
        printf("This winsock dll does not support v2.2\n");
        WSACleanup();
        return 1;
    }
    printf("Success\n");


    /* SOCKET WSAAPI socket(int af, int type, int protocol)
     * af (address family) - AF_INET or AF_INET6 (ipv4 or ipv6)
     * type - SOCKET_STREAM (TCP) or SOCK_DGRAM (UDP)
     * protocol - 0 service provider chooses the protocol
     */
    printf("Creating socket... ");
    if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Failed to create socket.\nERROR: %d", WSAGetLastError());
        return 1;
    }
    printf("Success\n");
    
    WSACleanup();

    return 0;
}

