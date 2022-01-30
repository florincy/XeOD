//Read, select and past program applied to get frequencies from .out file
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arq, *arqf;
    char Linha[100], metodo[100];
    char *result;
    char *v1, *v2, *v3, *shift, *Jconstant;
    int i;
    //Methods
    char v[35][10] = {"PBE", "BLYP", "BP86", "OLYP", "PW91", "mPW91", "revPBE", "TPSS","M06-L","M11-L","PBE0","B3LYP20","mPW1K","BHandHLYP","BHandH","SOGGA11-X","M06","M06-2X","M06-HF","BB1K","B1B95","mPWB1K","mPW1B95","PW6B95","M11","CAM-B3LYP","LC-BLYP","LC-PBE","LC-wPBE","LRC-wPBEh"};

    for (int i2 = 0; i2 < 32; i2++)
    {
        //Path by parts
        char caminho[100] = "/home/florincy/Documentos/nwchem/XeF4/";
        //Patern for naming files
        char arquivoout1[100] = "/XeF4_";
        char arquivoout2[100] = "_def2-SVP_opt_freq.out";
        printf("\nfoi!\n");
        strcpy(metodo, v[i2]);
        printf("\n%s\n", metodo);
        strcat(caminho, metodo);
        strcat(caminho, arquivoout1);
        strcat(caminho, metodo);
        strcat(caminho, arquivoout2);
        printf("\n%s", caminho);
        //Open the copy and past files
        arq = fopen(caminho, "r");
        arqf = fopen("/home/florincy/Documentos/nwchem/XeF4/FrequenciaXeF4.txt", "a");
        if (!arq)
        {
            printf("Problemas na CRIACAO do arquivo\n");
            return 0;
        }
        if (!arqf)
        {
            printf("Problemas na CRIACAO do arquivo\n");
            return 0;
        }
        i = 1;
        while (!feof(arq))
        {   //Search, copy and past
            // Lê uma linha (inclusive com o '\n')
            result = fgets(Linha, 100, arq); // o 'fgets' lê até 99 caracteres ou até o '\n'
            if (result)
            {
                v1 = strstr(result, "P.Frequency");

                if (v1)
                {
                    printf("\nLinha %d : %s", i, Linha);
                    fprintf(arqf, "\n...%s...\n", metodo);
                    fprintf(arqf, "%s\n", Linha);
                }

                i++;
            }
        }
    }
}