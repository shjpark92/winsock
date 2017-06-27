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
    printf("Success\n");

    printf("Creating socket... ");
    if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Failed to create socket.\nERROR: %d", WSAGetLastError());
        return 1;
    }
    printf("Success\n");
    
    return 0;
}

