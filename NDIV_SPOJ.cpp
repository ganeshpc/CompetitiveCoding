#include<stdio.h>
#include<set>
#include<vector>
#include<cstring>
#include<math.h>

using namespace std;

void sievePrimes(vector<int> &primes, int num);
void printVector(vector<int> vec);
int totalCombinations(vector<int> factors);

int main() {
    int A, B, N;

    scanf("%i %i %i", &A, &B, &N);

    int ans = 0;

    vector<int> primes;
    sievePrimes(primes, B);
    printVector(primes);
    // printf("A: %i  B: %i", A, B);
    for (int i = A; i<=B; i++) {
        int numD = 0;

        vector<int> primeFactors;
        int rem = i;

        vector<int>::iterator vectorIterator = primes.begin();

        for (int j = *vectorIterator; *vectorIterator <= i && vectorIterator != primes.end(); vectorIterator++) {
            j = *vectorIterator;
            while (rem % j == 0 && rem != 0) {
                // printf("WHile stuck");
                rem = rem / j;
                primeFactors.push_back(j);
            }
        }
        
        numD = totalCombinations(primeFactors);

        // printf("Prime factors of %i: ", i);
        // printVector(primeFactors);
        // printf("\n");

        if (numD == N) 
            ans++;

        // printf("I: %i", i);
    }

    printf("%i", ans);
}

void sievePrimes(vector<int> &primes, int num) {
    
    bool arr[num+1];
    memset(arr, true, sizeof(arr));

    for (int i = 2; i<=ceil(sqrt(num)); i++) {
        if (arr[i] == true) {
            for (int j = i*2; j<=num; j+=i) {
                arr[j] = false;
            }
        }
    }

    for (int i = 2; i<=num; i++) {
        if (arr[i]) 
            primes.push_back(i);
    }
}

void printVector(vector<int> vec) {
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        printf("%i  ", *it);
    }
    printf("\n");
}

int totalCombinations(vector<int> factors) {
    int countDistinct = 0;
    int combinations = 0;

    for (vector<int>::iterator it = factors.begin(); it != factors.end(); ) {
        int cur = *it;
        int ctr = 1;
        countDistinct++;
        while (cur == *(++it)) {
            ctr++;
        }
        combinations += ctr;
    }

    combinations += pow(2, countDistinct) - 1;

    return combinations;
}