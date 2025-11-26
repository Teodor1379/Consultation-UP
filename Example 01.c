#include <stdio.h>

#include <assert.h>



#define MAX 100



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}

unsigned int readSize() {
    unsigned int size = 0;
    int inputArgument = 0;

    do {
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return size;
}



void inputArray(int array[MAX], unsigned int size) {
    assert(size != 0);

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }
}

void printArray(const int array[MAX], unsigned int size) {
    assert(size != 0);

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    printf("\n");
}



int findElementArray1(const int array[MAX], unsigned int size, int k) {
    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] == k) {
            return 1;
        }
    }

    return 0;
}

int findElementArray2(const int array[MAX], unsigned int size, int k) {
    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] == k) {
            return 0;
        } 
    }

    return 1;
}



int min(int a, int b) { return (a < b) * a + (a >= b) * b; }
int max(int a, int b) { return (a > b) * a + (a <= b) * b; }



int findMinElement(const int array[MAX], unsigned int size) {
    int result = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        result = min(result, array[i]);
    }

    return result;
}

int findMaxElement(const int array[MAX], unsigned int size) {
    int result = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        result = max(result, array[i]);
    }

    return result;
}



void reverseArray(int array[MAX], unsigned int size) {
    for (unsigned int i = 0; i < size / 2; ++i) {
        int temporary = 0;

        temporary           =   array[i]            ;   
        array[i]            =   array[size - i - 1] ;
        array[size - i - 1] =   temporary           ;
    }
}



void sortArrayAscending(int array[MAX], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                int temporary = 0;

                temporary   =   array[i]    ;
                array[i]    =   array[j]    ;
                array[j]    =   temporary   ;
            }
        }
    }
}

void sortArrayDescending(int array[MAX], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (array[i] < array[j]) {
                int temporary = 0;

                temporary   =   array[i]    ;
                array[i]    =   array[j]    ;
                array[j]    =   temporary   ;
            }
        }
    }
}



unsigned int removeDuplicates(int array[MAX], int result[MAX], unsigned int size) {
    unsigned int index = 0;

    for (unsigned int i = 0; i < size; ++i) {
        int foundElement = 0;

        for (unsigned int j = 0; j < index; ++j) {
            if (array[i] == result[j]) {
                foundElement = 1;

                break;
            }
        }

        if (foundElement == 0) {
            result[index] = array[i];

            index = index + 1;
        }
    }

    return index;
}



unsigned int findConjunctionArraysNaive(int array1[MAX], int array2[MAX], int array3[MAX], unsigned int size1, unsigned int size2) {
    unsigned int index = 0;

    for (unsigned int i = 0; i < size1; ++i) {
        int found = 0;

        for (unsigned int j = 0; j < index; ++j) {
            if (array1[i] == array3[j]) {
                found = 1; break;
            }
        }

        if (found == 0) {
            array3[index] = array1[i];

            index = index + 1;
        }
    }

    for (unsigned int i = 0; i < size2; ++i) {
        int found = 0;

        for (unsigned int j = 0; j < index; ++j) {
            if (array2[i] == array3[j]) {
                found = 1; break;
            }
        }

        if (found == 0) {
            array3[index] = array2[i];

            index = index + 1;
        }
    }

    return index;
}

unsigned int findDisjunctionArraysNaive(int array1[MAX], int array2[MAX], int array3[MAX], unsigned int size1, unsigned int size2) {
    unsigned int index = 0;

    for (unsigned int i = 0; i < size1; ++i) {
        int found = 0;

        for (unsigned int j = 0; j < size2; ++j) {
            if (array1[i] == array2[j]) {
                found = 1; break;
            }
        }

        if (found == 0) {
            int added = 0;

            for (unsigned int k = 0; k < index; ++k) {
                if (array3[k] == array1[i]) {
                    added = 1; break;
                }
            }

            if (added == 0) {
                array3[index] = array1[i];

                index = index + 1;
            }
        }
    }

    for (unsigned int i = 0; i < size2; ++i) {
        int found = 0;

        for (unsigned int j = 0; j < size1; ++j) {
            if (array2[i] == array1[j]) {
                found = 1; break;
            }
        }

        if (found == 0) {
            int added = 0;

            for (unsigned int k = 0; k < index; ++k) {
                if (array3[k] == array2[i]) {
                    added = 1; break;
                }
            }

            if (added == 0) {
                array3[index] = array2[i];

                index = index + 1;
            }
        }
    }

    return index;
}


