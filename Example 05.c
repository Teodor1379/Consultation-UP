#include <stdio.h>

#include <assert.h>



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readNumber() {
    unsigned int numb = 0;
    int inputArgument = 0;

    do {
        printf("Enter the number: ");

        inputArgument = scanf("%u", &numb);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return numb;
}



void findCommonNumbers(unsigned int N1, unsigned int M1, unsigned int N2, unsigned int M2) {
    assert(N1 < 32);
    assert(M1 < 32);
    assert(N2 < 32);
    assert(M2 < 32);

    unsigned int number1 = 0;
    unsigned int number2 = 0;

    // Mark where we have numbers...

    for (unsigned int i = N1; i <= M1; ++i) { number1 = number1 | (1 << i); }
    for (unsigned int i = N2; i <= M2; ++i) { number2 = number2 | (1 << i); }

    unsigned int common = number1 & number2;

    printf("The common numbers are: ");

    for (unsigned int i = 0; i < sizeof(unsigned int) * 8; ++i) {
        unsigned int d = ((common >> i) & 1);

        if (d == 1) {
            printf("%u ", i);
        }
    }

    printf("\n");
}



unsigned int findNumber0(unsigned int n) {
    unsigned int result = 0;

    while (n > 0) {
        int d = n % 2;
            n = n / 2;

        if (d == 0) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int findNumber1(unsigned int n) {
    unsigned int result = 0;

    while (n > 0) {
        int d = n % 2;
            n = n / 2;

        if (d == 1) {
            result = result + 1;
        }
    }

    return result;
}


int main() {
    unsigned int number =   readNumber();
    unsigned int positn =   readNumber();

    if (positn >= 8 * sizeof(unsigned int)) {
        puts("Invalid bit position!");

        return 1;
    }

    printf("Bit Clear: %u\n",   number & ~(1 << positn));
    printf("Bit Set  : %u\n",   number |  (1 << positn));
    printf("Bit Flip : %u\n",   number ^  (1 << positn));
    printf("Bit Value: %u\n",   (number >> positn) & 1 );

    unsigned int n1 = readNumber(); unsigned int m1 = readNumber();
    unsigned int n2 = readNumber(); unsigned int m2 = readNumber();

    findCommonNumbers(n1, m1, n2, m2);

    return 0;
}
