// These test cases HAVE TO FAIL, because Fermat's prime test doesn't work correctly for these numbers (with base = 2 -> 1 iteration).
TEST(PrimeTest, isPrimeFermatFAIL) {
    size_t data[21] = {341, 561, 645, 1105, 1387, 1729, 1905, 2047, 2465, 2701, 2821, 3277, 4033, 4369, 4681, 5461, 6601, 7957, 8321, 8481, 8911};

    for(unsigned int i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        SCOPED_TRACE(data[i]);
        EXPECT_EQ(isPrimeFermat(data[i], 1), isPrime(data[i]));
    }
}

mpz_class maximum(100000000);

TEST(PrimeTest, isPrimeFermat14) {
    // 14 iterations correlate to a reliability of 0.9999 (for algorithms
    // that use random numbers, unlike the tested one)
    for(mpz_class i("0");; i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermat(i, 14)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeFermat54) {
    // 54 iterations correlate to a reliability of 1.0 (for algorithms
    // that use random numbers, unlike the tested one)
    for(mpz_class i("0");; i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermat(i, 54)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeFermatRandom75) {
    for(mpz_class i("0");; i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandom(i, 0.75)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeFermatRandom99) {
    for(mpz_class i("0");; i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandom(i, 0.9999)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeFermatRandom100) {
    for(mpz_class i("0");; i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandom(i, 1.0)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}


TEST(PrimeTest, isPrimeFermatRandom100WithChoosablePrecision128) {
    mpf_class probability(1.0);
    for(mpz_class i("0"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandomWithChoosablePrecision(i, 1, 128)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeFermatRandom100WithChoosablePrecision150) {
    mpf_class probability(1.0);
    for(mpz_class i("1"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandomWithChoosablePrecision(i, 1, 150)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeFermatRandomImproved50) {
    for(mpz_class i("1"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandomImproved(i, 0.5)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}


TEST(PrimeTest, isPrimeFermatRandomImproved75) {
    for(mpz_class i("1"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandomImproved(i, 0.75)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeFermatRandomImproved999) {
    for(mpz_class i("1"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeFermatRandomImproved(i, 0.999)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}
