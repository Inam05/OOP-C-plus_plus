/*
Implement the Singleton design pattern for a Logger class that logs messages to a file. Ensure thread safety and proper resource management.
*/

#include <iostream>
#include <fstream>
#include <mutex>
using namespace std;

class Logger
{
private:
    static Logger *instance;
    static mutex mtx;
    ofstream logFile;

    Logger()
    {
        logFile.open("log.txt", ios::app);
    }

public:
    static Logger *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new Logger();
            }
        }
        return instance;
    }

    void logMessage(const string &message)
    {
        logFile << message << endl;
    }

    ~Logger()
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
    }

    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
};

Logger *Logger::instance = nullptr;
mutex Logger::mtx;

int main()
{
    Logger *logger = Logger::getInstance();
    logger->logMessage("Singleton Logger Initialized");
    logger->logMessage("Logging another message");

    return 0;
}
