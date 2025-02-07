set terminal qt size 800,600  # screen terminal 
set output

set title "Preys and predators over time"
set xlabel "Time"
set ylabel "Individuals"
plot "Species_log.txt" using 1:2 with lines title "Preys", \
     "Species_log.txt" using 1:3 with lines title "Predators"

pause mouse close # second graph, remains open