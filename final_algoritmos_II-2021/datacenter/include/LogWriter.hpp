#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>    
using namespace std;

class LogWriter
{
    public:
        LogWriter();
        ~LogWriter();
        bool write(string systemModule, string message, string filePath = "log.txt");

    private:
        string getCurrentDatetime(); 

};

#endif