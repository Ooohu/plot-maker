#!/usr/bin/env bash
#tags=(Run1FHC)

#tags=(R1_CVFHC)
#NGe=(2)
#NRe=(2)
#NFl=(0)

tags=(R2a_CVFHC)
NGe=(10)
NRe=(10)
NFl=(10)


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

  root -l -b -q TTree2Multisim_${tag}.C
  echo "Save scripts!"
  mv TTree2Multisim_${tag}.C ./Saved_scripts
done
