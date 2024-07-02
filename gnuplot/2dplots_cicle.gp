# Read title from text file
title_file = '2dplots_cicle.legend'
title = system('cat '.title_file)

# Set the terminal to whatever you prefer, for example, PNG
set terminal pngcairo enhanced font 'Verdana,12'
set output 'scatter_plot.png'

# Set axis labels
set xlabel 'X'
set ylabel 'Y'

# Set integer tics on both axes
set xtics 1
set ytics 1

# Set axis range
set xrange [0:5]
set yrange [0:5]

# Set plot title
set title 'Reconstruction Efficiency'

# Plot the data using circles
plot '2dplots_cicle.dat' using 1:2:3 with circles lc rgb 'blue' title title, \
     '' using 1:2:(sprintf("%.2f%%",$3*100)) with labels offset 0,0.5 font 'Verdana,8' notitle