unsigned int findDisjunctionArrays(int array1[MAX], int array2[MAX], int array3[MAX], unsigned int size1, unsigned int size2) {
    sortArrayAscending(array1, size1);
    sortArrayAscending(array2, size2);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] < array2[index2]) {
            array3[index3] = array1[index1];

            index1 = index1 + 1;
            index3 = index3 + 1;
        } else if (array1[index1] > array2[index2]) {
            array3[index3] = array2[index2];

            index2 = index2 + 1;
            index3 = index3 + 1;
        } else {
            array3[index3] = array1[index1];

            index1 = index1 + 1;
            index2 = index2 + 1;
            index3 = index3 + 1;
        }
    }

    while (index1 < size1) {
        array3[index3] = array1[index1];

        index1 = index1 + 1;
        index3 = index3 + 1;
    }

    while (index2 < size2) {
        array3[index3] = array2[index2];

        index2 = index2 + 1;
        index3 = index3 + 1;
    }

    // Remove Duplicates From the Result... Here or in Main...

    return index3;
}

unsigned int findConjunctionArrays(int array1[MAX], int array2[MAX], int array3[2 * MAX], unsigned int size1, unsigned int size2) {
    sortArrayAscending(array1, size1);
    sortArrayAscending(array2, size2);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] < array2[index2]) {
            index1 = index1 + 1;
        } else if (array1[index1] > array2[index2]) {
            index2 = index2 + 1;
        } else {
            array3[index3] = array2[index2];

            index1 = index1 + 1;
            index2 = index2 + 1;
            index3 = index3 + 1;
        }
    }

    // Remove Duplicates From the Result... Here or in Main...

    return index3;
}

void findDifferencesArrays(int array1[MAX], int array2[MAX], int array3[MAX], int array4[MAX], unsigned int size1, unsigned int size2, unsigned int* newSize1, unsigned int* newSize2) {
    sortArrayAscending(array1, size1);
    sortArrayAscending(array2, size2);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;
    unsigned int index4 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] < array2[index2]) {
            array3[index3] = array1[index1];

            index1 = index1 + 1;
            index3 = index3 + 1;
        } else if (array1[index1] > array2[index2]) {
            array4[index4] = array2[index2];

            index2 = index2 + 1;
            index4 = index4 + 1;
        } else {
            index1 = index1 + 1;
            index2 = index2 + 1;
        }
    }

    while (index1 < size1) {
        array3[index3] = array1[index1];

        index1 = index1 + 1;
        index3 = index3 + 1;
    }

    while (index2 < size2) {
        array4[index4] = array2[index2];

        index2 = index2 + 1;
        index4 = index4 + 1;
    }

    // Remove Duplicates From Array 3... Here or in Main...
    // Remove Duplicates From Array 4... Here or in Main...

    *newSize1 = index3;
    *newSize2 = index4;
}



int linearSearch(const int array[MAX], unsigned int size, int element) {
    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return 1;
        }
    }

    return 0;
}

int binarySearch(const int array[MAX], unsigned int size, int element) {
    assert(size != 0);

    unsigned int l = 0          ;
    unsigned int r = size - 1   ;

    while (l <= r && l < size && r < size) {
        unsigned int m = l + (r - l) / 2;

        if (array[m] == element) {
            return 1;
        }

        if (array[m] < element) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return 0;
}



int main() {
    int array1[MAX] = { 0 };
    int array2[MAX] = { 0 };

    unsigned int size1 = readSize();    inputArray(array1, size1);
    unsigned int size2 = readSize();    inputArray(array2, size2);

    printArray(array1, size1);
    printArray(array2, size2);

    // Test Your Functions Here...

    return 0;
}
