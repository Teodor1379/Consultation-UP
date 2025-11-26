#include <stdio.h>



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}

unsigned int readNumber() {
    unsigned int numb = 0;
    int inputArgument = 0;

    do {
        inputArgument = scanf("%u", &numb);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return numb;
}



int isLeapYear(int year) {
    assert(year >=  1);
    
    if (year % 400 == 0) {
        return 1;
    }

    return year % 4 == 0 && year % 100 != 0;
}



int getDaysMonth(int month, int year) {
    assert(month >=  1);
    assert(month <= 12);
    assert(year  >=  1);

    switch (month) {
        case  1:
        case  3:
        case  5:
        case  7:
        case  8:
        case 10:
        case 12:
            return 31;

        case 2:
            return 28 + isLeapYear(year);

        case  4:
        case  6:
        case  9:
        case 11:
            return 30; 
    }

    return 0;
}



int main() {
    unsigned int d = readNumber();
    unsigned int m = readNumber();
    unsigned int y = readNumber();

    int result = d;

    for (unsigned int i = 1; i < m; ++i) {
        result = result + getDaysMonth(i, y);
    }

    printf("The days in the year are till now: %d\n", result);

    return 0;
}
