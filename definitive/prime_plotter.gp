set terminal qt size 800,600  # screen terminal 
set output 

print "Contenuto del file Species_log.txt:"
system "cat Species_log.txt"
set title "Prime integral over time"
set xlabel "Time"
set ylabel "Prime integral"
stats "Species_log.txt" using 4 nooutput  # statistics on prime integral, necessary for rescaling
max_value = STATS_max  
set yrange [0:max_value+0.1]
plot "Species_log.txt" using 1:4 with lines title "Prime integral" 

pause mouse close  # first graph, remains open

