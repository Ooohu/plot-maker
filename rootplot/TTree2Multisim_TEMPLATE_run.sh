#!/usr/bin/env bash

tags=(R1_CVFHC R2a_CVFHC)
NGe=(600 600)
NRe=(1000 1000)
NFl=(0 600)

#tags=(R2a_CVFHC)
#NGe=(10)
#NRe=(10)
#NFl=(10)

#tags=(R2b_CVRHC)
#NGe=(10)
#NRe=(10)
#NFl=(10)



template=TTree2Multisim_TEMPLATE.C

for i in "${!tags[@]}"; do

  echo -e "Processing tag: ${tags}\n"
  tag=${tags[i]}
  nge=${NGe[i]}
  nre=${NRe[i]}
  nfl=${NFl[i]}

  sed -e "s/TEMPLATE/${tag}/g" \
      -e "s/NGENIE/${nge}/g" \
      -e "s/NREINT/${nre}/g" \
      -e "s/NFLUX/${nfl}/g" \
      "$template" \
    > "TTree2Multisim_${tag}.C"
  
  out=TTree2Multisim_${tag}.C
  root -l -b -q ${out}
  echo "Save scripts! ${out}" 
  mv ${out} ./Saved_scripts
done
