#include "socket.h"
#include <iostream> 
#include <netinet/in.h>
#include <thread>
#include <cstring>
 
using namespace std;

int main()
{
 	char message[1000];
	socket client(); 

	client.initializeClient("127.0.0.1",3000);

	cout << "Enter message to send: " <<endl; 
	cin >> message; 

	client.writeToSocket(message);
	
   return 0; 
}