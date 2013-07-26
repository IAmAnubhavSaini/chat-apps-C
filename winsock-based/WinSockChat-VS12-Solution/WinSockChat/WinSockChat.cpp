// WinSockChat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WinSock2.h>
#include "Server.h"
#include "Client.h"
#pragma comment(lib, "ws2_32.lib") 
void CleanUp(void);
int _tmain(int argc, _TCHAR* argv[])
{
  WSADATA wsaData;
  int isVersionOkay = 0;
  int ret;

  if((ret = WSAStartup(MAKEWORD(2,2), &wsaData)) != 0){
    printf("\nWSA startup failed with error: %ld.\n", WSAGetLastError());
  }
  else{
    printf("\nwinsock dll found.");
    printf("\nThe current status is : %ld.", wsaData.szSystemStatus);
  }
  if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion)!= 2){
    printf("\nIncompatible winsock dll version: %u %u", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    CleanUp();
    exit(0);
  }
  else{ 
    printf("\nCompatible winsock dll version: %u %u",  LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("\nHighest supported version: %u %u", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("\nWill continue, sit tight.");
    isVersionOkay = 1;
  }

  if(isVersionOkay == 1){


    CreateServerLocal();
    CreateClientLocal();







  }

  CleanUp();
  return 0;
}
void CleanUp(void){
  printf("\n");
  if(WSACleanup() == SOCKET_ERROR){
    printf("\nWSA cleanup failed with error: %ld.\n", WSAGetLastError());
  }
  printf("\n");
}

