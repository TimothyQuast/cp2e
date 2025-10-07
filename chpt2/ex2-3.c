/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
 * through 9, a through f, and A through F. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi( char *s ) {
    char c;
    int hex_start_index = 0;
    int value = 0;
    int place_value = 1;
    int ndigits = 0;

    int digits[256];

    int i, is_digit, digit;
    int is_first_digit_found = 0;

    for(i = 0; (c = s[i]) != '\0'; i++) {
        if( i == 0 && c == '0' ) {
            continue;
        }
        if( i == 1 && tolower(c) == 'x' ) {
            continue;
        }

        is_digit = isdigit(c);
        if( is_digit ) {
            digit = c - '0';
        } else {
            digit = 10 + tolower(c) - 'a';
        }

        if( is_first_digit_found ) {
            digits[i - hex_start_index] = digit;
            ndigits++;
        } else {
            if( c != '0' ) {
                hex_start_index = i;
                is_first_digit_found = 1;
                digits[0] = digit;
                ndigits++;
            }
            continue;
        }
    }

    for(i = ndigits - 1; i > -1; i--) {
        value = value + place_value * digits[i];
        place_value = place_value * 16;
    }

    return value;
}

int main () {

    char *hexadecimal_numbers[] = {
        "0", "9", "a", "A", "f", "F",
        "10", "1A", "ff", "FF",
        "0x0", "0x10", "0xFF", "0xDEAD", "0xBEEF",
        "0X0", "0X10", "0XFF",
        "100", "FFF", "1000", "FFFF",
        "0xAbCd", "0XeFfE",
        "7FFFFFFF",
        "0x00FF", "0xCAFE", "0xC0FFEE"
    };

    int expected_results[] = {
        0, 9, 10, 10, 15, 15,
        16, 26, 255, 255,
        0, 16, 255, 57005, 48879,
        0, 16, 255,
        256, 4095, 4096, 65535,
        43981, 61438,
        2147483647,
        255, 51966, 12648430
    };

    int i, result, is_result_matching, num_mismatch_results;
    char *is_result_matching_string;

    num_mismatch_results = 0;

    printf("%12s %12s %12s %12s \n", "Hex", "Decimal", "Result", "Matches?");

    for( i = 0; i < 28; i++ ) {

        result = htoi( hexadecimal_numbers[i] );
        is_result_matching = result == expected_results[i];

        if(!is_result_matching) {
            num_mismatch_results++;
            is_result_matching_string = "No";
        } else {
            is_result_matching_string = "Yes";
        }

        printf("%12s %12d %12d %12s \n", hexadecimal_numbers[i], expected_results[i], result, is_result_matching_string);

    }

    if( num_mismatch_results ) {
        printf( "Number of non-matching results: %d\n", num_mismatch_results );
    } else {
        printf( "All results matching!\n" );
    }



}
