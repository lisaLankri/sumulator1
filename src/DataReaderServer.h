#ifndef PROJECT_DATAREADERSERVER_H
#define PROJECT_DATAREADERSERVER_H

#include <pthread.h>

class DataReaderServer {
public:
    ~DataReaderServer();
    static DataReaderServer* getInstance();
    void openServer(int portId, int timesPerSecond);

private:
    static void* readFromServer(void*);
    DataReaderServer();
    int portId, sockfd, newsockfd;
    int timesPerSecond;
    pthread_t serverThread;
};


#endif //PROJECT_DATAREADERSERVER_H
