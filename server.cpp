#include "socket.h"
#include <iostream> 
#include <netinet/in.h>
#include <thread>
#include <cstring>

using namespace std;

int main()
{
 	char message[1000];
	socket server();

	server.initializeServer("127.0.0.1",3000);
	server.readFromSocket(message);

	cout << "Message received from client:" <<endl;

	for (int i=0;i< strlen(message); i++)
		cout << message[i];

  	 return 0; 
}
