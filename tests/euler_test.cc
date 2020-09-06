#include <memory>
#include "gtest/gtest.h"
#include "src/lib/euler.h"

TEST(MultiplesOf3and5Should, ReturnValidSum){
    std::unique_ptr<MultiplesOf3and5> multiplesOf3and5(new MultiplesOf3and5());
    auto actual = multiplesOf3and5->getSum();
    auto expected = 233168;
    EXPECT_EQ(expected, actual);
}

TEST(EvenFibonacciNumbersShould, ReturnValidExampleSum){
    std::unique_ptr<EvenFibonacciNumbers> tested(new EvenFibonacciNumbers());
    auto actual = tested->getSum(100);
    auto expected = 2 + 8+ 34;
    EXPECT_EQ(expected, actual);
}

TEST(EvenFibonacciNumbersShould, ReturnValidSum){
    std::unique_ptr<EvenFibonacciNumbers> tested(new EvenFibonacciNumbers());
    auto actual = tested->getSum(4000000);
    auto expected = 4613732;
    EXPECT_EQ(expected, actual);
}

TEST(LargestPrimeFactorShould, ReturnValidExample){
    std::unique_ptr<LargestPrimeFactor> tested(new LargestPrimeFactor());
    auto actual = tested->getLargestPrimeFactorOf(13195);
    auto expected = 29;
    EXPECT_EQ(expected, actual);
}

TEST(LargestPrimeFactor2Should, ReturnValidExample){
    std::unique_ptr<LargestPrimeFactor> tested(new LargestPrimeFactor());
    auto actual = tested->getLargestPrimeFactorOf2(13195);
    auto expected = 29;
    EXPECT_EQ(expected, actual);
}

TEST(LargestPrimeFactor2Should, ReturnValidAnswer){
    std::unique_ptr<LargestPrimeFactor> tested(new LargestPrimeFactor());
    auto actual = tested->getLargestPrimeFactorOf2(600851475143);
    auto expected = 6857;
    EXPECT_EQ(expected, actual);
}

TEST(LargestPalindromeProductShould, ReturnValidExample){
    std::unique_ptr<LargestPalindromeProduct> tested(new LargestPalindromeProduct());
    auto actual = tested->get(10,99);
    auto expected = 9009;
    EXPECT_EQ(expected, actual);
}

TEST(LargestPalindromeProductShould, ReturnAnswer){
    std::unique_ptr<LargestPalindromeProduct> tested(new LargestPalindromeProduct());
    auto actual = tested->get(100, 999);
    auto expected = 906609;
    EXPECT_EQ(expected, actual);
}

TEST(SmallestMultipleShould, ReturnValidExample){
    std::unique_ptr<SmallestMultiple> tested(new SmallestMultiple());
    auto actual = tested->get(10);
    auto expected = 2520;
    EXPECT_EQ(expected, actual);
}

/*  takes a bit too much time to run 
TEST(SmallestMultipleShould, ReturnAnswer){
    std::unique_ptr<SmallestMultiple> tested(new SmallestMultiple());
    auto actual = tested->get(20);
    auto expected = 232792560;
    EXPECT_EQ(expected, actual);
}
*/


TEST(SumSquareDifferenceShould, ReturnValidExample){
    std::unique_ptr<SumSquareDifference> tested(new SumSquareDifference());
    auto actual = tested->get(10);
    auto expected = 2640;
    EXPECT_EQ(expected, actual);
}

TEST(SumSquareDifferenceShould, ReturnValidAnswer){
    std::unique_ptr<SumSquareDifference> tested(new SumSquareDifference());
    auto actual = tested->get(100);
    auto expected = 25164150;
    EXPECT_EQ(expected, actual);
}


TEST(The10001stPrimeShould, ReturnValidExample){
    std::unique_ptr<The10001stPrime> tested(new The10001stPrime());
    auto actual = tested->get(6);
    auto expected = 13;
    EXPECT_EQ(expected, actual);
}

/* 
takes a bit time to run
TEST(The10001stPrimeShould, ReturnValidAnswer){
    std::unique_ptr<The10001stPrime> tested(new The10001stPrime());
    auto actual = tested->get(10001);
    auto expected = 104743;
    EXPECT_EQ(expected, actual);
}
*/

TEST(LargestProductInASeries, ReturnValidExample){
    std::unique_ptr<LargestProductInASeries> tested(new LargestProductInASeries());
    auto actual = tested->get(4);
    auto expected = 5832;
    EXPECT_EQ(expected, actual);
}


TEST(LargestProductInASeries, ReturnValidAnswer){
    std::unique_ptr<LargestProductInASeries> tested(new LargestProductInASeries());
    auto actual = tested->get(13);
    auto expected = 23514624000;
    EXPECT_EQ(expected, actual);
}


TEST(SpecialPythagoreanTriplet, ReturnValidTriplet){
    std::unique_ptr<SpecialPythagoreanTriplet> tested(new SpecialPythagoreanTriplet());
    auto triplet = tested->get(1000);
    auto product = tested->getProduct(1000);

    EXPECT_EQ(triplet.a*triplet.a + triplet.b*triplet.b, triplet.c*triplet.c);

    EXPECT_EQ(200, triplet.a);
    EXPECT_EQ(375, triplet.b);
    EXPECT_EQ(425, triplet.c);
    EXPECT_EQ(31875000, product);
}

