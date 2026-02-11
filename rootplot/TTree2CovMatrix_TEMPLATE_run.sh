#!/usr/bin/env bash
tags=(R1_CVFHC R2a_CVFHC)

File1=(R1_DetVarLYDown              R2a_DetVarLYDown)
File2=(R1_DetVarAlternativeSCMap    R2a_DetVarAlternativeSCMap)
File3=(R1_DetVarAlternativeRecombination R2a_DetVarAlternativeRecombination)
File4=(R1_DetVarLYRayleigh          R2a_DetVarLYRayleigh)
File5=(R1_DetVarWireModX            R2a_DetVarWireModX)
File6=(R1_DetVarWireModThetaXZ      R2a_DetVarWireModThetaXZ)
File7=(R1_DetVarWireModThetaYZ      R2a_DetVarWireModThetaYZ)
File8=(R1_DetVarWireModYZ           R2a_DetVarWireModYZ)


#tags=(R2a_CVFHC)
#File1=(R2a_DetVarLYDown)
#File2=(R2a_DetVarAlternativeSCMap)
#File3=(R2a_DetVarAlternativeRecombination)
#File4=(R2a_DetVarLYRayleigh)
#File5=(R2a_DetVarWireModX)
#File6=(R2a_DetVarWireModThetaXZ)
#File7=(R2a_DetVarWireModThetaYZ)
#File8=(R2a_DetVarWireModYZ)

template=TTree2CovMatrix_TEMPLATE.C

for i in "${!tags[@]}"; do

  echo -e "Processing tag: ${tags}\n"
  tag=${tags[i]}
  f1=${File1[i]}
  f2=${File2[i]}
  f3=${File3[i]}
  f4=${File4[i]}
  f5=${File5[i]}
  f6=${File6[i]}
  f7=${File7[i]}
  f8=${File8[i]}

  sed -e "s/TEMPLATE/${tag}/g" \
      -e "s/FLYD/${f1}/g" \
      -e "s/FASC/${f2}/g" \
      -e "s/FARECO/${f3}/g" \
      -e "s/FLYR/${f4}/g" \
      -e "s/FWMX/${f5}/g" \
      -e "s/FWMTXZ/${f6}/g" \
      -e "s/FWMTYZ/${f7}/g" \
      -e "s/FWMYZ/${f8}/g" \
      "$template" \
    > "TTree2CovMatrix_${tag}.C"

  root -l -b -q TTree2CovMatrix_${tag}.C
  echo "Save scripts!"
  mv TTree2CovMatrix_${tag}.C ./Saved_scripts
done
