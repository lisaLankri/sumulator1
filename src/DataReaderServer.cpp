#include "DataReaderServer.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <strings.h>
#include <sys/socket.h>
#include "SymbolTable.h"
#include <chrono>
#include <thread>

using namespace std;

DataReaderServer* DataReaderServer::getInstance()
{
    static DataReaderServer instance;
    return &instance;
}

DataReaderServer::DataReaderServer()
{
    sockfd = 0;
}

DataReaderServer::~DataReaderServer()
{
    // close socket
    if (sockfd != 0)
        close(sockfd);
}

#define DATAREADERSERVER_BUFFER_SIZE 1024

void* DataReaderServer::readFromServer(void* arg)
{
    DataReaderServer* dataReaderServer = (DataReaderServer*)arg;
    char buffer[DATAREADERSERVER_BUFFER_SIZE];
    int n;


    /* If connection is established then start communicating */
    bzero(buffer, DATAREADERSERVER_BUFFER_SIZE);
    n = read(dataReaderServer->newsockfd, buffer, DATAREADERSERVER_BUFFER_SIZE);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    cout << "Data server start listening to the simulator" << endl;
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / dataReaderServer->timesPerSecond));
        bzero(buffer, DATAREADERSERVER_BUFFER_SIZE);
        n = read(dataReaderServer->newsockfd, buffer, DATAREADERSERVER_BUFFER_SIZE);
        if (n < 0)
            break;
        //cout << "Server read " << buffer << endl;
        string values = buffer;
        SymbolTable::getInstance()->updateValues(values);

    }
    return NULL;
}

void DataReaderServer::openServer(int _portId, int _timesPerSecond)
{
    struct sockaddr_in serv_addr, cli_addr;
    int portno, clilen;
    portId = _portId;
    timesPerSecond = _timesPerSecond;
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char*) &serv_addr, sizeof(serv_addr));
    portno = portId;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((u_int16_t )portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, (socklen_t*) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    cout << "Data Reader Server connected" << endl; // to know that we can continue
    pthread_create(&serverThread, nullptr, readFromServer, this);
}
