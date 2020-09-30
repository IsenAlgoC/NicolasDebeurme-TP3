#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
#define NBMAXNOTES 30

int main() {
	float notes[NBMAXNOTES], N = 0, moy = 0;
	int i = 0, Abs = 0, STOP = 0,valid=0;
	char Lettre;
	do {
		printf("\nEntrez la note no %d:", i);
		scanf_s("%f", &N);
		if (N > 0 && N < 20) {
			notes[i] = N;
			moy = moy + N;
			valid++;
		}
		else {
			do {
				printf("\n Note invalide (A=absent/O=arreter/N=continuer):");
				Lettre = getchar();
			} while (Lettre != 'A' && Lettre != 'O' && Lettre != 'N');
			switch (Lettre)
			{
			case 'A':
				printf("Abscence ajoute.\n");
				Abs++;
				notes[i] = -1;
				break;
			case 'N':
				printf("On continue.\n");
				i--;
				break;
			case 'O':
				STOP = 1;
				break;
			default:
				printf("Mauvais choix !\n");
			}
		} 
		i++;
	} while (STOP==0 && i != NBMAXNOTES);

	printf("\nNombre de notes valides:%d\n", valid);
	printf("Nombre d'abscences:%d\n", Abs);
	int j = 0;
	float min = 20, max = 0;
	for ( j = 0; j <NBMAXNOTES; j++)
	{
		if (notes[j] < min)
			min = notes[j];

		if (notes[j] > max)
			max = notes[j];
	}
	moy = (moy / valid);
	printf("La moyenne de ces %d notes est de %f\n",valid, moy);
	printf("Note la plus basse: %f\n", min);
	printf("Note la plus haute: %f\n", max);

	int n = 0;
	float tampon = 0, ecartype = 0;
	for ( n = 0; n < NBMAXNOTES; n++)
	{
		tampon += ((notes[n] - moy)* (notes[n] - moy));
	}
	ecartype = sqrtf((1 / valid- 1)*tampon);
	printf("Ecart type= %f", ecartype);
}
