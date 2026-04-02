#!/usr/bin/env bash

#tags=(Run1FHCAll Run2MCFHCAll Run2RHCAll Run3bRHCAll Run4bRHCAll Run4cFHCAll Run5FHCAll)
#NGe=(10 10 10 10 10 10 10)
#NRe=(10 10 10 10 10 10 10)
#NFl=(6 6 6 6 6 6 6)
#NRe=(0 0 0 0 0 0 0)
#NFl=(0 0 0 0 0 0 0)
#
tags=(AllMC Run1FHCAll Run2MCFHCAll Run2RHCAll Run3bRHCAll Run4bRHCAll Run4cFHCAll Run5FHCAll)
NGe=(600 600 600 600 600 600 600 600)
NRe=(1000 1000 1000 1000 1000 1000 1000 1000)
NFl=(600 600 600 600 600 600 600 600)


#tags=(Run4bRHCAll)
#NGe=(6)
#NRe=(10)
#NFl=(10)



template=TTree2Multisim_TEMPLATE.C

for i in "${!tags[@]}"; do

  echo -e "Processing tag: ${tags}\n"
  tag=${tags[i]}
  nge=${NGe[i]}
  nre=${NRe[i]}
  nfl=${NFl[i]}
  out=TTree2Multisim_${tag}.C

  sed -e "s/TEMPLATE/${tag}/g" \
      -e "s/NGENIE/${nge}/g" \
      -e "s/NREINT/${nre}/g" \
      -e "s/NFLUX/${nfl}/g" \
      "$template" \
     > "${out}"

  root -l -b -q ${out}
  echo "Save scripts! ${out}" 
  mv ${out} ./Saved_scripts
done
