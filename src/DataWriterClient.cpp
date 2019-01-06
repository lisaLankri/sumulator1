#include "DataWriterClient.h"
#include <arpa/inet.h>
#include <netdb.h> /* getprotobyname */
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;

DataWriterClient* DataWriterClient::getInstance()
{
    static DataWriterClient instance;
    return &instance;
}

pthread_mutex_t lock;
DataWriterClient::DataWriterClient()
{
    pthread_mutex_init(&lock, nullptr);
}

DataWriterClient::~DataWriterClient()
{
    pthread_mutex_destroy(&lock);
    close(sockfd);
}

void DataWriterClient::openClient(int _portId, string _hostName)
{
    portId = _portId;
    hostName = _hostName;
    pthread_create(&clientThread, nullptr, writeToClient, this);
}

void* DataWriterClient::writeToClient(void* arg) {
    DataWriterClient *dataWriterClient = (DataWriterClient *) arg;

    const char *server_hostname = dataWriterClient->hostName.c_str();
    in_addr_t in_addr;
    ssize_t user_input_len;
    struct hostent *hostent;
    /* This is the struct used by INet addresses. */
    struct sockaddr_in sockaddr_in;
    unsigned short server_port = dataWriterClient->portId;
    vector<string> currentCommands;

    dataWriterClient->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (dataWriterClient->sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Prepare sockaddr_in. */
    hostent = gethostbyname(server_hostname);
    if (hostent == NULL) {
        fprintf(stderr, "error: gethostbyname(\"%s\")\n", server_hostname);
        exit(EXIT_FAILURE);
    }
    in_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(hostent->h_addr_list)));
    if (in_addr == (in_addr_t)-1) {
        fprintf(stderr, "error: inet_addr(\"%s\")\n", *(hostent->h_addr_list));
        exit(EXIT_FAILURE);
    }
    sockaddr_in.sin_addr.s_addr = in_addr;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(server_port);

    /* Do the actual connection. */
    while (connect(dataWriterClient->sockfd, (struct sockaddr*)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
        sleep(2);
    }
    while (1) {
        currentCommands = dataWriterClient->getCommands();
        vector<string>::iterator it = currentCommands.begin();
        for (; it != currentCommands.end(); ++it)
        {
            user_input_len = (*it).size();
            if (write(dataWriterClient->sockfd, (*it).c_str(), user_input_len) == -1) {
                //perror("write");
                break;
            }
        }
    }
    return NULL;

}

void DataWriterClient::setCommand(string _command)
{
    pthread_mutex_lock(&lock);
    commands.push_back(_command);
    pthread_mutex_unlock(&lock);
}

vector<string> DataWriterClient::getCommands()
{
    vector<string> tempCommands;
    pthread_mutex_lock(&lock);
    tempCommands = commands;
    commands.clear();
    pthread_mutex_unlock(&lock);
    return tempCommands;
}
