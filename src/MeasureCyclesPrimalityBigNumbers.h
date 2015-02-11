#include "Meter.h"

#ifndef MIN_ODD_BIG
#define MIN_ODD_BIG 99900001
#endif

#ifndef MAX_ODD_BIG
#define MAX_ODD_BIG 100000000
#endif

Meter meterCyclesBig = Meter();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                  Different Fermat's algorithms with different probabilities (odd numbers)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Starting measuring cycles of primality tests for big numbers ..." << endl;
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.5 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomOdds50Big", isPrimeFermatRandom, i, 0.5);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.75 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomOdds75Big", isPrimeFermatRandom, i, 0.75);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 1.0 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomOdds100Big", isPrimeFermatRandom, i, 1.0);
}
cout << "Measuring function 'isPrimeFermatRandomWithChoosablePrecision' with probability of 1.0 (odd numbers, floating precision of 150)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
    mpf_class probability(1.0);
	meterCyclesBig.measureCycles<bool, size_t&, mpf_class, size_t>(i, 10, "isPrimeFermatRandom100WithChoosablePrecisionOdds150Big", isPrimeFermatRandomWithChoosablePrecision, i, 1.0, 150);
}
cout << "Measuring function 'isPrimeFermatRandomImproved' with probability of 1.0 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
    mpf_class probability(1.0);
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomImprovedOdds100Big", isPrimeFermatRandomImproved, i, 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      Solovay-Strassen with different probabilities (odd numbers), no random numbers
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovay' with probability of 0.5 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i < MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds50Big", isPrimeSolovay, i, 0.5);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.75 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i < MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds75Big", isPrimeSolovay, i, 0.75);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.9999 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i < MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds99Big", isPrimeSolovay, i, 0.9999);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 1 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i < MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayOdds100Big", isPrimeSolovay, i, 1.0);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Solovay-Strassen for comparing the self-implemented GCD-algorithm with the GMP library's and the C++ random number
//    generator with the GMP library's.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovayGMP' with probability of 1 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
    mpz_class n(i);
	meterCyclesBig.measureCycles<bool, mpz_class&, long double>(i, 10, "isPrimeSolovayGMPOddsBig", isPrimeSolovayGMP, n, 1.0);
}
cout << "Measuring function 'isPrimeSolovayRandom' with probability of 1 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
    mpz_class n(i);
	meterCyclesBig.measureCycles<bool, mpz_class&, long double>(i, 10, "isPrimeSolovayRandomOddsBig", isPrimeSolovayRandom, n, 1.0);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 1 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i <= MAX_ODD_BIG; i += 2) {
    mpz_class n(i);
	meterCyclesBig.measureCycles<bool, mpz_class&, long double>(i, 10, "isPrimeSolovayRandomGMPOddsBig", isPrimeSolovayRandom, n, 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Solovay-Strassen with different probabilities (odd numbers), using random number algorithm of the GMP library
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.5 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i < MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPOdds50Big", isPrimeSolovayRandomGMP, i, 0.5);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.75 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i < MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPOdds75Big", isPrimeSolovayRandomGMP, i, 0.75);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.9999 (odd numbers)." << endl;
for (size_t i = MIN_ODD_BIG; i < MAX_ODD_BIG; i += 2) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPOdds99Big", isPrimeSolovayRandomGMP, i, 0.9999);
}
cout << "Finished measuring cycles of primality tests for big numbers." << endl << endl;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                  Different Fermat's algorithms with different probabilities (prime numbers only)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Starting measuring cycles of primality tests for big numbers ..." << endl;
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.5 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomPrimes50Big", isPrimeFermatRandom, i, 0.5);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 0.75 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomPrimes75Big", isPrimeFermatRandom, i, 0.75);
}
cout << "Measuring function 'isPrimeFermatRandom' with probability of 1.0 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomPrimes100Big", isPrimeFermatRandom, i, 1.0);
}
cout << "Measuring function 'isPrimeFermatRandomWithChoosablePrecision' with probability of 1.0 (prime numbers only, floating precision of 150)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
    mpf_class probability(1.0);
	meterCyclesBig.measureCycles<bool, size_t&, mpf_class, size_t>(i, 10, "isPrimeFermatRandom100WithChoosablePrecisionPrimes150Big", isPrimeFermatRandomWithChoosablePrecision, i, 1.0, 150);
}
cout << "Measuring function 'isPrimeFermatRandomImproved' with probability of 1.0 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
    mpf_class probability(1.0);
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeFermatRandomImprovedPrimes100Big", isPrimeFermatRandomImproved, i, 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      Solovay-Strassen with different probabilities (prime numbers only), no random numbers
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovay' with probability of 0.5 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayPrimes50Big", isPrimeSolovay, i, 0.5);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.75 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayPrimes75Big", isPrimeSolovay, i, 0.75);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 0.9999 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayPrimes99Big", isPrimeSolovay, i, 0.9999);
}
cout << "Measuring function 'isPrimeSolovay' with probability of 1 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayPrimes100Big", isPrimeSolovay, i, 1.0);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Solovay-Strassen for comparing the self-implemented GCD-algorithm with the GMP library's and the C++ random number
//    generator with the GMP library's.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovayGMP' with probability of 1 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
    mpz_class n(i);
	meterCyclesBig.measureCycles<bool, mpz_class&, long double>(i, 10, "isPrimeSolovayGMPPrimesBig", isPrimeSolovayGMP, n, 1.0);
}
cout << "Measuring function 'isPrimeSolovayRandom' with probability of 1 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
    mpz_class n(i);
	meterCyclesBig.measureCycles<bool, mpz_class&, long double>(i, 10, "isPrimeSolovayRandomPrimesBig", isPrimeSolovayRandom, n, 1.0);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 1 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
    mpz_class n(i);
	meterCyclesBig.measureCycles<bool, mpz_class&, long double>(i, 10, "isPrimeSolovayRandomGMPPrimesBig", isPrimeSolovayRandom, n, 1.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Solovay-Strassen with different probabilities (prime numbers only), using random number algorithm of the GMP library
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.5 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPPrimes50Big", isPrimeSolovayRandomGMP, i, 0.5);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.75 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPPrimes75Big", isPrimeSolovayRandomGMP, i, 0.75);
}
cout << "Measuring function 'isPrimeSolovayRandomGMP' with probability of 0.9999 (prime numbers only)." << endl;
for (size_t i = 0; i < bigPrimesVector.size(); i++) {
	meterCyclesBig.measureCycles<bool, size_t&, long double>(i, 10, "isPrimeSolovayRandomGMPPrimes99Big", isPrimeSolovayRandomGMP, i, 0.9999);
}
cout << "Finished measuring cycles of primality tests for big numbers." << endl << endl;
