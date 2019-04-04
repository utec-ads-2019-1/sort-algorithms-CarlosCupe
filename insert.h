#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            // TODO
            for (int i = 0; i < size - 1; ++i) {
                        compare(elements, i, i + 1);
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif