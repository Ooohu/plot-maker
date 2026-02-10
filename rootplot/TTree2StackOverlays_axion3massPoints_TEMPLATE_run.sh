#!/usr/bin/env bash
#tags=(Run1FHC)

tags=(run2MCFHC)
dtags=(Run2aFHC)

template=TTree2StackOverlays_axion3massPoints_TEMPLATE.C

for i in "${!tags[@]}"; do

  echo -e "Processing tag: ${tags}\n"
  tag=${tags[i]}
  dtag=${dtags[i]}

  sed -e "s/TEMPLATE/${tag}/g" \
      -e "s/dTAG/${dtag}/g" \
      "$template" \
    > "TTree2StackOverlays_axion3massPoints_${tag}.C"

  root -l -b -q TTree2StackOverlays_axion3massPoints_${tag}.C
  echo "Save scripts!"
  mv TTree2StackOverlays_axion3massPoints_${tag}.C ./Saved_scripts
done
