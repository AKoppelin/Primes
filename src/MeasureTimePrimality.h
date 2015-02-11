#include "Meter.h"

#ifndef MIN_ODD
#define MIN_ODD 1
#endif

#ifndef MAX_ODD
#define MAX_ODD 100000
#endif

Meter meterTime = Meter();
cout << "Starting time measurements of primality tests ..." << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                                  Naive primality test
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrime'." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&>(primes[i], 10, "isPrime", isPrime, primes[i]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                        Fermat's primality test (prime numbers only)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeFermat' (prime numbers only, 1 iteration)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, size_t>(primes[i], 10, "isPrimeFermatPrimes1Iteration", isPrimeFermat, primes[i], 1);
}
cout << "Measuring function 'isPrimeFermat' (prime numbers only, 54 iterations)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, size_t>(primes[i], 10, "isPrimeFermatPrimes54Iterations", isPrimeFermat, primes[i], 54);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.5 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeFermatRandomPrimes50", isPrimeFermatRandom, primes[i], 0.5);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.75 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeFermatRandomPrimes75", isPrimeFermatRandom, primes[i], 0.75);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 1.0 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeFermatRandomPrimes100", isPrimeFermatRandom, primes[i], 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Fermat's primality test (odd numbers)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.5 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomOdds50", isPrimeFermatRandom, i, 0.5);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.75 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomOdds75", isPrimeFermatRandom, i, 0.75);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 1.0 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomOdds100", isPrimeFermatRandom, i, 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                  Fermat's primality test with high floating point precision
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeFermatRandomWithChoosablePrecision' with probability of 1.0 (prime numbers only, floating point precision of 150)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
    mpf_class probability(1.0);
	meterTime.measureTime<bool, size_t&, mpf_class, size_t>(primes[i], 10, "isPrimeFermatRandom100WithChoosablePrecisionPrimes150", isPrimeFermatRandomWithChoosablePrecision, primes[i], 1.0, 150);
}
cout << "Measuring function 'isPrimeFermatRandomWithChoosablePrecision' with probability of 1.0 (odd numbers, floating precision of 150)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
    mpf_class probability(1.0);
	meterTime.measureTime<bool, size_t&, mpf_class, size_t>(i, 10, "isPrimeFermatRandom100WithChoosablePrecisionOdds150", isPrimeFermatRandomWithChoosablePrecision, i, 1.0, 150);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                              Fermat's primality test with (improved)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeFermatRandomImproved' with probability of 1.0 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
    mpf_class probability(1.0);
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeFermatRandomImprovedPrimes100", isPrimeFermatRandomImproved, primes[i], 1.0);
}
cout << "Measuring function 'isPrimeFermatRandomImproved' with probability of 1.0 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
    mpf_class probability(1.0);
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomImprovedOdds100", isPrimeFermatRandomImproved, i, 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      Solovay-Strassen with different probabilities (prime numbers only), no random numbers
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovay' with probability of 0.5 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayPrimes50", isPrimeSolovay, primes[i], 0.5);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.75 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayPrimes75", isPrimeSolovay, primes[i], 0.75);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.9999 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayPrime99", isPrimeSolovay, primes[i], 0.9999);;
}
cout << "Measuring function 'isPrimeSolovay' with probability of 1 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayPrime100", isPrimeSolovay, primes[i], 1.0);;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                          Solovay-Strassen with different probabilities (odd numbers), no random numbers
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovay' with probability of 0.5 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds50", isPrimeSolovay, i, 0.5);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.75 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds75", isPrimeSolovay, i, 0.75);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.9999 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds99", isPrimeSolovay, i, 0.9999);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 1 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds100", isPrimeSolovay, i, 1.0);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Solovay-Strassen for comparing the self-implemented GCD-algorithm with the GMP library's and the C++ random number
//    generator with the GMP library's.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovay' with probability of 1 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
    mpz_class n(i);
	meterTime.measureTime<bool, mpz_class&, long double>(primes[i], 10, "isPrimeSolovayPrimes100", isPrimeSolovay, n, 1.0);
}
cout << "Measuring function 'isPrimeSolovayGMP' with probability of 1 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
    mpz_class n(i);
	meterTime.measureTime<bool, mpz_class&, long double>(primes[i], 10, "isPrimeSolovayGMPPrimes100", isPrimeSolovayGMP, n, 1.0);
}
cout << "Measuring function 'isPrimeSolovayRandom' with probability of 1 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
    mpz_class n(i);
	meterTime.measureTime<bool, mpz_class&, long double>(primes[i], 10, "isPrimeSolovayRandomPrimes100", isPrimeSolovayRandom, n, 1.0);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 1 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
    mpz_class n(i);
	meterTime.measureTime<bool, mpz_class&, long double>(primes[i], 10, "isPrimeSolovayRandomGMPPrimes100", isPrimeSolovayRandom, n, 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Solovay-Strassen with different probabilities (prime numbers only), random numbers with standard C++ function
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovayRandom' with probability of 0.5 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++ ) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayRandomPrimes50", isPrimeSolovayRandom, primes[i], 0.5);
}
cout << "Measuring function 'isPrimeSolovayRandom' with probability of 0.75 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayRandomPrimes75", isPrimeSolovayRandom, primes[i], 0.75);
}
cout << "Measuring function 'isPrimeSolovayRandom' with probability of 0.9999 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayRandomPrimes99", isPrimeSolovayRandom, primes[i], 0.9999);
}
cout << "Measuring function 'isPrimeSolovayRandom' with probability of 1 (prime numbers only)." << endl;
for (unsigned int i = 0; i < primes.size(); i++) {
	meterTime.measureTime<bool, size_t&, long double>(primes[i], 10, "isPrimeSolovayRandomPrimes100", isPrimeSolovayRandom, primes[i], 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Solovay-Strassen with different probabilities (odd numbers), using random number algorithm of the GMP library
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.5 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPOdds50", isPrimeSolovayRandomGMP, i, 0.5);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.75 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPOdds75", isPrimeSolovayRandomGMP, i, 0.75);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.9999 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPOdds99", isPrimeSolovayRandomGMP, i, 0.9999);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 1 (odd numbers)." << endl;
for (size_t i = MIN_ODD; i < MAX_ODD; i += 2) {
	meterTime.measureTime<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPOdds100", isPrimeSolovayRandomGMP, i, 1.0);
}
cout << "Finished time measurements of primality tests." << endl << endl;
