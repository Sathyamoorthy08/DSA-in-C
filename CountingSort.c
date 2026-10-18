#include <stdio.h>
#include <stdlib.h>

void CountingSort(int n, int a[]) {
    int k = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > k) k = a[i];
    }
    int count[k + 1];
    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i - 1];
    }
    int b[n];
    for (int i = n - 1; i >= 0; i--) {
        b[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void print(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {5, 3, 7, 1, 6, 4, 9, 2, 8};
    int n = 9;
    printf("Sorted array:  ");
    CountingSort(n, a);
    print(n, a);
    return 0;
}
