extern unsigned int primeVectorIndex;

// The algorithm passed the test in all 20 runs, so at least for numbers < 100000000 it seems to be reliable with a probability of 0.9999
// Due to extreme long runtimes this test won't be executed in future runs.
//TEST(PrimeTest, isPrimeSolovayRandom) {
//    mpz_class maximum(100000000);
//    for(int j = 0; j < 20; j++) {
//        cout << j + 1 << ". Durchgang:" << endl;
//        for(mpz_class i("1"); i <= maximum; i += 2) {
//            SCOPED_TRACE(i);
//            if(isPrimeSolovayRandom(i, 0.9999)) {
//                EXPECT_EQ(checkForPrimeNumber(i), 1);
//            }
//        }
//        primeVectorIndex = 0;
//    }
//}

TEST(PrimeTest, isPrimeSolovay) {
    mpz_class maximum(100000);
    for(mpz_class i("1"); i <= maximum; i += 2) {
        if(i % 100 == 0) cout << "Teste :" << i << endl;
        SCOPED_TRACE(i);
        if(isPrimeSolovay(i, 0.999999)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeSolovayGMP) {
    mpz_class maximum(100000);
    for(mpz_class i("1"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeSolovayGMP(i, 0.999999)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeSolovayRandom) {
    mpz_class maximum(100000);
    for(mpz_class i("1"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeSolovayRandom(i, 0.9999)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}

TEST(PrimeTest, isPrimeSolovayRandomGMP) {
    mpz_class maximum(100000);
    for(mpz_class i("1"); i <= maximum; i += 2) {
        SCOPED_TRACE(i);
        if(isPrimeSolovayRandomGMP(i, 0.9999)) {
            EXPECT_EQ(checkForPrimeNumber(i), 1);
        }
    }
    primeVectorIndex = 0;
}
