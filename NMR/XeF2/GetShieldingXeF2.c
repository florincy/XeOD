//Read, select and past program applied to get xyz from .out file
#include <stdio.h>
#include <string.h>


int main()
{
    FILE *arq, *arqf;
    char Linha[100], metodo[100];
    char *result;
    char *v1;
    int i;
    int a, a1;
    a= 0;
    a1 = 0;
    //Methods
    char v[35][10] = {"PBE", "BLYP", "BP86", "OLYP", "PW91", "mPW91", "revPBE", "TPSS","M06-L","M11-L","PBE0","B3LYP","mPW1K","BHandHLYP","BHandH","SOGGA11-X","M06","M06-2X","M06-HF","BB1K","mPWB1K","mPW1B95","PW6B95","M11","CAM-B3LYP","LC-BLYP","LC-PBE","LC-wPBE","LRC-wPBEh"};

    for (int i2 = 0; i2 < 32; i2++)
    {
        //Path by parts
        char caminho[100] = "/home/florincy/Documentos/nwchem/NMR/XeF2/";
        //Patern for naming files
        char arquivoout1[100] = "/XeF2_";
        char arquivoout2[100] = "_SSB-D_SC-ZORA_NMR-ZORA.out";
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
        arqf = fopen("/home/florincy/Documentos/nwchem/NMR/XeF2/ShieldingXeF2.txt", "a");
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
        fprintf(arqf, "\n...%s...\n", metodo);
        while (!feof(arq))
        {  
            result = fgets(Linha, 100, arq);
            if (result){
            v1 = strstr(result, "Wrote CPHF data to ./molecule.shieldcphf");
            if (v1){
                a = i + 19;
                a1= a + 1;
            }
        }
        if (a < a1){
        printf("Copying...");
        if (i == a)
        {
            a++;
            fprintf(arqf, "%s\n", Linha);
        }
        }
        i++; 
        }
    }
}
    