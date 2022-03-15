// Read, select and past program applied to get xyz from .out file
#include <stdio.h>
#include <string.h>
int main() {
  FILE *arq, *arqf;
  char Linha[100], metodo[100];
  char *result;
  char *v1, *v2, *v3, *shift, *Jconstant;
  int i;
  int a, a1, a2;
  a = 0;
  a1 = 0;
  // Methods
  char v[35][10] = {
      "PBE",    "BLYP",      "BP86",    "B3LYP",     "OLYP",    "PW91",
      "mPW91",  "revPBE",    "TPSS",    "M06-L",     "M11-L",   "PBE0",
      "mPW1K",  "BHandHLYP", "BHandH",  "SOGGA11-X", "M06",     "M06-2X",
      "M06-HF", "BB1K",      "B1B95",   "mPWB1K",    "mPW1B95", "PW6B95",
      "M11",    "CAM-B3LYP", "LC-BLYP", "LC-PBE",    "LC-wPBE", "LRC-wPBEh"};

  for (int i2 = 0; i2 < 32; i2++) {
    // Path by parts
    char caminho [100]= "/home/florincy/Documentos/nwchem/CFCl3/";
    char caminhoIn [100] = "/home/florincy/Documentos/nwchem/NMR/CFCl3/";
    // Patern for naming files
    char arquivoout1 [100] = "/CFCl3_";
    char arquivoout2 [100] = "_def2-SVP_opt_freq.out";
    char arquivoout3 [100]= "_SSB-D_SC-ZORA_NMR-ZORA.nw";
    printf("\nfoi!\n");
    strcpy(metodo, v[i2]);
    printf("\n%s\n", metodo);
    strcat(caminho, metodo);
    strcat(caminho, arquivoout1);
    strcat(caminho, metodo);
    strcat(caminho, arquivoout2);
    strcat(caminhoIn, metodo);
    strcat(caminhoIn, arquivoout1);
    strcat(caminhoIn, metodo);
    strcat(caminhoIn, arquivoout3);
    printf("\n%s", caminhoIn);
    // Open the copy and past files
    // ifstream infile(caminho.c_str());
    arq = fopen(caminho, "r");
    arqf = fopen(caminhoIn, "a");
    if (!arq) {
      printf("Problemas na CRIACAO do arquivo\n");
      return 0;
    }
    if (!arqf) {
      printf("Problemas na CRIACAO do arquivo\n");
      return 0;
    }
    i = 1;
    fprintf(arqf, "...%s...\n", metodo);
    while (!feof(arq)) {
      result = fgets(Linha, 100, arq);
      if (result) {
        v1 = strstr(result, "Optimization converged");
        if (v1) {
          a = i + 36;
          a1 = a + 8;
        }
      }
      if (a < a1) {
        printf("Copying...");
        if (i == a) {
          result2 = fgets(Linha, 100, arqf);
          if (result2) {
            v1 = strstr(result2, "geometry units angstroms print xyz autosym");
            int position = arqPast.tellg();
            fprintf(arqf, "%s\n", Linha);
          }
          a++;
        }
      }
      i++;
    }
  }
}
