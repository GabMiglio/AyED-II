#include <LogWriter.hpp>

LogWriter::LogWriter(){}

LogWriter::~LogWriter(){}

bool LogWriter::write(string systemModule, string message, string filePath)
{
    bool logState = false;

    cout << " Writing log....." << endl;
    cout << "   System Module: " << systemModule << endl;
    cout << "   Log message: " << message << endl;
    cout << "   Log file: " << filePath << endl;

    ofstream logFile;
    logFile.open(filePath, ofstream::app);
    logFile << getCurrentDatetime() + " - " +  systemModule + " - " +  message << endl;
    logFile.close();
    
    if(logFile.good()){logState = true;};
    return logState;
}


string LogWriter::getCurrentDatetime() 
{
    // auto start = chrono::system_clock::now();
    // Some computation here
    // auto end = chrono::system_clock::now();
    
 
    // chrono::duration<double> elapsed_seconds = end-start;
    // time_t end_time = chrono::system_clock::to_time_t(end);
 
    // return ctime(&end_time);

    //For example:
    // cout << "finished computation at " << ctime(&end_time)
    //           << "elapsed time: " << elapsed_seconds.count() << "s"
    //           << endl;   

    //TO DO using namespace chrono
    auto cppCDT = chrono::system_clock::now();
    time_t cCDT = chrono::system_clock::to_time_t(cppCDT);
    return ctime(&cCDT);
}