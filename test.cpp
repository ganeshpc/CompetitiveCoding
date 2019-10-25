#include<iostream>
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<vector>
#include<array>
#include<cstring>
#include<math.h>


using namespace std;

void printArray(int*, int);
void printVector(vector<int> vec);
void simpleSieve(int num);
void segmentedSieve(int num);
void modifyVector(vector<int>&);
int noOfDigits(int num);

int main() {
    vector<int> a;
    a.push_back(12);
    a.push_back(45);
    a.push_back(55);

    modifyVector(a);

    printVector(a);
}

void modifyVector(vector<int>& a) {
    a.push_back(77);
}

void printArray(int* arr, int size) {
    for (int i = 0; i<size; i++) {
        printf("%i  ",arr[i]);
    }

    printf("\n");
}

void printVector(vector<int> vec) {
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        printf("%i  ", *it);
    }
    printf("\n");
}

void simpleSieve(int num) {
    bool arr[num];

    memset(arr, true, sizeof(arr));

    for (int p = 2; p*p < num; p++) {

        if (arr[p] == true) {
            for (int i = p*2; i < num; i+=p) {
                arr[i] = false;
            }
        }
    }

    for (int i = 0; i<num; i++) {
        if (arr[i]) printf("%i ", i);
    }
    printf("\n");    
}

void segmentedSieve(int num) {
    vector<int> primes;

    int segment = floor(sqrt(num))+1;

    printf("Segment: %i", segment);

    bool arr[segment];

    memset(arr, true, sizeof(arr));

    for (int p = 2; p*p < segment; p++) {
        if (arr[p] == true) {
            for (int i = p*2; i<segment; i+=p) {
                arr[i] = false;
            }
        }
    }

    for (int i = 2; i < segment; i++) {
        if (arr[i]) {
            primes.push_back(i);
        }
    }

    for (auto it = primes.begin(); it != primes.end(); it++) {
        printf("%i ", *it);
    }

    printf("\n");
}

int noOfDigits(int num) {
    int digits = 0;
    while (num) {
        num /= 10;
        digits++;
    }
    return digits; 
}