/* Exercise 2-4. Write an alternate version of
 * squeeze(s1, s2) that deletes each character in
 * s1 that matches any character in the string s2.
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char s1[64];
    char *s2;
    char *expected_result;
} SqueezeTestCase;

void squeeze(char *s1, char *s2) {

    char c1, c2;
    int i,j,k;
    i = 0;
    j = 0;

    while( (c1 = s1[i]) != '\0' ) {
        while( (c2 = s2[j++]) != '\0') {
            if(c1 == c2){
                while( 
                    (s1[k] = s1[++k])
                    != '\0'
                );
                break;
            }
        }
        i++;
    }

}

int main() {
    char original[50];

    SqueezeTestCase test_cases[] = {
        { "goofy", "of", "gy" },
        { "Glorfindel", "Bilbo", "Grfnde" },
        { "Aragorn", "Gimli", "Aragorn" },
        { "Gandalf", "Ganondorf", "l" },
        { "zach", "Nebuchadnezzar", "" }
    };

    for( int i = 0; i < 5; i++) {
        SqueezeTestCase c = test_cases[i];
        strcpy(original, c.s1);
        squeeze( c.s1, c.s2 );

        printf(
            "squeeze( %s, %s ) = %s ... %s\n",
            original, c.s2, c.s1,
            strcmp(c.s1, c.expected_result)==0
                ? "Matches!"
                : "Wrong :("
        );
    }

}
