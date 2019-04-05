#include "tester.h"

void integersBubble(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}

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

        int aument = second - first;
        second = first;
        first = first - aument;

        while (first > 0) {
            if (array[first] > array[second])
                swap(array[first], array[second]);

            second = first;
            first = first - aument;
        }
    }
}

void integerQuick(void *elements, int first, int second) {
    int *array = (int*) elements;
    int size = second - first;
    int mid = (int)(size / 2);
    int pivot = array[mid];

    int *max = nullptr;
    int *min = nullptr;
    int last_right = size - 2;
    cout << array[mid] << endl;

    swap(array[mid], array[size - 1]);

    for (int i = 0; i < size - 1; i++) {
        if (array[i] > pivot) {
            max = &array[i];
            //cout << *max << " ";
            for (int j = last_right; j >= i; j--) {
                if (array[j] < pivot){
                    min = &array[j];
                    last_right = j - 1;
              //      cout << *min << endl;
                    
                    swap(array[j], array[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl ;
        if (i > last_right) {
            cout << "############ " << i <<endl;
            swap(array[size - 1], array[i]);
            break;
        }
    }

    cout << pivot << endl;

    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl ;
}

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integerBubble;
        case selectsort: return &integerSelect;
        case insertsort: return &integerInsert;
        case shellsort: return &integerShell;
        case quicksort: return &integerQuick;
        //case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid compare");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    fptr compare;
    int temp[size];

    Algorithm algorithm[] = { bubblesort, selectsort, insertsort, quicksort};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        compare = getCompare(algorithm[i]);
        sort->execute(compare);
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}