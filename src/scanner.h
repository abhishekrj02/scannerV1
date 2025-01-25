#ifndef SCANNER_H
#define SCANNER_H

#include <string>

class Scanner {
public:
    Scanner(const std::string& dir, const std::string& pattern);
    void scan();

private:
    std::string directory;
    std::string regexPattern;
    void scanFile(const std::string& filePath);
};

#endif
