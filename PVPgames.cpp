#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tris(void);
int bot1(void);
int bot2(void);
void posizioniBN(char A[10][10], int n);
void mappaBN(char A[10][10]);
int vittoriaBN(char V[10][10]);
void battnavBN();
void botdifficileBN();
void posizionibotBN(char A[10][10], int n);
void botfacileBN();
void mappaF(char A[6][7]);
void posizioniF(char A[6][7], int seme);
int vittoriaF(char A[6][7], int seme);
void f4F(int a, char A[6][7]);
void posizionibotF(char A[6][7], int seme);
void bot1F(int a, char A[6][7]);

//prova
int main()
{
	int n,f,m, ris, punti;
	int i;
	int j;
	int a;
	char seme;
	char A[6][7];
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			A[i][j]=' ';
		}
	}
	
	printf(" ___ .-. .-.     .--.    ___ .-.    ___  ___  \n");
	printf("(   )   '   \\   /    \\  (   )   \\  (   )(   ) \n");
	printf(" |  .-.  .-. ; |  .-. ;  |  .-. .   | |  | |  \n");
	printf(" | |  | |  | | |  | | |  | |  | |   | |  | |  \n");
	printf(" | |  | |  | | |  |/  |  | |  | |   | |  | |  \n");
	printf(" | |  | |  | | |  ' _.'  | |  | |   | |  | |  \n");
	printf(" | |  | |  | | |  .'.-.  | |  | |   | |  ; '  \n");
	printf(" | |  | |  | | '  `-' /  | |  | |   ' `-'  /  \n");
	printf("(___)(___)(___) `.__.'  (___)(___)   '.__.'   \n\n\n");
	
	printf("1-TRIS\n");
	printf("2-BATTAGLIA NAVALE\n");
	printf("3-FORZA 4\n");
	
	printf("Scegli il gioco che vuoi giocare:");
	scanf("%d",&n); 
	
	if(n<=0 && n>=4)
	{
		printf("scelta non valida");
	}
	
	if(n==1)
	{
		system("cls");
		printf("Hai selezionato:TRIS\n");
		printf("scegli la modalita' di gioco(1=PvP 2=PvBOTfacile 3=PvBOTdifficile):");
		scanf("%d",&f);
		
		if(f==1)
		{
			ris=tris();
		}
		else if(f==2)
		{
			ris=bot1();
		}
		else if(f==3)
		{
			ris=bot2();
		}
	}
	
	if(n==2)
	{
		system("cls");
		printf("Hai selezionato:BATTAGLIA NAVALE\n");
		printf("scegli la modalita' di gioco(1=PvP 2=PvBOTfacile 3=PvBOTdifficile):");
		scanf("%d",&f);
		
		if(f==1)
		{
			battnavBN();
		}
		else if(f==2)
		{
			botdifficileBN();
		}
		else if(f==3)
		{
			botfacileBN();
		}
	}
	
	if(n==3)
	{
		system("cls");
		printf("Hai selezionato:BATTAGLIA NAVALE\n");
		printf("scegli la modalita' di gioco(1=PvP 2=PvBOTfacile 3=PvBOTdifficile):");
		scanf("%d",&f);
		
		if(f==1)
		{
			mappaF(A);
	
			f4F(a, A);
		}
		else if(f==2)
		{
			mappaF(A);
	
			bot1F(a, A);
		}
		else if(f==3)
		{
			mappaF(A);
	
			bot2F(a, A);
		}
	}
}

