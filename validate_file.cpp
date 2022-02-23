#include "validate_file.h"
int validate_arguments(int argc, char **argv, std::vector<std::string> &lines) {
    if (argc > 2) {
        std::cout << "Too many command-line arguments." << std::endl;
        return 1;
    } else if (argc < 2) {
        std::cout << "Too few command-line arguments." << std::endl;
        return 1;
    } else { // correct number of command line arguements
        std::ifstream file;
        std::string line;
        int num_lines = 0;
        file.open(argv[1]);
        if (!file.is_open()) {  // filename wasn't correct
            std::cout << "Failed to open file: " << argv[1] << std::endl;
            return 2;
        }
        while(std::getline(file, line)) { //  stores the contents of file in vector
            num_lines++;
            while(static_cast<int>(line.length()) < width) {
                line.push_back(' ');
            }
            lines.emplace_back(line);
            if(num_lines > 30) {  //  too many lines
                std::cout << "File " << argv[1] << " has too many lines." << std::endl;
                return 2;
            }
            if(static_cast<int>(line.length()) > width) { //  one line is too long
                std::cout << "File " << argv[1] << " has at least one too long line." << std::endl;
                return 2;
            }
        }
        return 0;
    }
}