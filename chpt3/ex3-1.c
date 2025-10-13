#include <stdio.h>
#include <time.h>


int binsearch_book(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int binsearch_ex(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (x == v[mid]) {
        return mid;
    }

    return -1;
}

int main() {
    
    int v[1000000];


    for(int i = 0; i < 1000000; i++) {
        v[i] = i; 
    }

    clock_t start = clock();
    int n_book = binsearch_book(45678, v, 1000000);
    clock_t end = clock();

    double time_book_clocks = (
            (double) (end - start)
    );

    printf("cycles for book binsearch: %.6f\n", time_book_clocks);
    printf("Book result: %d \n\n", n_book);

    start = clock();
    int n_ex = binsearch_book(45678, v, 1000000);
    end = clock();

    double time_ex_clocks = (
            (double) (end - start)
    );

    printf("cycles for ex binsearch: %.6f\n", time_ex_clocks);
    printf("Ex result: %d \n\n", n_ex);
} 