int tris(void)
{
	int i, j, turno, giocatore, r, c, flag;
	char simbolo;

			turno = 0;
			int griglia[3][3];

				i = 0;
				j = 0;
				for (i=0; i<3; i++) {
					for (j=0; j<3; j++) {
						griglia[i][j] = -1;
					}
				}

			for (turno=0; turno<9; turno++) {
				if (turno%2==0) { giocatore = 0; }
				else { giocatore = 1; }
				flag = 0;

					while (flag != 1) {
						printf ("Player %d inserisci le coordinate\n", giocatore);
						scanf("%d %d" , &r , &c);

							if ((griglia[r][c] != -1) || (r>2) || (c>2) || (r<0) || (c<0)) { 
								flag = 0;
									if ((r>2) || (c>2) || (r<0) || (c<0)) {
										printf("Cordinate non valide\n");
									}
									else {
										printf("Questo valore non e'compreso, inseriscine un'altro\n");
									}
							}
							else { 
								flag = 1;
								griglia[r][c] = giocatore;
							}
					}

						i = 0;
						j = 0;
						for (i=0; i<3; i++) {
							for (j=0; j<3; j++) {
										if (griglia[i][j] == -1) {
											simbolo = '#';
										}
										else {
											if (griglia[i][j] == 0) {
											simbolo = 'X';
											}
											else {
											simbolo = 'O';
											}
										}
								if (j<2) { printf ("%c ", simbolo); }
								else { printf ("%c\n", simbolo); }
							}
						}

				if (( ((griglia[0][0]==1) && (griglia[0][1]==1) && (griglia[0][2]==1)) || ((griglia[1][0]==1) && (griglia[1][1]==1) && (griglia[1][2]==1)) || ((griglia[2][0]==1) && (griglia[2][1]==1) && (griglia[2][2]==1)) || ((griglia[0][0]==1) && (griglia[1][1]==1) && (griglia[2][2]==1)) || ((griglia[2][0]==1) && (griglia[1][1]==1) && (griglia[0][2]==1)) ) || ( ((griglia[0][0]==0) && (griglia[0][1]==0) && (griglia[0][2]==0)) || ((griglia[1][0]==0) && (griglia[1][1]==0) && (griglia[1][2]==0)) || ((griglia[2][0]==0) && (griglia[2][1]==0) && (griglia[2][2]==0)) || ((griglia[0][0]==0) && (griglia[1][1]==0) && (griglia[2][2]==0)) || ((griglia[2][0]==0) && (griglia[1][1]==0) && (griglia[0][2]==0)) )) {
					printf ("Player %d wins!\n", giocatore);
					
					if(giocatore==0)
					{
						return 1;
					}
					if(giocatore==1)
					{
						return 0;
					}
								
				}
			}
			printf ("Pareggio!\n");
		
	return 0;
}

int bot1(void)
{
	srand(time(0));
	int i, j, turno, r, c, flag;
	char simbolo;
	turno = 0;
	int griglia[3][3];
	i = 0;
	j = 0;
	
	for (i=0; i<3; i++) 
		{
			for (j=0; j<3; j++) 
			{
				if (griglia[i][j] == -1) 
				{
					simbolo = '#';
				}
				else 
				{
					if (griglia[i][j] == 0) 
					{
						simbolo = 'X';
					}
					else 
					{
						simbolo = 'O';
					}
				}
				if (j<2)
				{ 
					printf ("%c ", simbolo); 
				}
				else 
				{ 
					printf ("%c\n", simbolo); 
				}
			}
		}
	
	for (i=0; i<3; i++) 
	{
		for (j=0; j<3; j++) 
		{
			griglia[i][j] = -1;
		}
	}

	for (turno=0; turno<9; turno++) 
	{
		flag = 0;

		while (flag != 1) 
		{
			printf ("Player inserisci le coordinate\n");
			scanf("%d %d" , &r , &c);

			if ((griglia[r][c] != -1) || (r>2) || (c>2) || (r<0) || (c<0)) 
			{ 
				flag = 0;
				if ((r>2) || (c>2) || (r<0) || (c<0)) 
				{
					printf("Cordinate non valide\n");
				}
				else 
				{
					printf("Questo valore non e'compreso, inseriscine un'altro\n");
				}
			}
			else 
			{ 
				flag = 1;
				griglia[r][c] = 0;
			}

			do
			{
				r=rand()%3;
				c=rand()%3;
			}while(griglia[r][c]==1 || griglia[r][c]==0);
			griglia[r][c] = 1;
		}

		i = 0;
		j = 0;
		for (i=0; i<3; i++) 
		{
			for (j=0; j<3; j++) 
			{
				if (griglia[i][j] == -1) 
				{
					simbolo = '#';
				}
				else 
				{
					if (griglia[i][j] == 0) 
					{
						simbolo = 'X';
					}
					else 
					{
						simbolo = 'O';
					}
				}
				if (j<2)
				{ 
					printf ("%c ", simbolo); 
				}
				else 
				{ 
					printf ("%c\n", simbolo); 
				}
			}
		}

		if (( ((griglia[0][0]==1) && (griglia[0][1]==1) && (griglia[0][2]==1)) || ((griglia[1][0]==1) && (griglia[1][1]==1) && (griglia[1][2]==1)) || ((griglia[2][0]==1) && (griglia[2][1]==1) && (griglia[2][2]==1)) || ((griglia[0][0]==1) && (griglia[1][1]==1) && (griglia[2][2]==1)) || ((griglia[2][0]==1) && (griglia[1][1]==1) && (griglia[0][2]==1)) || ((griglia[0][0]==1) && (griglia[1][0]==1) && (griglia[2][0]==1)) || ((griglia[0][1]==1) && (griglia[1][1]==1) && (griglia[2][1]==1)) || ((griglia[0][2]==1) && (griglia[1][2]==1) && (griglia[2][2]==1)))) 
		{
			printf ("Bot wins!\n");
			return 1;						
		}
		else if((((griglia[0][0]==0) && (griglia[0][1]==0) && (griglia[0][2]==0)) || ((griglia[1][0]==0) && (griglia[1][1]==0) && (griglia[1][2]==0)) || ((griglia[2][0]==0) && (griglia[2][1]==0) && (griglia[2][2]==0)) || ((griglia[0][0]==0) && (griglia[1][1]==0) && (griglia[2][2]==0)) || ((griglia[2][0]==0) && (griglia[1][1]==0) && (griglia[0][2]==0)) || ((griglia[0][0]==0) && (griglia[1][0]==0) && (griglia[2][0]==0)) || ((griglia[0][1]==0) && (griglia[1][1]==0) && (griglia[2][1]==0)) || ((griglia[0][2]==0) && (griglia[1][2]==0) && (griglia[2][2]==0))))
		{
			printf ("Player wins!\n");
			return 0;
		}
	}
	printf ("Pareggio!\n");
		
	return 0;
}

