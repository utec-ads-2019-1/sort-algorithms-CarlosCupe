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
            int aumento = size / 2;
            while (aumento > 0) {
                for (int i = 0; i < size - aumento; i++) {
                    compare(elements, i, i + aumento);
                }
                aumento = (int)(aumento / 2);
            }
        }

        inline string name() { return "ShellSort"; }
};

#endif