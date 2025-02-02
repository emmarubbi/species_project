# output settings
set terminal qt size 800,600
set output

set title "Preys, predators and prime integral graph"
set xlabel "Time"
set ylabel ""

set grid
set key outside

plot "species_log.txt" using 1:2 with lines title "Preys", \
     "species_log.txt" using 1:3 with lines title "Predators", \
     "species_log.txt" using 1:4 with lines title "Prime integral"

pause -1