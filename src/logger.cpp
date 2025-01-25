#include "logger.h"
#include <fstream>
#include <iostream>
#include <ctime>

void Logger::clearLog() {
    std::ofstream logFile("scan_results.log", std::ios::trunc);
    if (!logFile) {
        std::cerr << "Error clearing log file!" << std::endl;
    }
    logFile.close();
}

void Logger::log(const std::string& message) {
    static bool isCleared = false;  // Ensures log is cleared only once

    if (!isCleared) {
        clearLog();
        isCleared = true;
    }
    
    std::ofstream logFile("scan_results.log", std::ios::app);
    if (!logFile) {
        std::cerr << "Error opening log file!" << std::endl;

        return;
    }
    
    auto t = std::time(nullptr);
    std::string timeStr = std::asctime(std::localtime(&t));
    timeStr.pop_back(); 
    logFile << timeStr << ": " << message << std::endl;
    logFile.close();
}
