#include <iostream>
#include <vector>
#include <string>
#include "scanner.h"
#include "logger.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <directory_path> <pattern>" << std::endl;
        return 1;
    }

    std::string directory = argv[1];
    std::string pattern = argv[2];

    Logger::log("Starting license scan in: " + directory);

    Scanner scanner(directory, pattern);
    scanner.scan();

    Logger::log("Scanning completed.");
    return 0;
}
