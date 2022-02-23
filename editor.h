//
// Created by ajays on 2/18/2022.
//

#ifndef EDITOR_H
#define EDITOR_H
#include "common.h"

void display(const strings &vec);
void scroll_down(const strings &vec);
void insert(strings &vec, const std::string &input);
void del(strings &vec, int& num);

#endif //EDITOR_H
