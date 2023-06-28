set terminal png size 500,500
set output '2dhist_output.png'

set view map
splot '2dhist_input.txt' matrix with image
