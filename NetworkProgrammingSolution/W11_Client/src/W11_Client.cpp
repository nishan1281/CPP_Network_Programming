// W11_Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../includes/stdafx.h"
#include "WinSock2.h"
#include "ws2tcpip.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "=== W11 sockets =====";
    cout << "=== CLIENT =====";
    cout << "=== Step1 - Set up DLL =====";

    SOCKET clientSocket;
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


    cout << "\n\n=== Step2 - Set up Server Socket =====\n";

    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Error at socket():" << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }

    else
    {
        cout << "Socket() is OK!" << endl;
    }



    cout << "\n\n=== Step3 - client connect =====\n";
    sockaddr_in clientService;

    clientService.sin_family = AF_INET;
    clientService.sin_port = htons(port);
    InetPton(AF_INET, "127.0.0.1", &clientService.sin_addr.s_addr);

/*Attempt to connect the socket to the specified address and port.Cast of the
  clientService structure to a sockaddr pointer by SOCKADDR data type.
  The connect() function expects a sockaddr pointer, but clientService is of type 
  sockaddr_in. */

    int connectResult;
    connectResult = connect(clientSocket, (SOCKADDR*) &clientService, sizeof(clientService));
    if (connectResult == SOCKET_ERROR) {
        cout << "Faaail to connect" << endl;
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "connect ok. Client can start send and receive data." << endl;
    }

    system("pause");
    WSACleanup();

    return 0;

}