int bot2(void)
{

	srand(time(NULL));
	int i=0, j=0, turno, r=0, c=0, flag=0;
	char simbolo;
	turno = 0;
	int griglia[3][3];
	i = 0;
	j = 0;
	
	for (i=0; i<3; i++) 
	{
		for (j=0; j<3; j++) 
		{
			griglia[i][j] = -1;
		}
	}
	
	for (i=0; i<3; i++) 
		{
			for (j=0; j<3; j++) 
			{
				if (griglia[i][j] == -1) 
				{
					simbolo = '#';
				}
				else 
				{
					if (griglia[i][j] == 0) 
					{
						simbolo = 'X';
					}
					else 
					{
						simbolo = 'O';
					}
				}
				if (j<2)
				{ 
					printf ("%c ", simbolo); 
				}
				else 
				{ 
					printf ("%c\n", simbolo); 
				}
			}
		}

	for (turno=0; turno<5; turno++) 
	{
		flag = 0;

		while (flag != 1) 
		{
			printf ("Player inserisci le coordinate\n");
			scanf("%d %d" , &r , &c);
			
			if ((r>2) || (c>2) || (r<0) || (c<0)) 
			{
				flag = 0;
				printf("Cordinate non valide\n");
			}
			else if(griglia[r][c] != -1)
			{
				flag = 0;
				printf("Casella gia' occupata\n");
			}
			else 
			{ 
				flag = 1;
				griglia[r][c] = 0;
			}
		}
		
		i = 0;
		j = 0;
		for (i=0; i<3; i++) 
		{
			for (j=0; j<3; j++) 
			{
				if (griglia[i][j] == -1) 
				{
					simbolo = '#';
				}
				else 
				{
					if (griglia[i][j] == 0) 
					{
						simbolo = 'X';
					}
					else 
					{
						simbolo = 'O';
					}
				}
				if (j<2)
				{ 
					printf ("%c ", simbolo); 
				}
				else 
				{ 
					printf ("%c\n", simbolo); 
				}
			}
		}
		
		printf("\n");

		if((((griglia[0][0]==0) && (griglia[0][1]==0) && (griglia[0][2]==0)) || ((griglia[1][0]==0) && (griglia[1][1]==0) && (griglia[1][2]==0)) || ((griglia[2][0]==0) && (griglia[2][1]==0) && (griglia[2][2]==0)) || ((griglia[0][0]==0) && (griglia[1][1]==0) && (griglia[2][2]==0)) || ((griglia[2][0]==0) && (griglia[1][1]==0) && (griglia[0][2]==0)) || ((griglia[0][0]==0) && (griglia[1][0]==0) && (griglia[2][0]==0)) || ((griglia[0][1]==0) && (griglia[1][1]==0) && (griglia[2][1]==0)) || ((griglia[0][2]==0) && (griglia[1][2]==0) && (griglia[2][2]==0))))
		{
			printf ("Player wins!\n");
			return 0;
		}
		
		if(turno<4)
		{
			printf("Cordinate del bot:\n");
				
			for(r=0;r<3;r++)
			{
				for(c=0;c<3;c++)
				{	
					if(griglia[r][c]==-1)
					{
						griglia[r][c]=1;
							
						if (( ((griglia[0][0]==1) && (griglia[0][1]==1) && (griglia[0][2]==1)) || ((griglia[1][0]==1) && (griglia[1][1]==1) && (griglia[1][2]==1)) || ((griglia[2][0]==1) && (griglia[2][1]==1) && (griglia[2][2]==1)) || ((griglia[0][0]==1) && (griglia[1][1]==1) && (griglia[2][2]==1)) || ((griglia[2][0]==1) && (griglia[1][1]==1) && (griglia[0][2]==1)) || ((griglia[0][0]==1) && (griglia[1][0]==1) && (griglia[2][0]==1)) || ((griglia[0][1]==1) && (griglia[1][1]==1) && (griglia[2][1]==1)) || ((griglia[0][2]==1) && (griglia[1][2]==1) && (griglia[2][2]==1)))) 
						{
							i = 0;
							j = 0;
							for (i=0; i<3; i++) 
							{
								for (j=0; j<3; j++) 
								{
									if (griglia[i][j] == -1) 
									{
										simbolo = '#';
									}
									else 
									{
										if (griglia[i][j] == 0) 
										{
											simbolo = 'X';
										}
										else 
										{
											simbolo = 'O';
										}
									}
									
									if (j<2)
									{ 
										printf ("%c ", simbolo); 
									}
									else 
									{ 
										printf ("%c\n", simbolo); 
									}
								}
							}
							
							printf ("Bot wins!\n");
							return 1;						
						}
						else
						{
							griglia[r][c]=-1;	
						}	
					}
				}
			}
			
			flag=0;
			
			for(r=0;r<3;r++)
			{
				for(c=0;c<3;c++)
				{	
					if(griglia[r][c]==-1 && flag==0)
					{
						griglia[r][c]=0;
							
						if((((griglia[0][0]==0) && (griglia[0][1]==0) && (griglia[0][2]==0)) || ((griglia[1][0]==0) && (griglia[1][1]==0) && (griglia[1][2]==0)) || ((griglia[2][0]==0) && (griglia[2][1]==0) && (griglia[2][2]==0)) || ((griglia[0][0]==0) && (griglia[1][1]==0) && (griglia[2][2]==0)) || ((griglia[2][0]==0) && (griglia[1][1]==0) && (griglia[0][2]==0)) || ((griglia[0][0]==0) && (griglia[1][0]==0) && (griglia[2][0]==0)) || ((griglia[0][1]==0) && (griglia[1][1]==0) && (griglia[2][1]==0)) || ((griglia[0][2]==0) && (griglia[1][2]==0) && (griglia[2][2]==0))))
						{
							flag=1;
							griglia[r][c]=1;
							
							i = 0;
							j = 0;
							for (i=0; i<3; i++) 
							{
								for (j=0; j<3; j++) 
								{
									if (griglia[i][j] == -1) 
									{
										simbolo = '#';
									}
									else 
									{
										if (griglia[i][j] == 0) 
										{
											simbolo = 'X';
										}
										else 
										{
											simbolo = 'O';
										}
									}
									
									if (j<2)
									{ 
										printf ("%c ", simbolo); 
									}
									else 
									{ 
										printf ("%c\n", simbolo); 
									}
								}
							}						
						}
						else
						{
							griglia[r][c]=-1;	
						}	
					}
				}
			}
			
			if(flag==0)
			{
				do
				{
					r=rand()%3;
					c=rand()%3;
				}while(griglia[r][c]==1 || griglia[r][c]==0);
			
				griglia[r][c] = 1;
				
				i = 0;
				j = 0;
				for (i=0; i<3; i++) 
				{
					for (j=0; j<3; j++) 
					{
						if (griglia[i][j] == -1) 
						{
							simbolo = '#';
						}
						else 
						{
							if (griglia[i][j] == 0) 
							{
								simbolo = 'X';
							}
							else 
							{
								simbolo = 'O';
							}
						}
						if (j<2)
						{ 
							printf ("%c ", simbolo); 
						}
						else 
						{ 
							printf ("%c\n", simbolo); 
						}
					}
				}
			}
		}	
	}
	
	printf ("Pareggio!\n");
		
	return 0;
}

