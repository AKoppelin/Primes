filename(n) = sprintf("CycleMeasurements_%s.dat", title_label(n))
title_label(n) = (n==1) ? "isPrime" : (n==2) ? "isPrimeSolovayRandomPrimes50" : (n==3) ? "isPrimeSolovayPrimes50" : (n==4) ? "isPrimeFermatRandomPrimes50" : (n==5) ? "isPrimeSolovayGMPPrimes50" : (n==6) ? "isPrimeSolovayPrime50" : "NOT_IMPLEMENTED"

# number of implementations
n = 6
set title "Computing prime numbers at probability 0.5"
set key outside #Legende auﬂerhalb
set style fill transparent solid 0.3
set xlabel "n"
set ylabel "Cycles"
#set yrange [0:2000]
#plot for [i = 1:n] filename(i) using 1:($2):($3) title '' with filledcurve lt i, \
#						for[i = 1:n] filename(i) using 1:($4) title title_label(i) with lines lt i lw 2
plot for[i = 1:n] filename(i) using 1:($4) title title_label(i) with lines lt i lw 2
pause -1
