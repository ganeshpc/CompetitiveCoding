#include<stdio.h>
#include<array>

using namespace std;

int biggestOfThree(int* arr, int i, int size);
void printArray(int* arr, int size);

int main() {
    int T;

    scanf("%i", &T);

    for (int t = 0; t<T; t++) {
        int N;
        scanf("%i", &N);
        int arr[N];
        for (int n = 0; n < N; n++) {
            scanf("%i", &arr[n]);
        }

        for (int i = 1; i<N; i+=2) {
            int max = biggestOfThree(arr, i, N);
            if (max == i) continue;

            swap(arr[i], arr[max]);
        }

        printArray(arr, N);
    }
}

int biggestOfThree(int* arr, int i, int size) {
    int max = i;

    if (arr[i-1] > arr[max]) {
        max = i-1;
    } 

    if (arr[i+1] > arr[max] && (i+1) < size) {
        max = i+1;
    }

    return max;
}

void printArray(int* arr, int size) {
    for (int i = 0; i<size; i++) {
        printf("%i ", arr[i]);
    }

    printf("\n");
}