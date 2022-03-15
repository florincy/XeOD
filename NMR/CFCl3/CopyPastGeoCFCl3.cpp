#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  std::vector<std::string> vecOfStr;
  int position, position2;
  string caminhoIn, caminhoOut, line, line2;
  char metodo[100];
  char *v1;
  char v[35][10] = {
      "PBE",    "BLYP",      "BP86",    "B3LYP",     "OLYP",    "PW91",
      "mPW91",  "revPBE",    "TPSS",    "M06-L",     "M11-L",   "PBE0",
      "mPW1K",  "BHandHLYP", "BHandH",  "SOGGA11-X", "M06",     "M06-2X",
      "M06-HF", "BB1K",      "B1B95",   "mPWB1K",    "mPW1B95", "PW6B95",
      "M11",    "CAM-B3LYP", "LC-BLYP", "LC-PBE",    "LC-wPBE", "LRC-wPBEh"};
  string arquivoout1 = "/CFCl3_";
  string arquivoout2 = "_def2-SVP_opt_freq.out";
  string arquivoout3 = "_SSB-D_SC-ZORA_NMR-ZORA.nw";
  for (int i2 = 0; i2 < 32; i2++) {
    caminhoOut = "/home/florincy/Documentos/nwchem/CFCl3/";
    caminhoIn = "/home/florincy/Documentos/nwchem/NMR/CFCl3/";
    strcpy(metodo, v[i2]);
    string methS(metodo);
    caminhoOut = caminhoOut + methS + arquivoout1 + methS + arquivoout2;
    caminhoIn = caminhoIn + methS + arquivoout1 + methS + arquivoout3;
    // cout << caminhoOut << endl;
    // cout << caminhoIn << endl;
    fstream arqCopy(caminhoOut.c_str());
    fstream arqPast(caminhoIn.c_str());
    if (arqCopy.is_open() && arqPast.is_open()) {
      while (getline(arqCopy, line)) {
        if (line.find("Optimization converged") != string::npos) {
          while (getline(arqPast, line2)) {
            if (line2.find("geometry units angstroms print xyz autosym") !=
                string::npos) {
              position = arqPast.tellg();
              arqPast.seekg(position);
            }
            cout << position;
          }
        }
        arqPast.close();
      }
      arqCopy.close();
    }
  }
}
