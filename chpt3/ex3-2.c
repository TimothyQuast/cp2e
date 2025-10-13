#include <stdio.h>


void escape( char *t, char *s) {

    char c;
    int i = 0;
    int j = 0;
    while ( (c = s[i]) != '\0' ) {
        switch(c) {

            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;

            default:
                t[j] = s[i];
                break;

        }
        i++;
        j++;
    }
    t[j] = '\0';
}

void unescape( char *r, char *s) {

    char c;
    int i = 0;
    int j = 0;
    while ( (c = s[i]) != '\0' ) {
        switch(c) {
            case '\\':
                i++;
                switch(s[i]) {
                    case 'n':
                        r[j] = '\n';
                        break;
                    case 't':
                        r[j] = '\t';
                        break;
                    case '\0':
                        r[j] = '\\';
                        i--;
                        break;
                    default:
                        r[j++] = '\\';
                        r[j] = s[i];
                }
                break;
            
            default:
                r[j] = s[i];
                break;

        }
        i++;
        j++;
    }
    r[j] = '\0';
}



int main() {

    char t[64];
    char *s = "My\nfavorite \things";
    char r[64];

    printf("Original: %s\n", s);
    escape(t, s);
    printf("Escaped: %s\n", t);
    unescape(r, t);
    printf("Unescaped: %s\n", r);

    return 0;
}
