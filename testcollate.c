#include "accent.h"
#include <string.h>
#include <assert.h>

//https://www.cprogramming.com/tutorial/cpreprocessor.html
#define DEBUG_hcgreekFunc(testNum,strA,strB,expectedVal) char *a##testNum = strA; \
							char *b##testNum = strB; \
							int c##testNum = hcgreekFunc(NULL, strlen(a##testNum), a##testNum, strlen(b##testNum), b##testNum); \
							printf("TEST" #testNum ": %s, %s: %d\n\n", a##testNum, b##testNum, c##testNum); \
							assert(c##testNum == expectedVal);

static int hcgreekFunc(
  void *NotUsed,
  int nKey1, const void *pKey1,
  int nKey2, const void *pKey2
){
    return compareSort(nKey1, pKey1, nKey2, pKey2);
    //int s = (nKey1 < nKey2) ? nKey1 : nKey2;
    //return memcmp(pKey1, pKey2, s);
}

int main(int argc, char **argv)
{
	DEBUG_hcgreekFunc(1, "", "", 0);

	DEBUG_hcgreekFunc(2, "α", "", 1);

	DEBUG_hcgreekFunc(3, "", "α", -1);

	DEBUG_hcgreekFunc(4, " καια", " καια", 0);

	DEBUG_hcgreekFunc(5, "και αβ", "και α", 0);

	DEBUG_hcgreekFunc(6, "β", "α", 1);

	DEBUG_hcgreekFunc(7, "α", "β", -1);

	DEBUG_hcgreekFunc(8, "αβ", "α", 1);

	DEBUG_hcgreekFunc(9, "α", "αβ", -1);
	


	//DEBUG_hcgreekFunc(10, "α", "αβ", -1);



	printf("All tests passed\n");
}