void battnavBN()
{
	char A[10][10]={' '};
	char B[10][10]={' '};
	char C[10][10]={' '};
	char D[10][10]={' '};
	int a;
	int b;
	char colonna;
	char riga,riga2;
	int i,j;
	
	mappaBN(A);
	
	printf("Per le coordinate inserire lettere maiuscole\n");
	printf("COORDINATE P1\n");
	posizioniBN(A,5);
	posizioniBN(A,4);
	posizioniBN(A,3);
	posizioniBN(A,3);
	posizioniBN(A,2);
	
	
	mappaBN(A);
	
	system("pause");
	system("cls");
	printf("COORDINATE P2\n");
	posizioniBN(B,5);
	posizioniBN(B,4);
	posizioniBN(B,3);
	posizioniBN(B,3);
	posizioniBN(B,2);
	
	
	mappaBN(B);
	
	do
	{
		system("pause");
		system("cls");
		printf("P1\n");
		printf("Inserisci le coordinate della bomba:");
		colonna=getchar();
		riga=getchar();
		riga2=getchar();
		colonna=colonna-65;
		if(riga2=='0')
		{
			riga=9;
		}
		else
		{
			riga=riga-49;
		}

		if(B[riga][colonna]=='-')
		{
			printf("***COLPITO***\n");
			B[riga][colonna]='X';
			C[riga][colonna]='X';
		}
		else
		{
			printf("***NON COLPITO***\n");
			C[riga][colonna]='O';
		}
		
		mappaBN(C);

		a=vittoriaBN(B);
		if(a==0)
		{
			printf("***VITTORIA P1***");
		}
		else
		{
			system("pause");
			system("cls");
			printf("P2\n");
			printf("Inserisci le coordinate della bomba:");
			colonna=getchar();
			riga=getchar();
			riga2=getchar();
			colonna=colonna-65;
			if(riga2=='0')
			{
				riga=9;
			}
			else
			{
				riga=riga-49;
			}
			
			if(A[riga][colonna]=='-')
			{
				printf("***COLPITO***\n");
				A[riga][colonna]='X';
				D[riga][colonna]='X';
			}
			else
			{
				printf("***NON COLPITO***\n");
				D[riga][colonna]='O';
			}
		
			mappaBN(D);
		
			b=vittoriaBN(A);
			if(b==0)
			{
				printf("**VITTORIA P2***");
			}
		}
		
	}while(a==1 && b==1);
}

