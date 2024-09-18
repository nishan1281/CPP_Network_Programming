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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
