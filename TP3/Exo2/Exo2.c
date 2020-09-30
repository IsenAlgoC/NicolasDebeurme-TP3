#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	unsigned long  Nb = 2868838400;
	int Oct=0,Bit=0,i=0;
	Oct = sizeof(Nb);
	printf("Nombre d'octets:%d\n", Oct);
	Bit = Oct * 8;
	printf("Nombre de bit:%d\n", Bit);
	while (i < 32) {
		if ((Nb >> i) & 1)
			printf("Bit %d: ON\n", i+1);
		else
			printf("Bit %d: OFF\n", i+1);
		i++;
	}
	printf("ByeBye\n");
}