#include "accent.h"
#include <string.h>
#include <assert.h>

//https://www.cprogramming.com/tutorial/cpreprocessor.html
#define DEBUG_hcgreekFunc(testNum,strA,strB,expectedVal) char *a##testNum = strA; \
							char *b##testNum = strB; \
							int c##testNum = hcgreekFunc(NULL, strlen(a##testNum), a##testNum, strlen(b##testNum), b##testNum); \
							printf("res" #testNum ": %d\n", c##testNum); \
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
	char *a1 = "";
	char *b1 = "";
	int c1 = hcgreekFunc(NULL, strlen(a1), a1, strlen(b1), b1);
	printf("c1: %d\n", c1);
	assert(c1 == 0);

	char *a2 = "α";
	char *b2 = "";
	int c2 = hcgreekFunc(NULL, strlen(a2), a2, strlen(b2), b2);
	printf("c2: %d\n", c2);
	assert(c2 == 1);

	char *a3 = "";
	char *b3 = "α";
	int c3 = hcgreekFunc(NULL, strlen(a3), a3, strlen(b3), b3);
	printf("c3: %d\n", c3);
	assert(c3 == -1);

	char *a4 = " καια";
	char *b4 = " καια";
	int c4 = hcgreekFunc(NULL, strlen(a4), a4, strlen(b4), b4);
	printf("c4: %d\n", c4);
	assert(c4 == 0);

	char *a5 = "και αβ";
	char *b5 = "και α";
	int c5 = hcgreekFunc(NULL, strlen(a5), a5, strlen(b5), b5);
	printf("c5: %d\n", c5);
	assert(c5 == 0);

	char *a6 = "β";
	char *b6 = "α";
	int c6 = hcgreekFunc(NULL, strlen(a6), a6, strlen(b6), b6);
	printf("c6: %d\n", c6);
	assert(c6 == 1);

	char *a7 = "α";
	char *b7 = "β";
	int c7 = hcgreekFunc(NULL, strlen(a7), a7, strlen(b7), b7);
	printf("c7: %d\n", c7);
	assert(c7 == -1);	

	char *a8 = "αβ";
	char *b8 = "α";
	int c8 = hcgreekFunc(NULL, strlen(a8), a8, strlen(b8), b8);
	printf("c8: %d\n", c8);
	assert(c8 == 1);

	char *a9 = "α";
	char *b9 = "αβ";
	int c9 = hcgreekFunc(NULL, strlen(a9), a9, strlen(b9), b9);
	printf("c9: %d\n", c9);
	assert(c9 == -1);	

	DEBUG_hcgreekFunc(10, "α", "αβ", -1);



	printf("All tests passed\n");
}
