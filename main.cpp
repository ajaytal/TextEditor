#include "editor.h"
#include "validate_file.h"
#include "user_input.h"

int cursorX = 0;
int cursorY = 0;
bool program_over = false;
bool is_saved = false;
int lower_limit = 0;
int upper_limit = 10;
int saved_stack_size = 0;
int width = 40;

int main(int argc, char** argv) {
    std::vector<std::string> lines;
    int exit_code = validate_arguments(argc, argv, lines);
    display(lines);
    prompt(lines);
    return exit_code;
}
