#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define carre(x) (x)*(x)

int main() {
	int Nb = 5;
	printf("Nb^2:%d\n", carre(Nb));
	printf("(Nb+1)^2:%d", carre(Nb + 1));
}