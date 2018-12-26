#include <stdio.h>

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
}

void moveElements(int *a, int n) {
    int val;
    for (int i = 1; i < n; i++) {
	val = a[i];
   	if (a[i] < 0) {
	    continue;
        }
        int j = i - 1;
        while(j >= 0 && a[j] < 0) {
   	    a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = val;
    }
}

int main() {
    int a[] = {4, -9, 5, -99, 44, -1, 3, -55};
    int n = sizeof(a) / sizeof(a[0]);
    moveElements(a, n);
    printArray(a, n);
}
