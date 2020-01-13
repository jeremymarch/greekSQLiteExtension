#include <string.h>
#include <stdio.h>
#include "accent.h"
#include <assert.h>

int main()
{
    
    const unsigned char *a = "ἀνάξιος, ἀνάξιον";
    int lena = strlen(a);
    const unsigned char *b = "ἀνα-";
    int lenb = strlen(b);
    int c = compareSort(lena, a, lenb, b);
    assert(c == 1);
    

    const unsigned char *a2 = "ἀνα-";
    int lena2 = strlen(a2);
    const unsigned char *b2 = "ἀνάξιος, ἀνάξιον";
    int lenb2 = strlen(b2);
    int c2 = compareSort(lena2, a2, lenb2, b2);
    assert(c2 == -1);
    
    
    const unsigned char *a3 = "καί";
    int lena3 = strlen(a3);
    const unsigned char *b3 = "καί ... καί";
    int lenb3 = strlen(b3);
    int c3 = compareSort(lena3, a3, lenb3, b3);
    assert(c3 == -1);
 
}
