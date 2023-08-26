#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

bool IsAllLinesCRLF(const std::string& filePath) {
    std::ifstream fileStream(filePath, std::ios::binary);
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return false;
    }

    char prevChar = '\0';
    char c;
    while (fileStream.get(c)) {
        if (c == '\n' && prevChar != '\r') {
            fileStream.close();
            return false;
        }
        prevChar = c;
    }

    fileStream.close();
    return true;
}

void CountLinesContainingCRLF(const std::string& path) {
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string filePath = entry.path().string();
            std::ifstream fileStream(filePath, std::ios::binary);
            if (fileStream.is_open()) {
                bool prevCharIsCR = false;
                bool prevCharIsLF = false;

                int lineNumber = 1;
                char c;
                while (fileStream.get(c)) {
                    if (c == '\r') {
                        prevCharIsCR = true;
                    }
                    else if (c == '\n') {
                        if (prevCharIsCR) {
                            std::cout << RED << "\"" << filePath << "\"" << RESET
                                << " - Line " << lineNumber << " ends with "
                                << RED << "CRLF" << RESET << std::endl;
                        }
                        else {
                            std::cout << RED << "\"" << filePath << "\"" << RESET
                                << " - Line " << lineNumber << " ends with "
                                << RED << "LF" << RESET << std::endl;
                        }
                        lineNumber++;
                        prevCharIsCR = false;
                    }
                    else {
                        if (prevCharIsCR && !prevCharIsLF) {
                            std::cout << RED << "\"" << filePath << "\"" << RESET
                                << " - Line " << lineNumber << " ends with "
                                << RED << "CR" << RESET << std::endl;
                        }
                        prevCharIsCR = false;
                        prevCharIsLF = false;
                    }
                }

                fileStream.close();

                if (IsAllLinesCRLF(filePath)) {
                    std::cout << GREEN << "\"" << filePath << "\"" << RESET
                        << " - All lines end with " << GREEN << "CRLF" << RESET << std::endl;
                }
            }
            else {
                std::cerr << "Failed to open file: " << filePath << std::endl;
            }
        }
        else if (entry.is_directory()) {
            CountLinesContainingCRLF(entry.path().string());
        }
    }
}

bool IsSourceFile(const std::string& filePath) {
    return filePath.find(".h") != std::string::npos || filePath.find(".cpp") != std::string::npos;
}

int main() {
    std::string folderPath;
    bool validFolder = false;

    while (!validFolder) {
        std::cout << "Enter folder path: ";
        std::getline(std::cin, folderPath);

        if (std::filesystem::is_directory(folderPath)) {
            validFolder = true;
        }
        else {
            std::cerr << RED << "Invalid folder path. Please enter a valid folder path." << RESET << std::endl;
        }
    }

    bool foundSourceFile = false;
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && IsSourceFile(entry.path().string())) {
            foundSourceFile = true;
            break;
        }
    }

    if (!foundSourceFile) {
        std::cerr << RED << "No .h or .cpp files found in the specified folder." << RESET << std::endl;
        return 1;
    }

    CountLinesContainingCRLF(folderPath);
    system("pause");
    return 0;
}
