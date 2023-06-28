### 2D density color plot
set terminal png size 500,500
set output 'scatter.png'

t1 = time(0.0)
# create some random rest data
set table $Data
    set samples 10
    plot '+' u (invnorm(rand(0))):(invnorm(rand(0))) w table
    set samples 10
    plot '+' u (invnorm(rand(0))+2):(invnorm(rand(0))+2) w table
unset table
print sprintf("Time data creation: %.3f s",(t0=t1,t1=time(0.0),t1-t0))

# for each datapoint: how many other datapoints are within radius R
R = 0.5     # Radius to check
Dist(x0,y0,x1,y1) = sqrt((x1-x0)**2 + (y1-y0)**2)

set print $Density
    do for [i=1:|$Data|] {
        x0 = real(word($Data[i],1))
        y0 = real(word($Data[i],2))
        c  = 0
        stats $Data u (Dist(x0,y0,$1,$2)<=R ? c=c+1 : 0) nooutput
        d = c / (pi * R**2)             # density: points per unit area
        print sprintf("%g %g %d", x0, y0, d)
    }
set print
print sprintf("Time density check: %.3f sec",(t0=t1,t1=time(0.0),t1-t0))

set size ratio -1   # same screen units for x and y
set palette rgb 33,13,10
plot $Density u 1:2:3 w p pt 7 lc palette z notitle
### end of script
