#include <stdio.h>

int mergeArray(int *a, int na, int *b, int nb, int *c) {
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i < na) && (j < nb)) {
	if (a[i] <= b[j]) {
           c[k] = a[i];
	   i++;
        } else {
	      c[k] = b[j];
	      j++;
        }
        k++;
    }
    while (i < na) {
    	c[k] = a[i];
	k++;
        i++;
    }
    while (j < nb) {
    	c[k] = b[j];
	k++;
	j++;
    }
    return k;
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++)
    {
	printf("%d ",a[i]);
    }
}

int main() {
    int a[] = {1, 3, 6, 9};
    int na = sizeof(a) / sizeof(a[0]);
    int b[] = {2, 4, 5, 8};
    int nb = sizeof(b) / sizeof(b[0]);
    int c[100];
    int n = mergeArray(a, na, b, na, c);
    printArray(c, n);
}
