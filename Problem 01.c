#include <stdio.h>

#include <assert.h>



int factorial(int n) {
    assert(n >= 0);

    int result = 1;

    for (int i = 2; i <= n; ++i) {
        result = result * i;
    }

    return result;
}



int binomial(int n, int k) {
    assert(n >= 0);
    assert(k >= 0);
    assert(n >= k);
    
    int numerator   =   factorial(n)                    ;
    int denominator =   factorial(k) * factorial(n - k) ;

    return numerator / denominator;
}



void printCharacterPow(char c, int n) {
    if (n == 0) {
        return;
    }

    if (n == 1) {
        printf("%c", c);
    } else {
        printf("%c^%d", c, n);
    }
}


void printExpression(char c1, char c2, int n) {
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            printCharacterPow(c1, n);

            printf(" + ");
        } else if (i == n) {
            printCharacterPow(c2, n);
        } else {
            printf("%d * ", binomial(n, i));

            printCharacterPow(c1, n - i );
            
            printf(" * ");

            printCharacterPow(c2, i     );

            printf(" + ");
        }
    }

    printf("\n");
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}


unsigned int readPower() {
    unsigned int numb = 0;
    int inputArgument = 0;

    do {
        printf("Enter the power: ");

        inputArgument = scanf("%u", &numb);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return numb;
}



int main() {
    char c1 = 0;
    char c2 = 0;

    printf("Enter the letter: "); scanf("%c", &c1); clearStandardInput();
    printf("Enter the letter: "); scanf("%c", &c2); clearStandardInput();

    unsigned int power = readPower();

    printExpression(c1, c2, power);
    
    return 0;
}
