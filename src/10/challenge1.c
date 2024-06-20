#include <stdbool.h>
#include <stdio.h>

bool divisible(int dividend,
               int divisor) { // dividedがdivisorで割り切れたらtrue
    if(dividend % divisor == 0) {
        return true;
    }
    return false;
}

bool isPrime(int number,
             int *primeNumbers) { // number以下の素数で割り切れなければtrue
    int i;
    for(i = 0; primeNumbers[i] != 0; i++) {
        if(divisible(number, primeNumbers[i])) {
            return false;
        }
    }
    return true;
}

void displayPrimeNumbers(int range,
                         int *primeNumbers) { // rangeまでの素数の表示
    for(int i = 0; i < range; i++) {
        if(primeNumbers[i] != 0) {
            if(i != 0)
                printf(" ");
            printf("%d", primeNumbers[i]);
        } else
            break;
        printf(",");
    }
    printf("\n");
}

void searchPrimeNumbers(int range,
                        int *primeNumbers) { // rangeまでの素数を配列に入れる
    int cnt = 0;
    for(int i = 2; i < range; i++) {
        if(isPrime(i, primeNumbers)) {
            primeNumbers[cnt] = i;
            cnt++;
        }
    }
    displayPrimeNumbers(range, primeNumbers);
}

int main(int argc, const char *argv[]) {
    int primeNumbers[100] = {};
    searchPrimeNumbers(100, primeNumbers);
    return 0;
}