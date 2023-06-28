# Set outputs
set terminal png size 500,500
set output 'twodhist.png'

set view map
set dgrid3d
splot "input.txt" using 1:2:3 with pm3d
