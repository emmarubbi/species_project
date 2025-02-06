# Imposta il terminale per mostrare il grafico a schermo
set terminal qt size 800,600

# Titoli e etichette degli assi
set title "Data2 vs Data1"
set xlabel "Data1"
set ylabel "Data2"

# Plotta i dati: prima colonna (x) e seconda colonna (y)
plot "Species_log.txt" using 1:2 with lines title "Data2"

# Mantieni la finestra aperta finché l'utente non chiude
pause -1