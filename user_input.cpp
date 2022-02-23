#include "user_input.h"
#include "editor.h"
#include <algorithm>

void prompt(strings& vec) { //  prompts user to enter command, quits program when user enters 'q'
    std::string input;
    std::string parse;
    std::stack<std::string> commands;
    bool is_first_command = true;
    stack undos;
    stack redos;
    strings copy = vec;
    std::ofstream new_file;
    do {
        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        std::cout << std::endl;
        if(!input.empty())
            commands.push(input);
        options(vec, input, new_file, commands, undos, redos, copy, is_first_command);
    } while(!program_over);
    new_file.close();
    std::cout << "Goodbye!" << std::endl;
}

void options(strings &vec, const std::string &input, std::ofstream &ofile, std::stack<std::string> &commands, stack &undos,
        stack &redos, strings &copy, bool &is_first_command) {
    if(input.empty()) {
        if(is_first_command) {
            std::cout << "No previous command." << std::endl;
            is_first_command = false;
        } else {
            auto top = commands.top();
            commands.push(top);
            options(vec, top, ofile, commands, undos, redos, copy, is_first_command);
        }
    }
    std::string parse;
    std::stringstream line(input);
    int num = 1;
    line >> parse;
    std::transform(parse.begin(), parse.end(), parse.begin(), ::tolower);  // converts string to lowercase if necessary
    if (parse == "q") {  // quit
        if(is_saved && copy == vec) {
            if(saved_stack_size != static_cast<int>(undos.size()))
                is_saved = false;
        } else if (!is_saved && copy == vec && undos.empty()){
            program_over = true;
            return;
        }
        if(!is_saved or copy != vec) {
            std::cout << "You have unsaved changes.\nAre you sure you want to quit (y or n)?" << std::endl;
            std::string answer;
            std::getline(std::cin, answer);
            if(answer == "y")
                program_over = true;
            else if(answer == "n")
                display(vec);
        } else
            program_over = true;
    } else if(parse == "save") {
        is_first_command = false;
        is_saved = true;
        saved_stack_size = static_cast<int>(undos.size());
        copy = vec;
        std::string filename;
        std::ofstream new_file;
        line >> filename;
        new_file.open(filename);
        for(const auto& l : vec)
            new_file << l << std::endl;
        display(vec);
    } else {
        is_first_command = false;
        if (parse == "a"){  // move left
            if(line)
                line >> num;
            cursorX -= num;
            display(vec);
        } else if (parse == "d"){  // move right
            if(line)
                line >> num;
            cursorX += num;
            display(vec);
        } else if (parse == "w"){  //  scroll up
            if(line)
                line >> num;
            auto temp = cursorY - num;
            cursorY -= num;
            if(temp < lower_limit) {
                lower_limit -= num;
                upper_limit = lower_limit + 10;
            }
            display(vec);
        } else if (parse == "s"){  //  scroll down
            if(line)
                line >> num;
            if(num == 1)
                scroll_down(vec);
            else {
                for(int i = 0; i < num; ++i)
                    scroll_down(vec);
            }
            display(vec);
        } else if (parse == "i"){  //  insert text
            undos.push(vec);
            insert(vec, input);
            while(!redos.empty()) {redos.pop();}
            display(vec);
        } else if (parse == "u") {  // undos insertions and deletions ONLY
            if(undos.empty()) {
                std::cout << "Cannot undo." << std::endl;
                std::cout << std::endl;
            } else {
                redos.push(vec);
                vec = undos.top();
                undos.pop();
            }
            display(vec);
        } else if (parse == "r") { //  redos an undo action
            if(redos.empty()) {
                std::cout << "Cannot redo." << std::endl;
                std::cout <<std::endl;
            } else {
                undos.push(vec);
                vec = redos.top();
                redos.pop();
            }
            display(vec);
        } else if (parse == "del") {  // deletes the whole line
            undos.push(vec);
            int amount = 0;
            if(line >> amount)
                del(vec, amount);
            else {
                for(int i = 0; i < width; ++i)
                    vec.at(cursorY).at(i) = ' ';
            }
            display(vec);
        }
        }
}