void botdifficileBN()
{
	char A[10][10]={' '};
	char B[10][10]={' '};
	char C[10][10]={' '};
	char D[10][10]={' '};
	int a=1;
	int b=1;
	char colonna;
	int riga,riga2;
	int i,j;
	int rigabot=0;
	int colonnabot=0;
	int cont=0;
	int spazio=0;
	srand(time(0));
	
	mappaBN(A);
	
	printf("Per le coordinate inserire lettere maiuscole\n");
	printf("COORDINATE P1\n");
	posizioniBN(A,5);
	posizioniBN(A,4);
	posizioniBN(A,3);
	posizioniBN(A,3);
	posizioniBN(A,2);
	
	
	mappaBN(A);

	posizionibotBN(B,5);
	posizionibotBN(B,4);
	posizionibotBN(B,3);
	posizionibotBN(B,3);
	posizionibotBN(B,2);
	
	do
	{
		system("pause");
		system("cls");
		printf("P1\n");
		printf("Inserisci le coordinate della bomba:");
		scanf("%c%d",&colonna,&riga);
		
		colonna=colonna-65;
		
		printf("%c%d",colonna,riga);

		if(B[riga][colonna]=='-')
		{
			printf("***COLPITO***\n");
			B[riga][colonna]='X';
			C[riga][colonna]='X';
		}
		else
		{
			printf("***NON COLPITO***\n");
			C[riga][colonna]='O';
		}
		
		mappaBN(C);

		a=vittoriaBN(B);
		if(a==0)
		{
			printf("***VITTORIA P1***");
		}
		else if(a!=0)
		{
			if(D[rigabot][colonnabot]=='X')
			{
				cont=0;
				
				do
				{
					spazio=rand()%4;
					cont++;
					
					if(spazio==0 && rigabot<9)
					{
						rigabot++;
					}
					else if(spazio==1 && rigabot>0)
					{
						rigabot--;
					}
					else if(spazio==2 && colonnabot<9)
					{
						colonnabot++;
					}
					else if(spazio==3 && colonnabot>0)
					{
						colonnabot--;
					}
				}while(D[rigabot][colonnabot]!='O' && D[rigabot][colonnabot]!='X' && cont<16);
			}
			else if(D[rigabot][colonnabot]!='X' || cont>=16)
			{
				do
				{
					rigabot=rand()%10;
					colonnabot=rand()%10;
				}while(D[rigabot][colonnabot]=='O' && D[rigabot][colonnabot]=='X');
			}
			
			
			if(A[rigabot][colonnabot]=='-')
			{
				printf("***COLPITO***\n");
				A[rigabot][colonnabot]='X';
				D[rigabot][colonnabot]='X';
			}
			else
			{
				printf("***NON COLPITO***\n");
				D[rigabot][colonnabot]='O';
			}
		
			mappaBN(D);
		
			b=vittoriaBN(A);
			if(b==0)
			{
				printf("**VITTORIA P2***");
			}
		}
		
	}while(a==1 && b==1);
}

