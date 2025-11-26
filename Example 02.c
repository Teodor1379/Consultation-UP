#include <math.h>

#include <stdio.h>



#define EPSILON 1e-9



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}

unsigned int getNumber() {
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


unsigned int findCntDigits(int n) {
    unsigned int res = 0;

    while (n > 0) {
        int d = n % 10;
            n = n / 10;

        res = res + 1;
    }

    return res;
}

unsigned int findSumDigits(int n) {
    unsigned int sum = 0;

    while (n > 0) {
        int d = n % 10;
            n = n / 10;

        sum = sum + d;
    }

    return sum;
}

unsigned int findPrdDigits(int n) {
    unsigned int prd = 1;

    while (n > 0) {
        int d = n % 10;
            n = n / 10;

        prd = prd * d;
    }

    return prd;
}


unsigned int reverseNumber(unsigned int n) {
    unsigned int r = 0;

    while (n > 0) {
        int d = n % 10;
            n = n / 10;

        r = r * 10 + d;
    }

    return r;
}



int isPalindrome(unsigned int n) {
    return n == reverseNumber(n);
}


int isPrime(unsigned int n) {
    if (n < 2) {
        return 0;
    }

    for (unsigned int i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}



int isKPrefix(unsigned int n, unsigned int k) {
    unsigned int count1 = countDigits(n);
    unsigned int count2 = countDigits(k);

    while (count1 > count2) {
        n = n / 10;
    }

    return n == k;
}

int isKSuffix(unsigned int n, unsigned int k) {
    while (n > 0 && k > 0) {
        int d1 = n % 10;    n = n / 10;
        int d2 = k % 10;    k = k / 10;

        if (d1 != d2) {
            return 0;
        }
    }

    return k == 0;
}

int isKInfix(unsigned int n, unsigned int k) {
    while (n > 0) {
        int c = n;
        
        if (isKSuffix(c, k)) {
            return 1;
        }

        n = n / 10;
    }

    return 0;
}



unsigned int findGCD(unsigned int a, unsigned int b) {
    if (a == 0) { return b; }
    if (b == 0) { return a; }

    if (a > b) { return findGCD(a % b, b); }
    if (b > a) { return findGCD(a, b % a); }
}

unsigned int findLCM(unsigned int a, unsigned int b) {
    return a * b / findGCD(a, b);
}



unsigned int buildNumberAscending(unsigned int n) {
    int digits[10] = { 0 };
    
    while (n > 0) {
        int d = n % 10;
            n = n / 10;

        digits[d] += 1;
    }

    unsigned int result = 0;

    for (int i = 0; i < 10; ++i) {
        for (unsigned int j = 0; j < digits[i]; ++j) {
            result = result * 10 + i;
        }
    }

    return result;
}

unsigned int buildNumberDescending(unsigned int n) {
    int digits[10] = { 0 };

    while (n > 0) {
        int d = n % 10;
            n = n / 10;

        digits[d] += 1;
    }

    unsigned int result = 0;

    for (int i = 9; i >= 0; --i) {
        for (unsigned int j = 0; j < digits[i]; ++j) {
            result = result * 10 + i;
        }
    }

    return result;
}



int areEqual(double number1, double number2) {
    if (isfinite(number1) == 0) { return 0; }
    if (isfinite(number2) == 0) { return 0; }

    return fabs(number1 - number2) < EPSILON;
}


int main() {
    // Test Your Functions Here...
    // For undefined cases with 0,
    // you can think what to add.

    return 0;
}
