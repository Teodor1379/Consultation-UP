#include <stdio.h>

#include <limits.h>


#define MAX 100



unsigned int min(unsigned int a, unsigned int b) {
    return (a > b) * b + (a <= b) * a; 
}

unsigned int max(unsigned int a, unsigned int b) {
    return (a > b) * a + (a <= b) * b;
}



unsigned int reverseNumber(unsigned int n) {
    unsigned int result = 0;

    while (n > 0) {
        int d = n % 10;
            n = n / 10;

        result = result * 10 + d;
    }

    return result;
}

unsigned int addDigitNumber(unsigned int n, unsigned int k) {
    if (n <  10) { return k * 10 + n; }
    
    if (n < 100) {
        unsigned int remainder1 = n % 10;
        unsigned int remainder2 = n / 10;

        return remainder2 * 100 + k * 10 + remainder1;
    }

    unsigned int remainder1 = n % 100; // 97
    unsigned int remainder2 = n / 100; // 8

    return remainder2 * 1000 + k * 100 + remainder1;
}

unsigned int delDigitNumber(unsigned int n) {
    if (n < 100) {
        return n;
    }

    unsigned int remainder1 = n % 100    ;
    unsigned int remainder2 = n / 1000   ;

    return remainder2 * 100 + remainder1;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readSize() {
    unsigned int size = 0;
    int inputArgument = 0;

    do {
        printf("Enter the size: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size >= MAX);

    return size;
}


void inputArray(unsigned int array[MAX], unsigned int size) {
    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        scanf("%u", &(array[i]));
    }
}

void printArray(unsigned int array[MAX], unsigned int size) {
    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    printf("\n");
}



unsigned int findMinArray(unsigned int array[MAX], unsigned int size) {
    // unsigned int result = INT_MAX;

    unsigned int result = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        result = min(result, array[i]);
    }

    return result;
}

unsigned int findMaxArray(unsigned int array[MAX], unsigned int size) {
    // unsigned int result = INT_MIN;

    unsigned int result = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        result = max(result, array[i]);
    }

    return result;
}


void applyAddDigitNumber(unsigned int array[MAX], unsigned int size, unsigned int d) {
    for (unsigned int i = 0; i < size; ++i) {
        array[i] = addDigitNumber(array[i], d);
    }

    // *size = 0;
}

void applyDelDigitNumber(unsigned int array[MAX], unsigned int size, unsigned int d) {
    for (unsigned int i = 0; i < size; ++i) {
        array[i] = delDigitNumber(array[i]);
    }

    // *size = 0;
}


int main() {
    unsigned int size1 = readSize();
    unsigned int size2 = readSize();


    unsigned int array1[MAX] = { 0 };
    unsigned int array2[MAX] = { 0 };

    // printf("%p", &size1);


    inputArray(array1, size1);
    inputArray(array2, size2);

    printArray(array1, size1);
    printArray(array2, size2);

    unsigned int minNumber = findMinArray(array1, size1);
    unsigned int maxNumber = findMaxArray(array2, size2);

    if (minNumber < 10) { applyAddDigitNumber(array2, size2, minNumber); }
    if (maxNumber < 10) { applyDelDigitNumber(array1, size1, maxNumber); }

    printArray(array1, size1);
    printArray(array2, size2);

    return 0;
}
