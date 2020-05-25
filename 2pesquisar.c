#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

#define TAM 30690

int carrega_genoma();
int mostra_genomas();
int compara_genoma(char genomaa[TAM], char genomab[TAM]);
int exibe_resultado(int igual, int dif);
int compara_sequencia(char genomaa[TAM], char genomab[TAM]);
void inicializa_vetor();

double wtime_start;
double wtime_end;
double wtime;
int igual, dif;
char genoma0[TAM];
char genoma1[TAM];
char genoma2[TAM];
char genoma3[TAM];
char genoma4[TAM];
char genoma5[TAM];
char genoma6[TAM];
char genoma7[TAM];
char genoma8[TAM];
char genoma9[TAM];
int count = 0;

void main(void)
{

    omp_set_num_threads(4);

    wtime_start = omp_get_wtime();
    inicializa_vetor();
    carrega_genoma();
    mostra_genomas();

    char *array_gen[10] = {genoma0, genoma1, genoma2, genoma3, genoma4, genoma5, genoma6, genoma7, genoma8, genoma9};

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j <= 9; j++)
        {
            printf("\n \n Comparação e sequencia do genoma %d e do genoma %d ", i, j);
            compara_genoma(array_gen[i], array_gen[j]);
            compara_sequencia(array_gen[i], array_gen[j]);
        }
    }

    wtime_end = omp_get_wtime();
    wtime = wtime_end - wtime_start;
    printf("\n \n O tempo total da execução foi: %f  \n \n", wtime);
}
//funcao carrega genomas
//===============================================================
int carrega_genoma()
{

    int i = 0;
    char c;

    //genoma 1
    FILE *file1;

    //abre arquivo para leitura
    file1 = fopen("genomas/AY278741.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file1)) != EOF)
    { //le um nucleotideo do primeiro genoma enquanto não chegor ao final do arquivo

        genoma0[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file1);

    //-----------------------------
    //genoma 2
    FILE *file2;

    //abre arquivo para leitura
    file2 = fopen("genomas/KY417146.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;

    while ((c = getc(file2)) != EOF)
    {

        genoma1[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file2);

    //-----------------------------
    //genoma 3
    FILE *file3;

    //abre arquivo para leitura
    file3 = fopen("genomas/MK211376.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;

    while ((c = getc(file3)) != EOF)
    {

        genoma2[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file3);

    //-----------------------------
    //genoma 4
    FILE *file4;

    //abre arquivo para leitura
    file4 = fopen("genomas/MN908947.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file4)) != EOF)
    {

        genoma3[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file4);

    //-----------------------------
    //genoma 5
    FILE *file5;

    //abre arquivo para leitura
    file5 = fopen("genomas/MN996532.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file5)) != EOF)
    {

        genoma4[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file5);

    //-----------------------------
    //genoma 6
    FILE *file6;

    //abre arquivo para leitura
    file6 = fopen("genomas/USA-AZ1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file6)) != EOF)
    {

        genoma5[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file6);

    //-----------------------------
    //genoma 7
    FILE *file7;

    //abre arquivo para leitura
    file7 = fopen("genomas/USA-CA1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file7)) != EOF)
    {

        genoma6[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file7);

    //-----------------------------
    //genoma 8
    FILE *file8;

    //abre arquivo para leitura
    file8 = fopen("genomas/USA-IL1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file8)) != EOF)
    {

        genoma7[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file8);

    //-----------------------------
    //genoma 9
    FILE *file9;

    //abre arquivo para leitura
    file9 = fopen("genomas/USA-TX1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file9)) != EOF)
    {

        genoma8[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file9);

    //-----------------------------
    //genoma 9
    FILE *file10;

    //abre arquivo para leitura
    file10 = fopen("genomas/WHUHAN-WH04-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file9)) != EOF)
    {

        genoma9[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file10);
}

//funcao compara
//===============================================================
int compara_genoma(char genomaa[TAM], char genomab[TAM])
{
    int i = 0,
        x = 0;
    igual = 0;
    dif = 0;

    //#pragma omp parallel for private(i) reduction(+  : igual, dif)
    for (i = 0; i < TAM; i++)
    {
        if (genomaa[i] == '0' && genomab[i] == '0')
        {
            break;
        }
        else
        {

            if (genomaa[i] == genomab[i])
            { //compara os dois nucleotideos
                igual++;
            }
            else
            {
                dif++;
                //scanf("%d", &x);
                // sleep(1);
            }
        }
    }
    count++;
    printf("\n Comparação número: %d ", count);
    //printf("\n \n Resultado da comparação do Genoma 1 e 2");
    exibe_resultado(igual, dif);
}
//mostra os genomas
//==============================
int mostra_genomas()
{
    int i = 0;

    for (i = 0; i < TAM; i++)
    {

        printf("\n | %5d  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | ", i,
               genoma0[i], genoma1[i], genoma2[i], genoma3[i], genoma4[i], genoma5[i], genoma6[i],
               genoma7[i], genoma8[i], genoma9[i]);
    }
}

//exibe resultado
//===============================================================
int exibe_resultado(int igual, int dif)
{

    printf("\n\n | Iguais %-18d \n | Diferentes %-18d ", igual, dif);

    printf("\n\n");
}

//funcao compara sequancia
//===============================================================
int compara_sequencia(char genomaa[TAM], char genomab[TAM])
{

    int i = 0,
        j = 0,
        igual = 0,
        inicio = 0,
        qtde = 0;

    for (i = 0, j = 0; i < TAM; i++, j++)
    {
        if (genomaa[i] == '0' && genomab[j] == '0')
        {
            break;
        }
        else
        {
            if (genomaa[i] == genomab[j])
            {
                igual++;
            }
            else
            {

                if (igual > qtde)
                {

                    qtde = igual;
                    inicio = i - qtde;
                    igual = 0;

                    printf("\n i = %-8d | inicio = %-8d | qtde = %-8d | ", i, inicio, qtde);
                }
            }
        }
    }
    printf("\n\n");
}

void inicializa_vetor()
{
    for (int i = 0; i <= TAM; i++)
    {
        genoma0[i] = '0';
        genoma1[i] = '0';
        genoma2[i] = '0';
        genoma3[i] = '0';
        genoma4[i] = '0';
        genoma5[i] = '0';
        genoma6[i] = '0';
        genoma7[i] = '0';
        genoma8[i] = '0';
        genoma9[i] = '0';
    }
}
