#include "review.h"

int Fibonacci(int a) {
    int Fib[a];
    Fib[0] = 1;
    Fib[1] = 1;
    for(int i = 2; i <= a; i++) {
        Fib[i] = Fib[i-2] + Fib[i-1];
    }
    return Fib[a];
}