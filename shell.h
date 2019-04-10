#ifndef SHELL_H
#define SHELL_H

#include "sort.h"
#include <iostream>

using namespace std;

class ShellSort : public Sort {       
    public:
        ShellSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            // TODO
            for (int pivot = size/2; pivot > 0; pivot /= 2) 
            { 
                compare(elements, pivot, size);
            } 
        }

        inline string name() { return "ShellSort"; }
};

#endif