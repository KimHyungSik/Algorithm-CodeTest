//4. ¹è¿­ ch[26] = { 'A','B',,,,,,'Z' };
//ABCD............WXYZ
//BCDE.............XYZA
//CDEF.............YZAB
//.................................
//ZABC.............VWXY
#include <stdio.h>

int main() {
    char ch[26] = { 'A','B','C','D','E','F','G','H','I',
   'J','K','L','M','N','O','P','Q','R',
   'S','T','U','V','W','X','Y','Z' };
    for (int i = 0; i < 26; i++) {
        for (int j = i; j < 26 ; j++) {
            printf("%c ", ch[j]);
        }
        for (int j = 0; j < i; j++) {
            printf("%c ", ch[j]);
        }
        printf("\n");
    }
}