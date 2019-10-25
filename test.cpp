#include<stdio.h>
#include<math.h>
#include<cstdlib>
#include<string>

using namespace std;

int noOfDigits(int num);

int main() {
    int T;
    scanf("%i", &T);
    for (int t = 0; t<T; t++) {
        int avg;
        int digits = 0;
        // scanf("%*[^.] %*c %d", &avg);   

        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);  
        

        char* average;
        // scanf("%s", average);
        average = to_string(r);
        printf("float: %f    sting: %s", r, average);
        return 0;

        int ignores = 0;

        for (int i = 0; average[i] != '\0'; i++) {
            if (average[i] == '.') {
                ignores = i+1;
                i++;
                while(average[i] != '\0') {
                    digits++;
                    i++;
                }
                break;
            }
        }   

        if (ignores == 0) {
            // printf("%d\n", 1);
            continue;
        }

        avg = atoi(average);  

        int mataches = 1;

        while(avg % 10 == 0) {
            // printf("in while avg: %d\n", avg);
            avg /= 10;
            digits--;
        }

        for (int i = 0; i<digits; i++) {
            int exp = pow(10, i+1);
            int endDigit = (avg % exp) / (exp/10);

            // printf("End digit: %d\n", endDigit);
            
            if (endDigit == 1 || endDigit == 3 || endDigit == 7 || endDigit == 9) {
                // printf("digits: %d  i: %d\n", digits, i);
                mataches *= pow(10, digits-i);
                break;
            }

            if (endDigit == 2 || endDigit == 4 || endDigit == 8 || endDigit == 6) {
                avg *= 5;
                mataches *= 5;
            }

            if (endDigit == 5) {
                avg *= 2;
                mataches *= 2;
            }
        }

        printf("%d\n", mataches);
        
    }

}

int noOfDigits(int num) {
    int digits = 0;
    while (num) {
        num /= 10;
        digits++;
    }
    return digits; 
}

