set terminal png size 500,500
set output 'hist_output.png'

set boxwidth 0.5 absolute 

plot 'hist_input.txt' using 1:2 with boxes
