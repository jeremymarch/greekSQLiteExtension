#include <string.h>
#include <stdio.h>
#include "accent.h"
#include <assert.h>

// gcc -pedantic test.c accent.c utilities.c -o ztest

int main(int argc, char **argv)
{
    char *a = "ἀνάξιος, ἀνάξιον";
    int lena = strlen(a);
    char *b = "ἀνα-";
    int lenb = strlen(b);
    int c = compareSort(lena, (const unsigned char *)a, lenb, (const unsigned char *)b);
    assert(c == 1);
    

    char *a2 = "ἀνα-";
    int lena2 = strlen(a2);
    char *b2 = "ἀνάξιος, ἀνάξιον";
    int lenb2 = strlen(b2);
    int c2 = compareSort(lena2, (const unsigned char *)a2, lenb2, (const unsigned char *)b2);
    assert(c2 == -1);
    
    
    char *a3 = "καί";
    int lena3 = strlen(a3);
    char *b3 = "καί ... καί";
    int lenb3 = strlen(b3);
    int c3 = compareSort(lena3, (const unsigned char *)a3, lenb3, (const unsigned char *)b3);
    assert(c3 == -1);
 
    return 0;
}
