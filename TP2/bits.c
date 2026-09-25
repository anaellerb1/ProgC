#include <stdio.h>

int main(){
	unsigned int d = 3;
	unsigned int bit4, bit20;

	bit4 = (d >> 28) & 1;
	bit20 = (d >> 12) & 1;
	printf("%u\n", bit4 & bit20);

	return 0;
}
