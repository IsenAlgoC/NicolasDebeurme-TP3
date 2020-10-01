#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>
#define NBMAXNOTES 30

int main() {
	float notes[NBMAXNOTES] = { 0 };
	float N = 0, moy = 0;
	int i = 0, Abs = 0, STOP = 0,valid=0;
	char Lettre;

	int j = 0;
	float min = 20;
	float max = 0;

	for (i = 0; i < NBMAXNOTES; i++)
	{
		notes[i] = -2;
	}
	i = 0;
	do {
		printf("\nEntrez la note no %d:", i);
		scanf_s("%f", &N);

		if (N > 0 && N < 20) {
			if (N < min)
				min = N;

			if (N > max)
				max = N;
			notes[i] = N;
			moy = moy + N;
			valid++;
		}
		else {
			
			printf("\nNote invalide (A=absent/O=arreter/N=continuer):");
			do {
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
	
	moy = (moy / valid);
	printf("La moyenne de ces %d notes est de %f\n",valid, moy);
	printf("Note la plus basse: %f\n", min);
	printf("Note la plus haute: %f\n", max);

	int n = 0;
	float tampon = 0, ecartype = 0;
	for ( n = 0; n < valid; n++)
	{
		tampon =tampon + ((notes[n] - moy)* (notes[n] - moy));
	}
	ecartype = sqrt((1.0 / ((double)valid - 1.0)) * (double)tampon);
	printf("Ecart type= %f", ecartype);

	printf("\n No note   Valeur note\n ");
	for ( i = 0; i < valid+Abs; i++)
	{
		if (notes[i] == -1)
			printf("Abscence\n");
		else
			printf("%.0f\n", notes[i]);
	}
	int en_desordre = 1,h=0;
	
	while (en_desordre)
	{
		en_desordre = 0;

		for (h = 0; h < NBMAXNOTES; h++)
		{
			/* Si les 2 éléments sont mal triés */
			if (notes[h] > notes[h + 1])
			{
				/* Inversion des 2 éléments */
				float tmp = notes[h + 1];
				notes[h + 1] = notes[h];
				notes[h] = tmp;

				/* Le tableau n'est toujours pas trié */
				en_desordre = 1;
			}
		}
	}
}
