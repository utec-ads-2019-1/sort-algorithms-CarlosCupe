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
    for (int i = first; i < second; i++) 
    { 
        int j;             
        for (j = i; j >= first && array[j - first] > array[i]; j -= first)
        {
            array[j] = array[j - first]; 
        }
        array[j] = array[i];; 
    } 
}

int partition (int *arr, int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
void integerQuick(void *elements, int first, int second) 
{ 
    int *array = (int*) elements;
    if (first < second) 
    { 
        int part = partition(array, first, second); 
  
        integerQuick(array, first, part - 1); 
        integerQuick(array, part + 1, second); 
    } 
} 

void merge(int *array, int start, int mid, int end) {
	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(array[i] <= array[j]) {
			temp[k] = array[i];
			k++;
            i++;
		}
		else {
			temp[k] = array[j];
			k++; j++;
		}
	}

	while(i <= mid) {
		temp[k] = array[i];
		k++; 
        i++;
	}

	while(j <= end) {
		temp[k] = array[j];
		k++;
        j++;
	}

	for(i = start; i <= end; i++) {
        array[i] = temp[i - start];
    }
}

void integerMerge(void *elements, int first, int second) 
{ 
    int *array = (int*) elements;
    
    if(first < second) {
        int mid = (first + second) / 2;
        integerMerge(array, first, mid);
        integerMerge(array, mid+1, second);
        merge(array, first, mid, second);
	}

} 

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integerBubble;
        case selectsort: return &integerSelect;
        case insertsort: return &integerInsert;
        case shellsort: return &integerShell;
        case quicksort: return &integerQuick;
        case mergesort: return &integerMerge;
        default: throw invalid_argument("Not a valid compare");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    fptr compare;
    int temp[size];

    Algorithm algorithm[] = { bubblesort, selectsort, insertsort, shellsort, quicksort, mergesort};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        compare = getCompare(algorithm[i]);
        sort->execute(compare);
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}