//
// Created by ajays on 2/18/2022.
//

#include "editor.h"

void scroll_down(const strings &vec) {
    auto copy = cursorY;
    cursorY++;
    if(cursorY >= static_cast<int>(vec.size()))
        cursorY = static_cast<int>(vec.size()) - 1;
    if ((cursorY == static_cast<int>(vec.size()) - 1) and upper_limit == static_cast<int>(vec.size()) + 9) {
        int check = 0;
        check++;
    } else if(cursorY >= upper_limit) {
        lower_limit++;
        upper_limit++;
    } else if ((copy == static_cast<int>(vec.size()) - 1) and upper_limit < static_cast<int>(vec.size()) + 10){
        lower_limit++;
        upper_limit++;
    }
}

void display(const strings &vec) {  //  displays the contents of the editor
    if(cursorX >= width){
        cursorX = 39;
        std::cout << std::setw(45) << '*' << std::endl;
    } else {
        if(cursorX < 0) {
            cursorX = 0;
            std::cout << std::setw(6) << '*' << std::endl;
        } else
            std::cout << std::setw(6 + cursorX) << '*' << std::endl;
    }
    if(lower_limit < 0)
        lower_limit = 0;
    if(upper_limit < 10)
        upper_limit = 10;
    std::cout << std::setw(45) << "1234567890123456789012345678901234567890" << std::endl;
    for(int i = lower_limit; i < upper_limit; ++i) {
        if(static_cast<int>(vec.size()) <= i) {
            for(int j = i; j < upper_limit; ++j) {
                std::cout << std::setw(4) << j + 1 << std::endl;
            }
            break;
        } else {
            if(cursorY < 0) {
                cursorY = 0;
                std::cout << "*" << std::setw(3) << 1 << '|' << vec.at(i) << std::endl;
            } else {
                if(i == cursorY)
                    std::cout << "*" << std::setw(3) << i + 1 << '|' << vec.at(i) << std::endl;
                else
                    std::cout << std::setw(4) << i + 1 << '|' << vec.at(i) << std::endl;
            }
        }
    }
    std::cout << std::setw(45) << "1234567890123456789012345678901234567890" << std::endl;
}

void insert(strings &vec, const std::string &input) {
    std::string word = input;
    word.erase(0, 1);
    size_t i = word.find_first_not_of(' ');
    word.erase(0, i);
    if(static_cast<int>(word.size()) > width or cursorX + static_cast<int>(word.size()) > width) {
        vec.at(cursorY).replace(cursorX, width - cursorX, word.substr(0, width - cursorX));
        word.erase(0, width - cursorX);
        cursorY++;
        if(static_cast<int>(word.size()) <= width) {
            if(cursorY >= static_cast<int>(vec.size()) && cursorY < 30) {
                while(static_cast<int>(word.size()) < width) {
                    word.push_back(' ');
                }
                vec.push_back(word);
            }
            else if (cursorY < static_cast<int>(vec.size()))
                vec.at(cursorY).replace(0, word.length(), word);
            cursorX = static_cast<int>(word.size()) + 1;
        } else {
            while(!word.empty()) {
                if(cursorY >= static_cast<int>(vec.size()) && cursorY < 30) {
                    while(static_cast<int>(word.size()) < width) {
                        word.push_back(' ');
                    }
                    vec.push_back(word.substr(0, width));
                }
                else if (cursorY < static_cast<int>(vec.size())) {
                    if(static_cast<int>(word.size()) >= width)
                        vec.at(cursorY).replace(0, width, word.substr(0, width));
                    else
                        vec.at(cursorY).replace(0, word.length(), word);
                }
                word.erase(0, width);
                if(word.empty())
                    ++cursorY;
            }
        }
    } else {
        vec.at(cursorY).replace(cursorX, word.size(), word);
        cursorX += (static_cast<int>(word.size()) + 1);
        if(cursorX >= width) {
            cursorY++;
            cursorX = 0;
        }
    }
}

void del(strings &vec, int &num) {
    if(num == 0) {
        vec.at(cursorY).at(cursorX) = ' ';
        return;
    }
    if(cursorX + num >= 40)
        num = width - cursorX;
    for(int i = cursorX; i < cursorX + num; ++i)
        vec.at(cursorY).at(i) = ' ';
}