void botfacileBN()
{
	char A[10][10]={' '};
	char B[10][10]={' '};
	char C[10][10]={' '};
	char D[10][10]={' '};
	int a;
	int b;
	char colonna;
	char riga,riga2;
	int i,j;
	int rigabot;
	int colonnabot;
	int cont=0;
	int spazio=0;
	srand(time(0));
	
	mappaBN(A);
	
	printf("Per le coordinate inserire lettere maiuscole\n");
	printf("COORDINATE P1\n");
	posizioniBN(A,5);
	posizioniBN(A,4);
	posizioniBN(A,3);
	posizioniBN(A,3);
	posizioniBN(A,2);
	
	
	mappaBN(A);

	posizionibotBN(B,5);
	posizionibotBN(B,4);
	posizionibotBN(B,3);
	posizionibotBN(B,3);
	posizionibotBN(B,2);
	
	do
	{
		system("pause");
		system("cls");
		printf("P1\n");
		printf("Inserisci le coordinate della bomba:");
		scanf("%c%d",&colonna,&riga);
		if(cont==0)
		{
			colonna=colonna-10;
		}
		cont++;
		printf("%c%d",colonna,riga);

		if(B[riga][colonna]=='-')
		{
			printf("***COLPITO***\n");
			B[riga][colonna]='X';
			C[riga][colonna]='X';
		}
		else
		{
			printf("***NON COLPITO***\n");
			C[riga][colonna]='O';
		}
		
		mappaBN(C);

		a=vittoriaBN(B);
		if(a==0)
		{
			printf("***VITTORIA P1***");
		}
		else
		{
			rigabot=rand()%10;
			colonnabot=rand()%10;
		
			if(A[rigabot][colonnabot]=='-')
			{
				printf("***COLPITO***\n");
				A[rigabot][colonnabot]='X';
				D[rigabot][colonnabot]='X';
			}
			else
			{
				printf("***NON COLPITO***\n");
				D[rigabot][colonnabot]='O';
			}
		
			mappaBN(D);
		
			b=vittoriaBN(A);
			if(b==0)
			{
				printf("**VITTORIA P2***");
			}
		}
		
	}while(a==1 && b==1);
}

