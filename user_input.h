//
// Created by ajays on 2/18/2022.
//

#ifndef IMPROVED_TEXTEDITOR_USER_INPUT_H
#define IMPROVED_TEXTEDITOR_USER_INPUT_H
#include "common.h"
void
options(strings &vec, const std::string &input, std::ofstream &ofile, std::stack<std::string> &commands, stack &undos,
        stack &redos, strings &copy, bool &is_first_command);
void prompt(strings& vec);
#endif //IMPROVED_TEXTEDITOR_USER_INPUT_H
