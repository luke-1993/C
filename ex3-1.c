#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low, mid, high;
    low = 0;
    high = n - 1;
    while(low < high) {
       mid = low + (high - low) / 2;
        if(v[mid] > x) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return(--low >= 0 && x == v[low] ? low : -1);
}
        
int main() {
    int v[7] = {1, 1, 3,4, 5, 7, 9};
    int s = sizeof(v)/sizeof(v[0]);
    for(int i = 0; i < s; ++i) {
        printf("%d ", v[i]);
    }
    int r = binsearch(5, v, s);
    printf("\n%d\n", r);
    return 0;
}
