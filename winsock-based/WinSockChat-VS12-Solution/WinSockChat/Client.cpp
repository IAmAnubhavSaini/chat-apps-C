#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib") 


int CreateClientLocal(){
  SOCKADDR_IN clntAddr;
  INT clntPort = 6655;
  clntAddr.sin_family = AF_INET;
  clntAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.19");
  clntAddr.sin_port = htons(clntPort);
  printf("\nClient Address: %X", clntAddr.sin_addr.S_un.S_addr);
  SOCKET clntSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  return 0;
}