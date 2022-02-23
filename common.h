#ifndef IMPROVED_TEXTEDITOR_COMMON_H
#define IMPROVED_TEXTEDITOR_COMMON_H
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>

extern int cursorX;
extern int cursorY;
extern bool program_over;
extern bool is_saved;
extern int lower_limit;
extern int upper_limit;
extern int saved_stack_size;
extern int width;

using strings = std::vector<std::string>;
using stack = std::stack<std::vector<std::string>>;

#endif //IMPROVED_TEXTEDITOR_COMMON_H
