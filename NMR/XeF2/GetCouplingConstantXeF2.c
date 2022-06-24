// Read, select and past program applied to get xyz from .out file
#include <stdio.h>
#include <string.h>

int main() {
  FILE *arq, *arqf;
  char Linha[100], metodo[100], chave[100];
  char *result;
  char *v1;
  int i;
  int a, a1;
  a = 0;
  a1 = 0;
  // Methods
  char v[35][10] = {"PBE",       "BLYP",    "BP86",    "OLYP",      "PW91",
                    "mPW91",     "revPBE",  "TPSS",    "M06-L",     "M11-L",
                    "PBE0",      "B3LYP",   "mPW1K",   "BHandHLYP", "BHandH",
                    "SOGGA11-X", "M06",     "M06-2X",  "M06-HF",    "BB1K",
                    "mPWB1K",    "mPW1B95", "PW6B95",  "M11",       "CAM-B3LYP",
                    "LC-BLYP",   "LC-PBE",  "LC-wPBE", "LRC-wPBEh"};
  char busca[2][50] = {"Atom    1: 129-Xe and Atom    2:  19-F",
                       "Atom    1: 129-Xe and Atom    3:  19-F"};

  for (int i2 = 0; i2 < 32; i2++) {
    // Path by parts
    char caminho[100] = "/home/florincy/Documentos/nwchem/NMR/XeF2/";
    // Patern for naming files
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
    // Open the copy and past files
    arqf = fopen(
        "/home/florincy/Documentos/nwchem/NMR/XeF2/CouplingConstantXeF2.txt",
        "a");
    if (!arqf) {
      printf("Problemas na CRIACAO do arquivo\n");
      return 0;
    }
    fprintf(arqf, "\n...%s...\n", metodo);
    i = 0;
    for (int i3 = 0; i3 < 2; i3++) {
      arq = fopen(caminho, "r");
      if (!arq) {
        printf("Problemas na CRIACAO do arquivo\n");
        return 0;
      }
      while (!feof(arq)) {
        strcpy(chave, busca[i3]);
        result = fgets(Linha, 100, arq);
        if (result) {
          v1 = strstr(result, chave);
        }
        if (v1) {
          a = i + 41;
          a1 = a + 1;
          fprintf(arqf, "%s\n", Linha);
        }
        if (i == a) {
          fprintf(arqf, "%s\n", Linha);
        }
        i++;
      }
    }
  }
}
