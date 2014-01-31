#include <stdio.h>
#include <stdlib.h>

int **ploca, **preskoci;
int postavljeno, n, br_poteza;
int *stog;

void kraljice();
void postavi_kraljicu(int red, int stupac);
void ukloni_kraljicu();
void ispisi();
int dijagonala(int red, int stupac, int i, int j);
int slijedeci_red();

int main(int argc, char *argv[])
{
	int i;

	if (argc != 2)
	{
		printf("potrebno je odrediti velicinu ploce\n");
		exit(1);
	}
	
	n = atoi(argv[1]);
	
	if (n == 2 || n == 3)
	{
		printf("rjesenje ne postoji za ploce velicine 2x2 i 3x3\n");
		exit(1);
	}
	
	ploca = (int **)calloc(n, sizeof(int *));
	preskoci = (int **)calloc(n, sizeof(int *));
	
	for (i = 0; i < n; i++)
	{
		ploca[i] = (int *)calloc(n, sizeof(int));
		preskoci[i] = (int *)calloc(n, sizeof(int));
	}
	
	stog = (int *)calloc(n, sizeof(int));
		
	postavljeno = 0;
	br_poteza = 0;
	
	kraljice();
	ispisi();
	
	free(ploca);
	free(preskoci);
	free(stog);
	
	return 0;
}

void kraljice()
{
	int stupac, pronasao_mjesto;
	
	while(postavljeno < n)
	{
		pronasao_mjesto = slijedeci_red();

		if (!pronasao_mjesto)
			ukloni_kraljicu();
			
		for (stupac = 0; stupac < n; stupac++)
		{
			if (ploca[stog[postavljeno]][stupac] == 0 && preskoci[stog[postavljeno]][stupac] == 0)
			{
				postavi_kraljicu(stog[postavljeno], stupac);
				pronasao_mjesto = 1;
				break;
			}
		}
	}
}

void postavi_kraljicu(int red, int stupac)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (ploca[i][j] >= 0 && (i == red || j == stupac || dijagonala(red, stupac, i, j)))
				ploca[i][j]++;
		}
		
	ploca[red][stupac] = -10;
	postavljeno++;
	br_poteza++;
	
	printf("postavio kraljicu na red %d, stupac %d\n", red +1, stupac + 1);
}

void ukloni_kraljicu()
{
	int red, stupac, stupac_kraljice;
	postavljeno--;
	
	for (stupac = 0; stupac < n; stupac++)
	{
		if (ploca[stog[postavljeno]][stupac] == -10)
		{
			ploca[stog[postavljeno]][stupac] = 0;
			preskoci[stog[postavljeno]][stupac] = 1;
			stupac_kraljice = stupac;
			break;
		}
	}
	
	for (red = 0; red < n; red++)
		for (stupac = 0; stupac < n; stupac++)
		{
			if (ploca[red][stupac] > 0 && (red == stog[postavljeno] || stupac == stupac_kraljice || dijagonala(stog[postavljeno], stupac_kraljice, red, stupac)))
				ploca[red][stupac]--;
		}
	
	br_poteza++;
	
	printf("uklonio kraljicu sa reda %d, stupca %d\n", stog[postavljeno] + 1, stupac_kraljice + 1);
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
	printf("redoslijed po redovima: ");
	for (red = 0; red < n; red ++)
		printf("%d ", stog[red] + 1);
	printf("\n");
}

int dijagonala(int red, int stupac, int i, int j)
{
	return abs(red - i) == abs(stupac - j);
}

int slijedeci_red()
{
	int red, stupac, br_slobodnih, min_br, i;
	int slobodan_red = 0;
	int odabrani_red = 0;
	int ima_kraljicu = 0;
	int br_provjera = 0;
	
	min_br = n + 1;
	
	for (red = 0; red < n; red++)
	{
		slobodan_red = 1;
		br_slobodnih = 0;
		ima_kraljicu = 0;
		
		if (br_provjera < postavljeno)
		{
			for(i = 0; i < postavljeno; i++)
			{
				if (stog[i] == red)
				{
					ima_kraljicu = 1;
					br_provjera++;
					break;
				}
			}
		}
			
		if (!ima_kraljicu)
		{
			for (stupac = 0; stupac < n; stupac++)
			{
				if (ploca[red][stupac] == 0 && preskoci[red][stupac] == 0)
				{
					br_slobodnih++;
				}
			}
		}
		
		if (!br_slobodnih && !ima_kraljicu)
		{
			slobodan_red = 0;
			break;
		}
		
		if (br_slobodnih < min_br && br_slobodnih > 0)
		{
			min_br = br_slobodnih;
			odabrani_red = red;
		}
	}
	
	if(slobodan_red)
	{
		if (stog[postavljeno] >= 0)
		{
			for (i = 0; i < n; i++)
				preskoci[stog[postavljeno]][i] = 0;
		}		
		stog[postavljeno] = odabrani_red;
	}
	
	return slobodan_red;
}
