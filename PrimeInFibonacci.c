#include <stdio.h>

int prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int fibbo(int n) {
    int a = -1, b = 1, fib = 0;
    for (int i = 0; i < n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    int n;
    printf("Enter the number N: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0, j = 1; i < n; j++) {
        int f = fibbo(j);
        if (prime(f)) {
            printf("%d\n", f);
            i++;
        }
    }
    return 0;
}