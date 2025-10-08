/* Exercise 2-5. Write the function any(s1,s2), 
 * which returns the first location in a string s1
 * where any character from the string s2 occurs, 
 * or -1 if s1 contains no characters from s2. 
 * (The standard library function strpbrk does 
 * the same job but returns a pointer to the 
 * location.)
 */

#include <stdio.h>

typedef struct {
    char *s1;
    char *s2;
    int expected_result;
} TestCase;




int any(char *s1, char *s2){
    
    for(int i = 0; s1[i] != '\0'; i++){
        for(int j = 0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j]){
                return i;
            }
        }
    }

    
    return -1;
}
 

int main() {
    
    TestCase test_cases[] = {
        {"hello world", "o", 4},           
        {"hello world", "wld", 2},        
        {"abcdef", "fed", 3},            
        {"programming", "xyz", -1},     
        {"test", "", -1},                  
        {"", "abc", -1},                  
        {"", "", -1},                    
        {"abc", "cba", 0},                 
        {"hello", "aeiou", 1},            
        {"123456789", "9876", 5},        
    };
    
    int num_tests = sizeof(test_cases) 
        / sizeof(test_cases[0]);
    int passed = 0;
    
    for (int i = 0; i < num_tests; i++) {
        int result = any(
            test_cases[i].s1, 
            test_cases[i].s2
        );
        if (result == test_cases[i].expected_result) {
            printf(
                "PASSED: any(\"%s\", \"%s\") = %d\n", 
                test_cases[i].s1, 
                test_cases[i].s2, 
                result
            );
            passed++;
        } else {
            printf("FAILED: any(\"%s\", \"%s\") = %d, expected %d\n", 
                   test_cases[i].s1, test_cases[i].s2, 
                   result, test_cases[i].expected_result);
        }
    }
    
    printf("\n%d/%d tests passed\n", passed, num_tests);
   

    return 0;
}
