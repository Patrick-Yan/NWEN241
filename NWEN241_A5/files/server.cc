#include <cstring>    // sizeof()
#include <iostream>
#include <string>
// headers for socket(), getaddrinfo() and friends
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>    // close()
#include "dbTable.hh"
#define SERVER_PORT 12345


int main(){

  int socketfd;
  socklen_t clilen;
  AbstractDbTable *db;
  db = new AbstractDbTable();
	bool loaded = db -> loadCSV("scifi.csv");

  sockaddr_in serv_addr, client_addr;
  char buffer[200];

  std::cerr << "Starting server..." << std::endl;

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(SERVER_PORT);

  /* Step 1 : create a socket with the socket() system call */
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    std::cerr << "Error while creating socket" << std::endl;
    exit(1);
  }

  /* Step 2 : Bind the socket to an address using the bind() system call */
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    std::cerr << "Error while binding socket" << std::endl;
    // if some error occurs, make sure to close socket and exit
    close(sockfd);
    exit(1);
  }


  /* Step 3 : Listen for connections with the listen() system call */
  if (listen(sockfd, SOMAXCONN) < 0) {
    std::cerr << "Error while Listening on socket" << std::endl;
    // if some error occurs, make sure to close socket and exit
    close(sockfd);
    exit(1);
  }


  // structure large enough to hold client's address
  socklen_t client_addr_size = sizeof(client_addr);


  const std::string response = "Hello World";


  /* Step 4 : Accept a connection with the accept() system call */
  int clientfd = accept(sockfd, (sockaddr *) &client_addr, &client_addr_size);

  if (clientfd < 0) {
    std::cerr << "Error while Accepting on socket" << std::endl;
    exit(1);
  }

  while (1) {

    /*reset the buffer*/
    memset(buffer, 0, 200);

    /* Step 5 : Send and receive data */
    int r = recv(clientfd,buffer,200, 0);

    if (r < 0) {
      std::cerr << "Error while reading from socket" << std::endl;
      exit(1);
    }

    std:: cout << "Message received: " << buffer << std::endl;

    /* Deals with \n character for excit from NC */
    if ((strcasecmp(buffer, "BYE") == 0) || (strcasecmp(buffer, "BYE\n") == 0) ){
      std:: cout << "Closing connection with client." << std::endl;
      close(clientfd);
      close(sockfd);
      exit(0);
    }
    if (strcasecmp(buffer, "GET") == 0 || strcasecmp(buffer, "GET\n") == 0 ){
			string moviesString = db -> get();
			const char* movies = moviesString.c_str();
			if (send(clientfd, movies, strlen(movies), 0) < 0) {
				cout << "Error: cannot write to socket." << endl;
				exit(1);
			}
		}

    std::cout << "Message is reversed: " << buffer << std::endl;

    /* Step 5 : Send and receive data */
    int s = send(clientfd,buffer,strlen(buffer), 0);

    if (s < 0) {
      std::cerr << "Error while writing to socket" << std::endl;
      exit(1);
    }
  }

  return 0;
}
