#include "scanner.h"
#include "logger.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

Scanner::Scanner(const std::string& dir, const std::string& pattern)
    : directory(dir), regexPattern(pattern) {}

void Scanner::scan() {
    std::vector<std::thread> workers;

    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            workers.emplace_back(&Scanner::scanFile, this, entry.path().string());
        }
    }

    for (auto& worker : workers) {
        worker.join();
    }
}

void Scanner::scanFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        Logger::log("Failed to open file: " + filePath);
        return;
    }

    std::string line;
    std::regex pattern(regexPattern);
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (std::regex_search(line, pattern)) {
            std::string result = "Match found in: " + filePath + " at line " + std::to_string(lineNumber);
            Logger::log(result);
            std::cout << result << std::endl;
        }
    }
}
