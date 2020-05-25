#include <stdio.h>

#define L 10
#define C 10

int m1[C][L], m2[C][L];

void inicializa_matriz();
void mostra_matriz();

int main(int argc, char *argv[])
{

	inicializa_matriz();

	mostra_matriz();

}


 

void mostra_matriz()
{
        int z, v;
        printf("\n  M A T R I Z \n");

        printf("\n  M.1 \n");
        for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf("  %3.2d", m1[z][v]);
		}
        	printf("\n");
	}
	printf("\n\n\n");
	
        printf("\n  M.2 \n");
	for (z=0; z < L; z ++){
		for (v=0; v < C; v++) {
        	        printf("  %3.3d", m2[z][v]);
		}
        	printf("\n");
	}
}
 

void inicializa_matriz()
{
        int z, v;
        printf("\n inicializando matrizes ...\n");
        for (z=0; z < L; z ++)
		for (v=0; v < C; v++){
			m1[z][v] = 30000;
			m2[z][v] = 0;
		}
}


