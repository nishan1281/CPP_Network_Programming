#include "stdafx.h"
#include "WinSock2.h"
#include "ws2tcpip.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "=== W11 sockets =====";
    cout << "=== SERVER =====";
    cout << "=== Step1 - Set up DLL =====";

    SOCKET serverSocket, acceptSocket;
    int port = 55555;
    WSADATA wsaData;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);

    wsaerr = WSAStartup(wVersionRequested, &wsaData);

    if (wsaerr != 0) {
        cout << "The Winsock dll not found!" << endl;
        return 0;
    }

    else
    {
        cout << "The Winsock dll found!" << endl;
        cout << "the status:" << wsaData.szSystemStatus << endl;

    }

    return 0;

}