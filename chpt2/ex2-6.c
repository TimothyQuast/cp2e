/*
* Exercise 2-6. Write a function setbits(x,p,n,y) 
* that returns x with the n bits that begin at
* position p set to the rightmost n bits of y, 
* leaving the other bits unchanged.
*/

#include <stdio.h>

/* & - and
 * | - or
 * ^ - xor
 * >>- rs
 * <<- ls
 * ~ - compl.
 */

typedef struct {
    unsigned int x;
    int p;
    int n;
    unsigned int y;
    unsigned int expected_result;
} TestCase;


void binary_string(char *buffer, unsigned int b) {
    int ndigits = 0;
    int is_first_digit_found =0;
    unsigned int d;
    for(int i = 0; i < 32; i++){
        d = (b >> (31-i)) & 1;
        if(!is_first_digit_found && d)
            is_first_digit_found++;

        if(is_first_digit_found) {
            buffer[ndigits] = d + '0';
            ndigits++;
        }
    }
    buffer[ndigits] = '\0';
}

unsigned int setbits(
    unsigned int x,
    int p,
    int n,
    unsigned int y
) {
    unsigned int r_nbits_y = y - ((y>>n)<<n);
    unsigned int x_pn_bits = (
        ((x >> (p-n)) << (p-n)) -
        ((x >> p) << p)
    );
    return (x ^ x_pn_bits) + (r_nbits_y << (p-n));
}

int main() {
    
    TestCase test_cases[] = {
        {0b11111111, 5, 3, 0b1010000, 0b11000111},
        {0b11111111, 1, 2, 0b1100, 0b11111100},
        {0b10101010, 4, 1, 0b11, 0b10111010},
        {0b00000000, 4, 4, 0b0101111, 0b00011110},
        {0b00000000, 7, 4, 0b1010, 0b10100000},
        {0b11110000, 7, 4, 0b1111, 0b11110000},
        {0b10101010, 3, 2, 0b11, 0b10101110},
        {0b11111111, 6, 5, 0b1000000, 0b11000011},
        {0b11111110, 0, 1, 0b1, 0b11111111},
        {0b10000001, 4, 3, 0b101, 0b10010101}
    };

    char x_buffer[33];
    char y_buffer[33];
    char r_buffer[33];
    char er_buffer[33];

    for(int i = 0; i < 10; i++) {
        unsigned int r = setbits(
            test_cases[i].x,
            test_cases[i].p,
            test_cases[i].n,
            test_cases[i].y
        );

        binary_string(x_buffer, test_cases[i].x);
        binary_string(y_buffer, test_cases[i].y);
        binary_string(r_buffer, r);
        binary_string(
            er_buffer, 
            test_cases[i].expected_result
        );

        printf(
            "setbits(%s, %d, %d, %s) = %s; expected %s; %s\n",
            x_buffer, 
            test_cases[i].p,
            test_cases[i].n, 
            y_buffer,
            r_buffer, 
            er_buffer,
            test_cases[i].expected_result==r
                ? "MATCHES"
                : "WRONG"
        );
    }

    return 0;
}