void mappaBN(char A[10][10])
{
	int i,j;
	
	printf(" _______________________\n");
	printf("|  |A|B|C|D|E|F|G|H|I|J|\n");
	for(i=1;i<11;i++)
	{	
		printf(" -----------------------\n");	
		
		if(i==10)
		{
			printf("|%d|",i);
		}
		else
		{
			printf("|%d |",i);
		}
		
		for(j=0;j<10;j++)
		{
			printf("%c",A[i-1][j]);
			if(A[i-1][j]=='-' || A[i-1][j]=='O' || A[i-1][j]=='X')
			{
				printf("|");
			}
			else 
			{
				printf(" |");
			}
		}
		printf("\n");
	}
}

void posizioniBN(char A[10][10], int n)
{
	int i;
	int riga;
	char colonna;
	char cvecchia;
	int rvecchia;
	
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("Inserisci la posizione della nave(%d posizioni):",n);
		scanf("%c%d",&colonna,&riga);
		
		
		while(riga<=0 || riga>10 || colonna-65>9 || colonna-65<0)
		{
			fflush(stdin);
			printf("Coordinate esterne all'area di gioco!\n");
			printf("Reinserisci la posizione della nave:");
			scanf("%c%d",&colonna,&riga);
		}
		
		while(A[riga-1][colonna-65]=='-')
		{
			fflush(stdin);
			printf("Coordinate gia' occupate!\n");
			printf("Reinserisci la posizione della nave:");
			scanf("%c%d",&colonna,&riga);
		}
		
		if(i>0)
		{
			while(!(((colonna-1==cvecchia || colonna+1==cvecchia) && rvecchia==riga) || ((riga-1==rvecchia || riga+1==rvecchia) && cvecchia==colonna)))
			{
				fflush(stdin);
				printf("Coordinate sconnesse!\n");
				printf("Reinserisci la posizione della nave:");
				scanf("%c%d",&colonna,&riga);
			}
		}
		
		cvecchia=colonna;
		rvecchia=riga;
		
	A[riga-1][colonna-65]='-';
		
	}
	printf("\n");
}

void posizionibotBN(char A[10][10], int n)
{
	int i;
	int riga;
	char colonna;
	int direzione;
	int flag=0;
	srand(time(0));
	
	direzione=rand()%2;
	
	if(direzione==0)
	{	
		do
		{
			flag=0;
			colonna=rand()%10;
			riga=rand()%(10-n);
			
			for(i=0;i<n;i++)
			{
				if(A[riga+i][colonna]=='-')
				{
					flag++;
				}
			}
		}while(flag!=0);
		
		for(i=0;i<n;i++)
		{
			A[riga+i][colonna]='-';
		}
	}
	else
	{
		do
		{
			flag=0;
			riga=rand()%10;
			colonna=rand()%(10-n);
			
			for(i=0;i<n;i++)
			{
				if(A[riga][colonna+i]=='-')
				{
					flag++;
				}
			}
		}while(flag!=0);
		
		for(i=0;i<n;i++)
		{
			A[riga][colonna+i]='-';
		}
	}
	
}

int vittoriaBN(char V[10][10])
{
	int i,j;
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(V[i][j]=='-')
			{
				return 1;
			}
		}
	}
	
	return 0;
}

void mappaF(char A[6][7])
{
	int i,j;
	
	printf(" _____________\n");
	printf("|1|2|3|4|5|6|7|\n");
	for(i=0;i<6;i++)
	{	
		printf(" -------------\n");	
		
		printf("|");
		
		for(j=0;j<7;j++)
		{
			printf("%c|",A[i][j]);
		}
		printf("\n");
	}
}

