#!/usr/bin/env bash

tags=(Run1FHC run2MCFHC Run2RHC Run3RHC         run4bMC  run4cMC  run5MC)
Costags=(Run1EXT Run2aEXT Run2bEXT Run3Pre16880EXT Run4bEXT Run4cEXT Run5EXT)
dtags=(Run1FHC Run2aFHC Run2bRHC Run3Pre16880RHC Run4bRHC Run4cFHC Run5FHC)

#Costags=(JumboEXT JumboEXT JumboEXT JumboEXT JumboEXT JumboEXT JumboEXT)

#tags=(Run3RHC)
#Costags=(Run3Pre16880EXT)
#dtags=(Run3Pre16880RHC)

template=TTree2StackOverlays_axion3massPoints_TEMPLATE.C

for i in "${!tags[@]}"; do

  echo -e "Processing tag: ${tags}\n"
  tag=${tags[i]}
  dtag=${dtags[i]}
  costag=${Costags[i]}
  out=TTree2StackOverlays_axion3massPoints_${tag}.C

  sed -e "s/TEMPLATE/${tag}/g" \
      -e "s/ETAG/${costag}/g" \
      -e "s/dTAG/${dtag}/g" \
      "$template" \
    > "${out}"

  root -l -b -q ${out}
  echo "Save scripts! ${out}" 
  mv ${out} ./Saved_scripts
done
