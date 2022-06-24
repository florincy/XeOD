#!/bin/bash
Methods=('BLYP' 'BP86' 'OLYP' 'PW91' 'mPW91' 'revPBE' 'TPSS' 'M06-L' 'M11-L' 'PBE0' 'B3LYP' 'mPW1K' 'BHandHLYP' 'BHandH' 'SOGGA11-X' 'M06' 'M06-2X' 'M06-HF' 'BB1K' 'mPWB1K' 'mPW1B95' 'PW6B95' 'M11' 'CAM-B3LYP' 'LC-BLYP' 'LC-PBE' 'LC-wPBE' 'LRC-wPBEh')
echo "Lets start some calculations?"
read -p "Molecule formula : " molecule
read -p "Is it NMR?(Y/N)" Anwser
if [ "$Anwser" = "Y" ]; then
  directory="/home/florincy/Documentos/nwchem/NMR/${molecule}/"
  StandardNomenclatureIn="_SSB-D_SC-ZORA_NMR-ZORA.nw"
  StandardNomenclatureOut="_SSB-D_SC-ZORA_NMR-ZORA.out"
else
  directory="/home/florincy/Documentos/nwchem/${molecule}/"
  StandardNomenclatureIn="_def2-SVP_opt_freq.nw"
  StandardNomenclatureOut="_def2-SVP_opt_freq.out"
fi
echo "$directory"
for i in ${!Methods[@]}; do
  echo "element $i is ${Methods[$i]}"
  Method=${Methods[i]}
  inputNWCHEM="${molecule}_${Method}${StandardNomenclatureIn}"
  OutputNWCHEM="${molecule}_${Method}${StandardNomenclatureOut}"
  directory2="${directory}${Method}"
  echo $inputNWCHEM
  echo $OutputNWCHEM
  cd ${directory2}
  ls
  mpirun -np 2 /scr/programas/nwchem-7.0.2/bin/LINUX64/nwchem ${inputNWCHEM} >${OutputNWCHEM} &
  wait
done
