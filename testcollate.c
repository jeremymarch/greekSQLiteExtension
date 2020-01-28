#include "accent.h"
#include <string.h>
#include <assert.h>

//https://www.cprogramming.com/tutorial/cpreprocessor.html
#define DEBUG_hcgreekFunc(testNum, strA, strB, expectedVal) char *a##testNum = strA; \
							char *b##testNum = strB; \
							printf("TEST " #testNum " START **************\n"); \
							int c##testNum = hcgreekFunc(NULL, strlen(a##testNum), a##testNum, strlen(b##testNum), b##testNum); \
							printf("TEST " #testNum ": %s, %s: %d\n\n", a##testNum, b##testNum, c##testNum); \
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

	DEBUG_hcgreekFunc(10, " <blah> ", "αβ", -1);

	DEBUG_hcgreekFunc(11, "αβ", " <blah> ", 1);

	DEBUG_hcgreekFunc(12, "αβ", " <blah> ", 1);

	DEBUG_hcgreekFunc(13, "αβ", " <blah> αβ", 0);

	DEBUG_hcgreekFunc(14, "ξε(ι)ναπάτης, ξε(ι)ναπάτου, ὁ", "ξε(ι)ναπάτης, ξε(ι)ναπάτου, ὁ", 0);

	DEBUG_hcgreekFunc(15, "ξε(αι)ναπάτης, ξε(ι)ναπάτου, ὁ", "ξε(βι)ναπάτης, ξε(ι)ναπάτου, ὁ", 0);

	DEBUG_hcgreekFunc(16, "βίᾱ, βίᾱς, ἡ", "βίᾱ, βίᾱς, ἡ", 0);

	DEBUG_hcgreekFunc(25, "βίᾱ, βίᾱς, ἡ", "βία, βίᾱς, ἡ", 0);

	DEBUG_hcgreekFunc(26, "βία, βίᾱς, ἡ", "βίᾱ, βίᾱς, ἡ", 0);

	DEBUG_hcgreekFunc(17, "βίᾱα, βίᾱς, ἡ", "βίᾱβ, βίᾱς, ἡ", -1);

	DEBUG_hcgreekFunc(18, "βίᾱ, βίᾱς, ἡ", "βιάζομαι", -1);

	DEBUG_hcgreekFunc(19, "βιάζομαι", "βίᾱ, βίᾱς, ἡ", 1);

	DEBUG_hcgreekFunc(20, "ᾗ", "ᾗ", 0); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(21, "ᾗ", "α", 1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(22, "α", "ᾗ",  -1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(23, "ᾗ", "αβ", 1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(24, "αβ", "ᾗ",  -1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(33, "ᾗ", "ω", -1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(34, "ω", "ᾗ",  1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(35, "ᾗα", "ω", -1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(36, "ω", "ᾗα",  1); //1f27+0345 and 1f27+0345

	DEBUG_hcgreekFunc(27, "γβ", "α",  1); 
	DEBUG_hcgreekFunc(28, "α", "γβ",  -1);

	DEBUG_hcgreekFunc(29, "γβ ", "α",  1); 
	DEBUG_hcgreekFunc(30, "α ", "γβ",  -1);

	DEBUG_hcgreekFunc(31, "γβ ", "α ",  1); 
	DEBUG_hcgreekFunc(32, "α ", "γβ ",  -1);

	DEBUG_hcgreekFunc(37, "χρωτός/χροός, ὁ", "χρωτός/χροός, ὁ",  0);

	DEBUG_hcgreekFunc(38, "βίᾱ, βίᾱς, ἡ", "βιά", 0);
	DEBUG_hcgreekFunc(39, "βιά", "βίᾱ, βίᾱς, ἡ", 0);

		DEBUG_hcgreekFunc(40, "βίᾱ, βίᾱς, ἡ", "βιά", 0);
	DEBUG_hcgreekFunc(41, "βιά", "βίᾱ, βίᾱς, ἡ", 0);


	





	printf("All tests passed\n");
}
