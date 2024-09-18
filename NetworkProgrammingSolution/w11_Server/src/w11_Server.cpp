// Include necessary header files
// "../includes/stdafx.h" - Precompiled header for Visual Studio (commonly used for faster compilation)
#include "../includes/stdafx.h"

// "WinSock2.h" - Contains declarations for Winsock functions for network programming in Windows
#include "WinSock2.h"

// "ws2tcpip.h" - Additional functions for IPv6 and other advanced Winsock features
#include "ws2tcpip.h"

// Include standard input/output stream library
#include <iostream>

using namespace std;

int main()
{
    // Output some introductory information
    cout << "=== W11 sockets ===== \n";
    cout << "=== SERVER =====\n\n";

    cout << "=== Step1 - Set up DLL refers to initializing the WinSock Library =====\n";

    //WinSock Library is required before any network operations

    // Declare variables for the server socket and accepted socket
    SOCKET serverSocket, acceptSocket;

    // Specify the port number for the server
    int port = 55555;

    // WSADATA structure to hold details of the Windows Sockets implementation
    WSADATA wsaData;

    // Variable to hold error codes returned by Winsock functions
    int wsaerr;

    // Define the version of Winsock required (2.2)
    WORD wVersionRequested = MAKEWORD(2, 2);

    // Initialize Winsock by calling WSAStartup with the requested version
    wsaerr = WSAStartup(wVersionRequested, &wsaData);

    // Check if WSAStartup succeeded
    if (wsaerr != 0) {
        // If WSAStartup failed, output an error message
        cout << "The Winsock dll not found!\n" << endl;
        return 0; // Exit the program if initialization fails
    }

    // If WSAStartup succeeded, continue execution
    else
    {
        // Output success message and system status
        cout << "The Winsock dll found!" << endl;
        cout << "the status: " << wsaData.szSystemStatus << endl;
    }


    cout << "\n\n=== Step2 - Set up Server Socket =====\n";

    serverSocket = INVALID_SOCKET;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Error at socket():" << WSAGetLastError() << endl;
        WSACleanup();
        return 0; // Exit the program if binding fails
    }

    else
    {
        cout << "socket () OK!" << endl;
    }


    cout << "\n\n=== Step3 - Bind Socket =====\n";
    
    //sockaddr_in: in for ipv4. This is a second parameter for bind function.
    sockaddr_in service;

    //There are three parameter we will work with and value is setting below as well
    service.sin_family = AF_INET;
    service.sin_port = htons(port);
    InetPton(AF_INET, "127.0.0.1", &service.sin_addr.s_addr);

    /**InetPton means Internet Presentation to Numeric.This function used to convert
    ip address to binary format (network byte order) and storing the converted
    format in s_addr location of service. **/

    int bindResult;
    bindResult = bind(serverSocket, (struct sockaddr*)&service, sizeof(service));

    if (bindResult == SOCKET_ERROR) {
        cout << "bind () failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 0;
    }

    else
    {
        cout << "bind() is ok" <<endl;
    }

    cout << "\n\n=== Step4 - Initiate Listen =====\n";

    int listenServer = listen(serverSocket, 1);

    if (listenServer == SOCKET_ERROR)
    {
        cout << "listen(): Error listening on socket" << WSAGetLastError() << endl;
    }

    else
    {
        cout << "listen() is OK, i'm waiting for connections.." << endl;
    }


    cout << "\n\n=== Accept Connection from Client =====\n";

    acceptSocket = accept(serverSocket, NULL, NULL);
    if (acceptSocket == INVALID_SOCKET)
    {
        cout << "accept failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return -1; //-1 indicate severe error and its terminating
    }

    cout << "accepted connection" << endl;
    system("pause"); //to see the output in console.
    WSACleanup();
    

    return 0; // End the program
}
