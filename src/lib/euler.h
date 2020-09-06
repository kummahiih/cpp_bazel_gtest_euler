#ifndef TEMPLATE_EULER_H
#define TEMPLATE_EULER_H

#include <string>
#include <vector>


class MultiplesOf3and5 {
public:
    int getSum();
};

class EvenFibonacciNumbers {
public:
    uint64_t getSum(uint64_t limit);
};

class LargestPrimeFactor {
public:
    uint64_t getLargestPrimeFactorOf(uint64_t factored); // this took ages to complete
    uint64_t getLargestPrimeFactorOf2(uint64_t factored);

};

class LargestPalindromeProduct {
public:
    uint64_t get(uint productMin, uint productMax);
};


class SmallestMultiple {
public:
    uint64_t get(uint numberMax);
};


class SumSquareDifference {
public:
    uint64_t get(uint numberMax);
};

class The10001stPrime {
public:
    uint64_t get(uint numberMax);
};

class LargestProductInASeries {
public:
    uint64_t get(uint digits);
};


class SpecialPythagoreanTriplet {
public:
    struct Triplet
    {
        uint a;
        uint b;
        uint c;
    };
    Triplet get(uint sum);

    uint getProduct(uint sum);

};


#endif