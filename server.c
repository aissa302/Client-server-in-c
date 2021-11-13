/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

// A function to print errors
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr; // Two structure to hold server socketoptions and client socket option such as IP and Port
     int n;
   
     // Check whether the port value is provided by the user or not
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
   
     // create a server TCP socket
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
   
     //clean the memory buffer of serv_addr
     bzero((char *) &serv_addr, sizeof(serv_addr));
   
     // Turn the privided port by user into an integer
     portno = atoi(argv[1]); 
     
     // Set server IP and port
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno); // Turn the port from host format to network format
   
     // Bind the socket with IP and port
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
   
     // Listen for client connection MAX 5 connections
     printf("[+] Listening to incoming connections...\n")
     listen(sockfd,5);
   
     clilen = sizeof(cli_addr);
   
     // Accept an incoming connection from the client
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0) // check whether the socket is opened or not 
          error("ERROR on accept");
     print("[+] Connection accepted...\n")
     // Clean the buffer
     bzero(buffer,256);
   
     if(recv(newsockfd,buffer,sizeof(buffer), 0);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     close(newsockfd);
     close(sockfd);
     return 0; 
}
