#include <vector>
#include <string> 
#include <algorithm> 

#include "euler.h"

int MultiplesOf3and5::getSum() {
    auto sum = 0;
    for (int i = 2; i < 1000; i++) {
        if (( i%3 == 0) || (i%5 == 0 )) {
            sum += i;
        }
    }
    return sum;
}

uint64_t EvenFibonacciNumbers::getSum(uint64_t limit) {
    uint64_t sum = 0;
    uint64_t previousValue = 1;
    uint64_t currentValue = 2;
    while ( currentValue < limit ) {
        if (currentValue %2 == 0) {
            sum += currentValue;
        }
        uint64_t newCurrentValue = currentValue + previousValue;
        previousValue = currentValue;
        currentValue = newCurrentValue;
    }
    return sum;
}

uint64_t LargestPrimeFactor::getLargestPrimeFactorOf(uint64_t factored) {
    std::vector<uint64_t> primes = {2};

    auto limit = factored;
    uint64_t current = 3;

    while ( current * 2 <= limit) {
        auto foundPrime = true;
        for (auto prime: primes) {
            if (current % prime == 0) {
                foundPrime = false;
                break;
            }
        }
        if (foundPrime) {
            primes.push_back(current);
        }
        current +=2; //such an optimization!
    }
    
    for (unsigned i = primes.size(); i-- > 0; ) {
           if (factored % primes[i] == 0) {
            return primes[i];
        }
    }
    return 0;
}

uint64_t LargestPrimeFactor::getLargestPrimeFactorOf2(uint64_t factored) {
    uint64_t i = 2;
    while( i<factored/2) {
        while (factored % i == 0) {
            factored /= i;
        }
        i++;
    }
    return factored;
}

uint64_t LargestPalindromeProduct::get(uint productMin, uint productMax) {
    uint64_t largestPalindrome = 0; //zero is a palindrome as well
    for(uint i = productMin; i <=productMax; i++) {
        for(uint j = productMin; j <=productMax; j++) {
             auto s = std::to_string(i*j);
             auto reverse_s(s);
             std::reverse(s.begin(), s.end());
             if ((s == reverse_s) && (largestPalindrome < i*j)) {
                 largestPalindrome = i*j;
             }
        }
    }
    return largestPalindrome;
}

uint64_t SmallestMultiple::get(uint numberMax){
    auto tested = numberMax;
    while (true) {
        auto found = true;
        for (uint64_t i = 2; i<=numberMax; i++) {
            if (tested%i != 0) {
                found = false;
                break;
            }
        }
        if(found) {
            break;
        }
        tested ++;
    }
    return tested;
}

uint64_t SumSquareDifference::get(uint numberMax){
    uint64_t squareSum = 0;
    for(uint i = 1; i <= numberMax; i++) {
        squareSum += i*i;
    }

    uint64_t sumSquare = (1+numberMax)*numberMax/2;
    sumSquare *= sumSquare;

    return sumSquare - squareSum;
}

uint64_t The10001stPrime::get(uint numberMax) {
    std::vector<uint64_t> primes = {2};
    uint64_t current = 3;
    while ( primes.size() < numberMax) {
        auto foundPrime = true;
        for (auto prime: primes) {
            if (current % prime == 0) {
                foundPrime = false;
                break;
            }
        }
        if (foundPrime) {
            primes.push_back(current);
        }
        current +=2; //such an optimization!
    }
    return primes.back();
}


uint64_t LargestProductInASeries ::get(uint digits) {
    const std::string number = "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";

    
    uint numbers[digits];
    uint i = 0;
    for(; i<digits; i++) {
        numbers[i] = std::stoi(number.substr(i,1));
    }
    
    uint64_t productMax = 0;

    while (true) {
        uint64_t product=1;
        for(uint j=0; j<digits; j++) {
            product *= numbers[j];
        }
        if (product > productMax ){
            productMax = product;
        }

        if (i>=number.size()) {
            break;
        }

        numbers[i%digits] = std::stoi(number.substr(i,1));
        i++;
    }


    return productMax;
}

SpecialPythagoreanTriplet::Triplet SpecialPythagoreanTriplet::get(uint sum) {
    SpecialPythagoreanTriplet::Triplet triplet;
    triplet.a = 0;
    triplet.b = 0;
    triplet.c = 0;
    for (uint i=1; i<sum;i++) {
        for (uint j=i+1; j<sum;j++) {
            for (uint k=j+1; k<sum;k++) {
                // not optimal, but I got this done fast
                if ( i + j +k != sum ) {
                    continue;
                }

                if ( i*i + j*j != k*k) {
                    continue;
                }

                triplet.a = i;
                triplet.b = j;
                triplet.c = k;

                return triplet;
            }
            
        }
    }

    return triplet;
}


uint SpecialPythagoreanTriplet::getProduct(uint sum) {
    auto triplet = SpecialPythagoreanTriplet::get(sum);
    return triplet.a * triplet.b * triplet.c;
}
