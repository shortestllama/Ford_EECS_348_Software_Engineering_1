#include <stdio.h>
#include <stdlib.h>

int* rec(int s, int* a) {
    return 0;
}
//38
//a is a list of score: [2,2,2,2,2,2,2,2,2,2,2,3]
//chosen[3], {1,2,3,4}, 0, 2, 0, 3
                      //index, r, start, end
void print_a(int s) {
    int q[5] = {2, 3, 6, 7, 8};
    int n = 0;

    if (s % 2 == 0) {
        n = s / 2;
    }

    else {
        n = (s + 1) / 2;
    }

    for (int i = 0; i < s; i++) {
    }
    int* combs = (int*)malloc(sizeof(int) * s);
    rec(s, combs);
}

void recCombs(int chosen[], int arr[], int index, int r, int start, int end) {
    if (index == r) {
    }
}

void combs(int arr[], int n, int r) {
    int chosen[r + 1];

    recCombs(chosen, arr, 0, r, 0, n - 1);
}

int main() {
    printf("%d\n", 25/2);

    int arr[] = {2,3,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int r = 13;
    combs(arr, n, r);

    printf("%lu %lu\n", sizeof(arr), sizeof(arr[0]));
}