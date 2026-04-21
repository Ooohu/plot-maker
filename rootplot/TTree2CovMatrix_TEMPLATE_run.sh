#!/usr/bin/env bash
mtags=(ma0146 ma03 ma003 ma084)

tags=(CV_2s0t_6runs)
#tags=(CV_2s0t_6runs R1_DetVarCV R2a_CVFHCOLD R2b_CVRHCOLD R3b_CV R4_CV R5_CV)

File1=(DetVarLYDown_2s0t_6runs				R1_DetVarLYDown						R2a_DetVarLYDown					R2b_DetVarLYDown					R3b_DetVarLYDown						R4_DetVarLYDown						R5_DetVarLYDown					)
File1a=(DetVarAttenuation_2s0t_5runs		R1_DetVarCV						R2a_DetVarAttenuation					R2b_DetVarAttenuation					R3b_DetVarAttenuation						R4_DetVarAttenuation						R5_DetVarAttenuation					)
File2=(DetVarAlternativeSCMap_2s0t_5runs	R1_DetVarAlternativeSCMap			R2a_DetVarAlternativeSCMap			R2b_DetVarAlternativeSCMap			R3b_DetVarAlternativeSCMap				R4_DetVarAlternativeSCMap			R5_DetVarAlternativeSCMap			)
File3=(DetVarAlternativeRecombination_2s0t_4runs R1_DetVarAlternativeRecombination	R2a_DetVarAlternativeRecombination	R2b_CVRHCOLD	R3b_DetVarAlternativeRecombination		R4_DetVarAlternativeRecombination	R5_DetVarAlternativeRecombination	)
#File3=(R1_DetVarAlternativeRecombination	R2a_DetVarAlternativeRecombination	R2b_DetVarAlternativeRecombination	R3b_DetVarAlternativeRecombination		R4_DetVarAlternativeRecombination	R5_DetVarAlternativeRecombination	)
File4=(DetVarLYRayleigh_2s0t_6runs			R1_DetVarLYRayleigh					R2a_DetVarLYRayleigh				R2b_DetVarLYRayleigh				R3b_DetVarLYRayleigh					R4_DetVarLYRayleigh					R5_DetVarLYRayleigh				)
File5=(DetVarWireModX_2s0t_6runs			R1_DetVarWireModX            		R2a_DetVarWireModX					R2b_DetVarWireModX					R3b_DetVarWireModX						R4_DetVarWireModX					R5_DetVarWireModX					)
File6=(DetVarWireModThetaXZ_2s0t_6runs		R1_DetVarWireModThetaXZ      		R2a_DetVarWireModThetaXZ			R2b_DetVarWireModThetaXZ			R3b_DetVarWireModThetaXZ				R4_DetVarWireModThetaXZ				R5_DetVarWireModThetaXZ			)
File7=(DetVarWireModThetaYZ_2s0t_6runs		R1_DetVarWireModThetaYZ      		R2a_DetVarWireModThetaYZ			R2b_DetVarWireModThetaYZ			R3b_DetVarWireModThetaYZ				R4_DetVarWireModThetaYZ				R5_DetVarWireModThetaYZ			)
File8=(DetVarWireModYZ_2s0t_6runs			R1_DetVarWireModYZ           		R2a_DetVarWireModYZ					R2b_DetVarWireModYZ					R3b_DetVarWireModYZ						R4_DetVarWireModYZ					R5_DetVarWireModYZ					)


#tags=(R5_CV)
#File1=(R5_DetVarLYDown						)
#File1a=(R5_DetVarAttenuation						)
#File2=(R5_DetVarAlternativeSCMap			)
#File3=(R5_DetVarAlternativeRecombination	)
#File4=(R5_DetVarLYRayleigh					)
#File5=(R5_DetVarWireModX					)
#File6=(R5_DetVarWireModThetaXZ				)
#File7=(R5_DetVarWireModThetaYZ				)
#File8=(R5_DetVarWireModYZ					)

template=TTree2CovMatrix_TEMPLATE.C

for i in "${!tags[@]}"; do

  echo -e "Processing tag: ${tags[i]}\n"
  mtag=${mtags[0]}
  tag=${tags[i]}
  f1=${File1[i]}
  f1a=${File1a[i]}
  f2=${File2[i]}
  f3=${File3[i]}
  f4=${File4[i]}
  f5=${File5[i]}
  f6=${File6[i]}
  f7=${File7[i]}
  f8=${File8[i]}
  out=TTree2CovMatrix_${tag}.C

  sed -e "s/MASSTAG/${mtag}/g" \
	  -e "s/TEMPLATE/${tag}/g" \
	  -e "s/FATTN/${f1a}/g" \
      -e "s/FLYD/${f1}/g" \
      -e "s/FASC/${f2}/g" \
      -e "s/FARECO/${f3}/g" \
      -e "s/FLYR/${f4}/g" \
      -e "s/FWMX/${f5}/g" \
      -e "s/FWMTXZ/${f6}/g" \
      -e "s/FWMTYZ/${f7}/g" \
      -e "s/FWMYZ/${f8}/g" \
      "$template" \
    > "${out}"

  root -l -b -q ${out}
  echo "Save scripts! ${out}" 
  mv ${out} ./Saved_scripts
done
