#include <stdio.h>

void calculateSpan(int *a, int n, int *s) {
    s[0] = 1;
    for (int i = 1; i < n; i++) {
        s[i] = 1;
	for (int j = i - 1; ; j--) {
	    if(j < 0) {
                break;
	    } else {
		if (a[i] > a[j]) {
		    s[i]++;
                }
            }
        }
    }
}

int main() {
    int a[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(a) / sizeof(a[0]);
    int s[6] = {0};
    calculateSpan(a, n , s);
    for (int i = 0; i < n; i++) {
	printf("%d ",s[i]);
    }
}
