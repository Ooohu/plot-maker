reset
# output info
set terminal png size 500,500
set output 'simpleHist.png'


set key off    # legend off
set border 3   # thin border

# Add a vertical dotted line at x=0 to show centre (mean) of distribution.
set yzeroaxis

bin_width = 1; #Varaibles 

# Each bar is half the (visual) width of its x-range.
set boxwidth bin_width absolute
set style fill solid 1.0 noborder


rounded(x) = bin_width * ( floor(x/bin_width) + 0.5 )

plot 'run1_NuMI_beamoff_pelee_subset.txt' using (rounded($1)):(1) smooth frequency with boxes # draw 1st column

# table version of the histogram
set table 'simpleHist.record'
    plot 'input.txt' using (rounded($1)):(1) smooth frequency with boxes # draw 1st column
unset table
