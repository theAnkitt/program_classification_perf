#include <stdio.h>

// Recursive function to generate Fibonacci series
long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print Fibonacci series
void printFibonacciSeries(int n) {
    printf("Fibonacci Series up to %d terms: \n", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms for Fibonacci Series: ");
    scanf("%d", &terms);

    printFibonacciSeries(terms);

    return 0;
}
