#include <stdio.h>



#define MAX 100



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



void convertBase2(unsigned int n) {
    if (n == 0) {
        printf("The representation is: 0\n");

        return;
    }

    int record[MAX] = { 0 };

    unsigned int size = 0;

    while (n > 0) {
        int d = n % 2;
            n = n / 2;

        record[size] = d;
        size = size + 1 ;
    }

    for (unsigned int i = 0; i < size / 2; ++i) {
        int temporary = 0;

        temporary               =   record[i]           ;
        record[i]               =   record[size - i - 1];
        record[size - i - 1]    =   temporary           ;
    }

    printf("The representation is: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d", record[i]);
    }

    printf("\n");
}

void convertBase8(unsigned int n) {
    if (n == 0) {
        printf("The representation is: 0\n");

        return;
    }

    int record[MAX] = { 0 };

    unsigned int size = 0;

    while (n > 0) {
        int d = n % 8;
            n = n / 8;

        record[size] = d;
        size = size + 1 ;
    }

    for (unsigned int i = 0; i < size / 2; ++i) {
        int temporary = 0;

        temporary               =   record[i]           ;
        record[i]               =   record[size - i - 1];
        record[size - i - 1]    =   temporary           ;
    }

    printf("The representation is: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d", record[i]);
    }

    printf("\n");
}

void convertBase16(unsigned int n) {
    if (n == 0) {
        printf("The representation is: 0\n");

        return;
    }

    int record[MAX] = { 0 };

    unsigned int size = 0;

    while (n > 0) {
        int d = n % 16;
            n = n / 16;

        record[size] = d;
        size = size +  1;
    }

    for (unsigned int i = 0; i < size / 2; ++i) {
        int temporary = 0;

        temporary               =   record[i]           ;
        record[i]               =   record[size - i - 1];
        record[size - i - 1]    =   temporary           ;
    }

    printf("The representation is: ");

    for (unsigned int i = 0; i < size; ++i) {
        if (record[i] < 10) {
            printf("%d", record[i]);
        } else {
            printf("%c", 'A' + (record[i] - 10));
        }
    }

    printf("\n");
}


int main() {
    unsigned int n = readNumber();

    convertBase2    (n);
    convertBase8    (n);
    convertBase16   (n);

    // Can you do it when the base is P...

    return 0;
}
