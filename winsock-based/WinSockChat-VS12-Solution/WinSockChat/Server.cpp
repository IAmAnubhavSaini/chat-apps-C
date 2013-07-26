#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib") 

int CreateServerLocal();

int CreateServerLocal(){
  SOCKADDR_IN servAddr;
  INT servPort = 5566;
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.10");
  servAddr.sin_port = htons(servPort);
  SOCKET servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  printf("\nServer Address: %X", servAddr.sin_addr.S_un.S_addr);

  printf("\nBinding server socket.");
  int bindingResult = bind(servSock , (SOCKADDR *) &servAddr, sizeof(servAddr));
  if(bindingResult == 0){
    printf("\nListening at : %d", servAddr.sin_port);
    listen(servSock, 5);
    SOCKET lstnSock = SOCKET_ERROR;
    while(lstnSock == SOCKET_ERROR){
      lstnSock = accept(servSock, NULL, NULL);
    }
    lstnSock = servSock;
  }
  else{
    printf("\nBinding failed. Exiting.\n");
    exit(1);
  }
  //printf("\nBinding result: %d", bindingResult);
  
  return 0;
}