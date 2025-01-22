#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <filesystem>
#include <cstdlib>
#include <algorithm>


void sleep_ms(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void playAnimation(const std::vector<std::string>& textFiles, int loops) {

    size_t i = 0;
    bool first = true;

    int backspaceLines = std::count(textFiles[0].begin(), textFiles[0].end(), '\n') + 1;

    while (i < static_cast<size_t>(loops) || loops == -1) {
        for (const auto& frame : textFiles) {
            if (!first) {
                for (int j = 0; j < backspaceLines; ++j) {
                    std::cout << "\x1b[A";
                }
            }

            std::cout << frame << "\n";

            first = false;
            sleep_ms(50);
        }
        i++;
    }
}

void fileVerification(std::filesystem::path folderPath, std::string folderName, const std::vector<std::string>& textFiles){
    
    if (!std::filesystem::exists(folderPath)) {
        std::cerr << folderName << " folder wasn't found, closing...\n";
        sleep_ms(3000);
        std::exit(0);
    }
    if (textFiles.empty()) {
        std::cerr << folderName << " don't have any text art files, closing...\n";
        sleep_ms(3000);
        std::exit(0);
    }
}

void menu(int argc, char *argv[]){

    std::string folderName = (argc > 1) ? argv[1] : "fireworks";
    int loops = (argc > 2) ? std::stoi(argv[2]) : 10;

    std::vector<std::string> textFiles;
    std::filesystem::path folderPath = std::filesystem::absolute(argv[0]).parent_path() / folderName;

    int numFound = 0;
    while (true) {
        std::filesystem::path fileName = folderPath / (std::to_string(numFound) + ".txt");

        if (std::filesystem::exists(fileName)) {
            std::ifstream file(fileName);
            if (file) {
                std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                textFiles.push_back(content);
                numFound++;
            }
        } else {
            break;
        }
    }
    fileVerification(folderPath,folderName,textFiles);
    playAnimation(textFiles, loops);
}


int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--help") {
        std::cout << "\nPlay text art animations in the terminal\n\n";
        std::cout << "Usage: double-click on executable or ./fireworks-cpp [folder] [loops]\n";
        std::cout << "Warning: the folder must be in the same directory as the executable\n";
        std::cout << "[folder]\tFolder containing text art frames (default: fireworks)\n";
        std::cout << "[loops]\t\tNumber of times to loop the animation or use -1 to loop until the user terminates the program (default: 10)\n\n";
    
        return 0;
    }
    menu(argc, argv);
    return 0;
}