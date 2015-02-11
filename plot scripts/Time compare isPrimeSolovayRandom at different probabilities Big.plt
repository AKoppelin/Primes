filename(n) = sprintf("TimeMeasurements_%s.dat", title_label(n))
title_label(n) = (n==1) ? "isPrimeSolovayRandomPrimesBig50" : (n==2) ? "isPrimeSolovayRandomPrimesBig75" : (n==3) ? "isPrimeSolovayRandomPrimesBig99" : (n==4) ? "isPrimeSolovayRandomPrimesBig100" : "NOT_IMPLEMENTED"

# number of implementations
n = 4
set title "Function 'isPrimeSolovayRandom' at propabilities 0.5, 0.75, 0.9999 and 1.0 (big primes only)"
set key outside #Legende auﬂerhalb
set style fill transparent solid 0.3
set xlabel "n"
set ylabel "running time [us]"
#set yrange [0:2000]
#plot for [i = 1:n] filename(i) using 1:($2):($3) title '' with filledcurve lt i, \
#						for[i = 1:n] filename(i) using 1:($4) title title_label(i) with lines lt i lw 2
plot for[i = 1:n] filename(i) using 1:($4) title title_label(i) with lines lt i lw 2
pause -1
