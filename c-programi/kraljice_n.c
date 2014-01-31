#include <stdio.h>
#include <stdlib.h>

int **ploca, **preskoci;
int postavljeno, n, br_poteza;

void kraljice();
void postavi_kraljicu(int red, int stupac);
void ukloni_kraljicu();
void ispisi();
int kvadrat(int red, int stupac, int i, int j);

int main(int argc, char *argv[])
{
	int i, j;
	
	n = atoi(argv[1]);
	ploca = (int **)malloc(n * sizeof(int *));
	preskoci = (int **)malloc(n * sizeof(int *));
	
	for (i = 0; i < n; i++)
	{
		ploca[i] = (int *)malloc(n * sizeof(int));
		preskoci[i] = (int *)malloc(n * sizeof(int));
	}
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			ploca[i][j] = 0;
			preskoci[i][j] = 0;
		}
		
	postavljeno = 0;
	br_poteza = 0;
	
	kraljice();
	ispisi();
	
	free(ploca);
	free(preskoci);
	
	return 0;
}

void kraljice()
{
	int stupac, pronasao_mjesto;
	
	while(postavljeno < n)
	{
		pronasao_mjesto = 0;
		
		for (stupac = 0; stupac < n; stupac++)
		{
			if (ploca[postavljeno][stupac] == 0 && preskoci[postavljeno][stupac] == 0)
			{
				postavi_kraljicu(postavljeno, stupac);
				pronasao_mjesto = 1;
				break;
			}
		}
		
		if (!pronasao_mjesto)
			ukloni_kraljicu();
	}
}

void postavi_kraljicu(int red, int stupac)
{
	int i, j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == red || j == stupac || kvadrat(red, stupac, i, j))
				ploca[i][j]++;
		}
		
	ploca[red][stupac] = -10;
	postavljeno++;
	br_poteza++;
	
	printf("postavio kraljicu broj %d na stupac %d\n", postavljeno, stupac + 1);
}

void ukloni_kraljicu()
{
	int red, stupac, stupac_kraljice;
	postavljeno--;
	
	for (stupac = 0; stupac < n; stupac++)
	{
		if (ploca[postavljeno][stupac] == -10)
		{
			ploca[postavljeno][stupac] = 0;
			preskoci[postavljeno][stupac] = 1;
			stupac_kraljice = stupac;
			break;
		}
	}
	
	for (red = 0; red < n; red++)
		for (stupac = 0; stupac < n; stupac++)
			if (ploca[red][stupac] > 0 && (red == postavljeno || stupac == stupac_kraljice || kvadrat(postavljeno, stupac_kraljice, red, stupac)))
				ploca[red][stupac]--;
			
	for (stupac = 0; stupac < n; stupac++)
		preskoci[postavljeno + 1][stupac] = 0;
	
	br_poteza++;
	
	printf("uklonio kraljicu broj %d\n", postavljeno + 1);
}

void ispisi()
{
	int red, stupac;
	
	printf("\n");
	
	for (red = 0; red < n; red++)
	{
		for (stupac = 0; stupac < n; stupac++)
		{
			if (ploca[red][stupac] != -10)
				printf("_ ");
			else
				printf("K ");
		}
		printf("\n");
	}
	
	printf("\n");
	printf("rjesenje pronadjeno u %d poteza\n", br_poteza);
}

int kvadrat(int red, int stupac, int i, int j)
{
	int apsolutni_i, apsolutni_j;
	
	apsolutni_i = red - i;
	if (apsolutni_i < 0)
		apsolutni_i = 0 - apsolutni_i;
	
	apsolutni_j = stupac - j;
	if (apsolutni_j < 0)
		apsolutni_j = 0 - apsolutni_j;
		
	if (apsolutni_i == apsolutni_j)
		return 1;
	else
		return 0;
}
