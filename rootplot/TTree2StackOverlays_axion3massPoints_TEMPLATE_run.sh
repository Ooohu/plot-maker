#!/usr/bin/env bash
mtags=(ma0093 ma011 ma0146 ma03 ma04 ma052 ma068 ma084 ma003)
#mtags=(ma0093 ma0146 ma084)

tags=(Run1FHC run2MCFHC Run2RHC Run3RHC         )
Costags=(Run1EXT Run2aEXT Run2bEXT Run3Pre16880EXT)
dtags=(Run1FHC Run2aFHC Run2bRHC Run3Pre16880RHC )

#tags=(Run1FHC run2MCFHC Run2RHC Run3RHC         run4bMC  run4cMC  run5MC)
#Costags=(Run1EXT Run2aEXT Run2bEXT Run3Pre16880EXT Run4bEXT Run4cEXT Run5EXT)
#dtags=(Run1FHC Run2aFHC Run2bRHC Run3Pre16880RHC Run4bRHC Run4cFHC Run5FHC)

#Costags=(JumboEXT JumboEXT JumboEXT JumboEXT JumboEXT JumboEXT JumboEXT)

#tags=(Run1FHC)
#Costags=(Run1EXT)
#dtags=(Run1FHC)

template=TTree2StackOverlays_axion3massPoints_TEMPLATE.C

for i in "${!tags[@]}"; do

  mtag=${mtags[3]}
  tag=${tags[i]}
  dtag=${dtags[i]}
  costag=${Costags[i]}
  out=TTree2StackOverlays_axion3massPoints_${tag}.C


  echo -e "Processing mass: ${mtag} tag: ${tag}\n"

  sed -e "s/MASSTAG/${mtag}/g" \
      -e "s/TEMPLATE/${tag}/g" \
      -e "s/ETAG/${costag}/g" \
      -e "s/dTAG/${dtag}/g" \
      "$template" \
    > "${out}"

  root -l -b -q ${out}
  echo "Save scripts! ${out}" 
  mv ${out} ./Saved_scripts
done
