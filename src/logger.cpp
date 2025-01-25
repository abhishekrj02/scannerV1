#include "logger.h"
#include <fstream>
#include <iostream>
#include <ctime>

void Logger::log(const std::string& message) {
    std::ofstream logFile("scan_results.log", std::ios::app);
    if (!logFile) {
        std::cerr << "Error opening log file!" << std::endl;
        return;
    }

    auto t = std::time(nullptr);
    logFile << std::asctime(std::localtime(&t)) << ": " << message << std::endl;
    logFile.close();
}
