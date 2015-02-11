#include <cassert>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits>
#include <stdlib.h>
#include <vector>

#include <gmpxx.h>

#include "Helpers.h"

#ifdef TEST_RUN
#include <gtest/gtest.h>
#endif // TEST_RUN

#ifdef MEASURE
#include "Meter.h"
#endif

using namespace std;

// Global variables.
unsigned int primeVectorIndex = 0;

// This function determines if an integer n number is prime. It tests all numbers up to sqrt(n) whether they are divisors of n.
// Complexity: O(sqrt((n))
template<typename T>
bool isPrime(T &n) {
    assert(n >= 0);
    T squareroot = sqrt(n);
    if(n < 2) return false;
    if(n == 2) return true;
    for(T i = 2; i <= squareroot; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// This function calculates the result with the formula base^^(n-1) % n to check if n fullfills Fermat's little theorem.
template<typename T>
mpz_class calculateFermat( T &n, T &baseInput) {
    mpz_class base(baseInput);
    mpz_class exp(n - 1);
    mpz_class mod(n);
    mpz_class res;

    mpz_powm(res.get_mpz_t(), base.get_mpz_t(), exp.get_mpz_t(), mod.get_mpz_t());

    return res;
}

// This function determines if an integer number is prime using the Fermat primality test.
// Simple approach without random numbers.
// A higher number of iterations improves the reliability if this functions returns 1.
// Complexity: Runs in constant time (depending on the number of iterations)
template<typename T>
bool isPrimeFermat(T &n, size_t iterations) {
    assert(n >= 0);
    assert(iterations > 0);
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;

    size_t i = 1;
    T base = 2;
    while(base <= iterations) {
        if(base == n) return true; // ???????????????????????????
        if(getGCD(n ,base) > 1) return false;
        if(calculateFermat(n, base) != 1) return false;

        i++;
        base++;
    }
    return true;
}


// This function determines if an integer number is prime using the Fermat primality test.
// Improvements: Using random numbers instead of loop over Fermat's formula to enhance the result's reliability.
// The function argument 'probability' influences the reliability of a return value of 1.
// Complexity: Runs in constant time (depending on the probability argument)
template<typename T>
bool isPrimeFermatRandom(T &n, long double probability) {
    assert(n >= 0);
    assert(probability >= 0.0);
    assert(probability <= 1.0);

    if(n < 2) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    long double actualProbability = 0.0;
    int k = 1;
    initializeRandomNumberGenerator();

    while(actualProbability < probability) {
        T randomNumber = getOddRandomNumber(n);
        if(getGCD(n ,randomNumber) > 1) return false;
        if(calculateFermat(n, randomNumber) != 1) return false;

        actualProbability = 1.0 - pow(0.5, k);
        k++;
    }
    return true;
}


// This function determines if an integer number is prime using the Fermat primality test.
// Improvement: To influence the reliability of a return value of 1 the floatingpoint precision
// of the calculated probability can be set.
// Complexity: Runs in constant time (depending on the probability argument and the precision argument)
template<typename T>
bool isPrimeFermatRandomWithChoosablePrecision(T &n, mpf_class probability, size_t precision) {
    assert(n >= 0);
    assert(probability >= 0.0);
    assert(probability <= 1.0);
    assert(precision > 0);
    if(n < 2) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;

    initializeRandomNumberGenerator();
    mpz_class k(1);

    mpf_class actualProbability(0.0, precision);
    mpf_class highPrecisionProbability(probability, precision);
    mpf_class half(0.5, precision);

    while(actualProbability < highPrecisionProbability) {
        T randomNumber = getOddRandomNumber(n);
        if(getGCD(n ,randomNumber) > 1) return false;
        if(calculateFermat(n, randomNumber) != 1) return false;

        mpf_pow_ui(actualProbability.get_mpf_t(), half.get_mpf_t(), k.get_ui());
        actualProbability = 1.0 - actualProbability;
        k++;
    }
    return true;
}


// This function determines if an integer number is prime using the Fermat primality test with random numbers.
// Improvement: Raise probability of a correct result by testing if prime numbers < 1000 are divisors to n,
// since "out of the Carmichael numbers less than 10^16, about 95% of them are divisible by primes < 1000."
// (Source: http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=primalityTesting).
// Complexity: Runs in constant time (depending on the probability argument)
template<typename T>
bool isPrimeFermatRandomImproved(T &n, long double probability) {
    assert(n >= 0);
    assert(probability >= 0.0);
    assert(probability <= 1.0);

    if(n < 2) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if(nIsDivisiblyBySmallPrimes(n)) return false;


    long double actualProbability = 0.0;
    int k = 1;

    initializeRandomNumberGenerator();

    while(actualProbability < probability) {
        T randomNumber = getOddRandomNumber(n);
        if(getGCD(n ,randomNumber) > 1) return false;
        if(calculateFermat(n, randomNumber) != 1) return false;

        actualProbability = 1.0 - pow(0.5, k);
        k++;
    }
    return true;
}


// This function calculates the result with the formula "base^^((n-1)/2) % n" and the Jacobi-Symbol.
// Then it checks if n fullfills the condition of Solovay's & Strassen's formula.
template<typename T1, typename T2>
bool calculatedSolovayIsValid(T1 &n, T2 &baseInput) {
    mpz_class base(baseInput);
    mpz_class exp(n);
    exp = (exp - 1) / 2;
    mpz_class mod(n);
    mpz_class res;
    mpz_powm(res.get_mpz_t(), base.get_mpz_t(), exp.get_mpz_t(), mod.get_mpz_t());

    if(res > 1 && res < n - 1) return false;
    if(res == n - 1) res = -1;

    mpz_class jacobiSymbol;
    jacobiSymbol = mpz_jacobi(base.get_mpz_t(), mod.get_mpz_t());   // Calculation of the Jacoby symbol
    if(jacobiSymbol % n != res) return false;

    return true;
}

// This function determines if an integer number is prime using the algorithm of Solovay and Strassen.
// The probability argument sets the upper bound of iterations (for probability = 1.0 the algorithm loops
// 54 times but only 14 times for probability = 0.9999).
// Complexity: Runs in constant time (depending on the probability argument)
template<typename T>
bool isPrimeSolovay(T &n, long double probability) {
    assert(n >= 0);
    assert(probability >= 0.0);
    assert(probability <= 1.0);

    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;

    long double actualProbability = 0.5;
    int counter = 1;
    T base(3); // GMP library function mpz_powm (calculates base^^exponent % m) only works with odd numbers

    while(actualProbability < probability) {
        if(base == n) return true;

        if(getGCD(n, base) > 1) return false;
        if(!calculatedSolovayIsValid(n, base)) return false;

        actualProbability = 1.0 - pow(0.5, counter);

        counter++;
        base += 2;
    }
    return true;
}

// This function determines if an integer number is prime using the algorithm of Solovay and Strassen.
// The probability argument sets the upper bound of iterations (for probability = 1.0 the algorithm loops
// 54 times, but only 14 times for probability = 0.9999).
// In contrast to isPrimeSolovay the greatest common divisor is calculated using a GMP library function.
// Complexity: Runs in constant time (depending on the probability argument)
template<typename T>
bool isPrimeSolovayGMP(T &n, long double probability) {
    assert(n >= 0);
    assert(probability >= 0.0);
    assert(probability <= 1.0);
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;

    long double actualProbability = 0.0;
    size_t counter = 1;
    mpz_class base(3);

    while(actualProbability < probability) {
        if(base == n) return true;
        if(getGCD_GMP(n, base) > 1) return false;
        if(!calculatedSolovayIsValid(n, base)) return false;

        actualProbability = 1.0 - pow(0.5, counter);

        counter++;
        base += 2;
    }
    return true;
}

// This function determines if an integer number is prime using the algorithm of Solovay and Strassen.
// Improvement: Use of random numbers (provided by C++ standard random number generator).
// Complexity: Runs in constant time (depending on the probability argument)
template<typename T>
bool isPrimeSolovayRandom(T &n, long double probability) {
    assert(n >= 0);
    assert(probability >= 0.0);
    assert(probability <= 1.0);

    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;

    long double actualProbability = 0.0;
    size_t counter = 1;

    initializeRandomNumberGenerator();

    while(actualProbability < probability){
        mpz_class randomNumber = getOddRandomNumber(n);

        if(getGCD_GMP(n, randomNumber) > 1) return false;
        if(!calculatedSolovayIsValid(n, randomNumber)) return false;

        actualProbability = 1.0 - pow(0.5, counter);

        counter++;
    }
    return true;
}


// This function determines if an integer number is prime using the algorithm of Solovay and Strassen.
// Use of random numbers provided by the GMP library's random number generator for performance comparison reasons.
// Complexity: Runs in constant time (depending on the probability argument)
template<typename T>
bool isPrimeSolovayRandomGMP(T &n, long double probability) {
    assert(n >= 0);
    assert(probability >= 0.0);
    assert(probability <= 1.0);
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;

    long double actualProbability = 0.0;
    size_t counter = 1;
    gmp_randstate_t state;
    gmp_randinit_default(state); // Initialize

    while(actualProbability < probability){
        mpz_class randomNumber = getOddRandomNumberGMP(n, state);

        if(getGCD_GMP(n, randomNumber) > 1) {
            gmp_randclear(state);
            return false;
        }
        if(!calculatedSolovayIsValid(n, randomNumber)) {
            gmp_randclear(state);
            return false;
        }

        actualProbability = 1.0 - pow(0.5, counter);

        counter++;
    }
    gmp_randclear(state);
    return true;
}


#ifdef TEST_RUN
#include "Testcases.h"
#endif

int main(int argc, char **argv) {
#ifdef TEST_RUN
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#endif // TEST_RUN

#ifdef MEASURE
//#include "MeasureTimePrimality.h"
#include "MeasureTimePrimalityBigNumbers.h"
#include "MeasureCyclesPrimality.h"
#include "MeasureCyclesPrimalityBigNumbers.h"
#endif // MEASURE
}
