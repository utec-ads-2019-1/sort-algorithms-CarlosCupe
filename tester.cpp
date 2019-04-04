#include "tester.h"

Sort* Tester::getSort(Algorithm sort, void *array, size_t size) {
    switch (sort) {
        case bubblesort: return new BubbleSort(array, size);
        case selectsort: return new SelectSort(array, size);
        case insertsort: return new InsertSort(array, size);
        case shellsort: return new ShellSort(array, size);
        case quicksort: return new QuickSort(array, size);
        case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid sort");
    }
}

void integerBubble(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}

void integerInsert(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
            for (int j = first; j >= 0; j--) {
                if (array[j] < array[j + 1])
                    break;
                swap(array[j], array[j + 1]);
            }
        }
}

void integerSelect(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}

void integerShell(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integerBubble;
        case selectsort: return &integerSelect;
        case insertsort: return &integerInsert;
        case shellsort: return &integerShell;
        //case quicksort: return new QuickSort(array, size);
        //case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid compare");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    fptr compare;
    int temp[size];

    Algorithm algorithm[] = { bubblesort, selectsort, insertsort, shellsort };
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        compare = getCompare(algorithm[i]);
        sort->execute(compare);
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}