TEST(GCD_TEST, GCD) {
    ASSERT_EQ(getGCD(7, 8), 1);
    ASSERT_EQ(getGCD(8, 7), 1);
    ASSERT_EQ(getGCD(12, 18), 6);
    ASSERT_EQ(getGCD(12, 18), 6);
    ASSERT_EQ(getGCD(18, 12), 6);
    ASSERT_EQ(getGCD(1029, 1071), 21);
    ASSERT_EQ(getGCD(1071, 1029), 21);
    ASSERT_EQ(getGCD(22, -5), 1);
    ASSERT_EQ(getGCD(-22, 5), 1);
    ASSERT_EQ(getGCD(-22, -5), 1);
}
