#ifndef PROJECT_DATAWRITERCLIENT_H
#define PROJECT_DATAWRITERCLIENT_H

#include <pthread.h>
#include <string>
#include <vector>

using namespace std;

class DataWriterClient {
public:
    ~DataWriterClient();
    static DataWriterClient* getInstance();
    void openClient(int portId, string hostName);
    void setCommand(string command);
    vector<string> getCommands();

private:
    static void* writeToClient(void*);
    DataWriterClient();
    int portId;
    int sockfd;
    string hostName;
    pthread_t clientThread;
    vector<string> commands;
};


#endif //PROJECT_DATAWRITERCLIENT_H
