filename(n) = sprintf("TimeMeasurements_%s.dat", title_label(n))
title_label(n) = (n==1) ? "isPrime" : (n==2) ? "isPrimeFermatRandom100WithChoosablePrecisionPrimes150" : (n==3) ? "isPrimeFermatRandomImprovedPrimes100" : (n==4) ? "isPrimeFermatRandomPrimes100" : (n==5) ? "isPrimeSolovayGMPPrimes100" : (n==6) ? "isPrimeSolovayPrime100" : (n==7) ? "isPrimeSolovayRandomPrimes100" : "NOT_IMPLEMENTED"

# number of implementations
n = 7
set title "Computing prime numbers at probability 1.0"
set key outside #Legende auﬂerhalb
set style fill transparent solid 0.3
set xlabel "n"
set ylabel "running time [us]"
#set yrange [0:2000]
#plot for [i = 1:n] filename(i) using 1:($2):($3) title '' with filledcurve lt i, \
#						for[i = 1:n] filename(i) using 1:($4) title title_label(i) with lines lt i lw 2
plot for[i = 1:n] filename(i) using 1:($4) title title_label(i) with lines lt i lw 2
pause -1