void posizioniF(char A[6][7], int seme)
{
	int i;
	int colonna;
	int riga=5;
	
	fflush(stdin);
	printf("Inserisci la colonna:");
	scanf("%d",&colonna);
	
	while(colonna>7 || colonna<1)
	{
		printf("Coordinate esterne all'area di gioco!");
		printf("Reinserisci la colonna:");
		scanf("%d",&colonna);
	}
	
	do
	{
		
		while(A[riga][colonna-1]!=' ')
		{
			riga--;
		}
		
		A[riga][colonna-1]=seme;
		
		if(riga<0)
		{
			printf("Colonna gia'occupata!");
			printf("Reinserisci la colonna:");
			scanf("%d",&colonna);
		}
	}while(A[riga][colonna-1]==' ');
	
	printf("\n");
}

int vittoriaF(char A[6][7], int seme)
{
	int riga=0;
	int colonna=0;
	for(riga=0;riga<6;riga++)
	{
		for(colonna=0;colonna<4;colonna++)
		{
			if(A[riga][colonna]==seme && A[riga][colonna+1]==seme && A[riga][colonna+2]==seme && A[riga][colonna+3]==seme)
			{
				return 1;
			}
		}
	}
	
	for(colonna=0;colonna<7;colonna++)
	{
		for(riga=0;riga<3;riga++)
		{
			if(A[riga][colonna]==seme && A[riga+1][colonna]==seme && A[riga+2][colonna]==seme && A[riga+3][colonna]==seme)
			{
				return 1;
			}
		}
	}
	
	for(colonna=0;colonna<4;colonna++)
	{
		for(riga=0;riga<3;riga++)
		{
			if(A[riga][colonna]==seme && A[riga+1][colonna+1]==seme && A[riga+2][colonna+2]==seme && A[riga+3][colonna+3]==seme)
			{
				return 1;
			}
		}
	}
	
	for(colonna=0;colonna<4;colonna++)
	{
		for(riga=6;riga>3;riga--)
		{
			if(A[riga][colonna]==seme && A[riga-1][colonna+1]==seme && A[riga-2][colonna+2]==seme && A[riga-3][colonna+3]==seme)
			{
				return 1;
			}
		}
	}
	
	return 0;
}

void f4F(int a, char A[6][7])
{
	while(a!=1)
	{
		printf("turno PLAYER 1\n");
		posizioniF(A,'O');
		mappaF(A);
		a=vittoriaF(A,'O');
		if(a==1)
		{
			printf("PLAYER 1 WIN!\n");
		}
		else
		{
			printf("turno PLAYER 2\n");
			posizioniF(A,'X');
			mappaF(A);
			a=vittoriaF(A,'X');
			if(a==1)
			{
				printf("PLAYER 2 WIN!\n");
			}
		}
		
	}
}

void bot1F(int a, char A[6][7])
{
	
	while(a!=1)
	{
		printf("turno PLAYER 1\n");
		posizioniF(A,'O');
		mappaF(A);
		a=vittoriaF(A,'O');
		if(a==1)
		{
			printf("PLAYER 1 WIN!\n");
		}
		else
		{
			printf("turno BOT\n");
			posizionibotF(A,'X');
			mappaF(A);
			a=vittoriaF(A,'X');
			if(a==1)
			{
				printf("BOT WIN!\n");
			}
		}
		
	}
}

void bot2F(int a, char A[6][7])
{
	int i;
	int j;
	
	while(a!=1)
	{
		printf("turno PLAYER 1\n");
		posizioniF(A,'O');
		mappaF(A);
		a=vittoriaF(A,'O');
		if(a==1)
		{
			printf("PLAYER 1 WIN!\n");
		}
		else
		{
			printf("turno BOT\n");
			
			for(i=0;i<6;i++)
			{
				for(j=0;j<7;j++)
				{
					
				}
			}
			posizionibotF(A,'X');
			mappaF(A);
			a=vittoriaF(A,'X');
			if(a==1)
			{
				printf("BOT WIN!\n");
			}
		}
		
	}
}

void posizionibotF(char A[6][7], int seme)
{
	int i;
	int colonna;
	int riga=5;
	srand(time(NULL));
	
	colonna=rand()%8;
	do
	{
		
		while(A[riga][colonna-1]!=' ')
		{
			riga--;
		}
		
		A[riga][colonna-1]=seme;
		
	}while(A[riga][colonna-1]==' ');
	
	printf("\n");
}
