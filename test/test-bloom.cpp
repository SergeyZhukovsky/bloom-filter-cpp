#include "CppUnitLite/TestHarness.h"
#include "CppUnitLite/test.h"
#include "BloomFilter.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include "util.h"
#include "string.h"
#include <iostream>
#include <set>

using namespace std;

TEST(BloomFilter, isBitSetSetBit)
{
  BloomFilter b(10, 3);

  // First bit in a byte
  CHECK(!b.isBitSet(0))
  b.setBit(0);
  CHECK(b.isBitSet(0))

  // Last bit in a byte
  CHECK(!b.isBitSet(7))
  b.setBit(7);
  CHECK(b.isBitSet(7))
  for (int i = 1; i <= 6; i++) {
    CHECK(!b.isBitSet(i));
  }
  CHECK(b.isBitSet(0));

  // Second bit in non first byte
  CHECK(!b.isBitSet(9))
  b.setBit(9);
  CHECK(b.isBitSet(9))
  CHECK(!b.isBitSet(1));
}

// Generates a simple hash function for the specified prime
TEST(BloomFilter, SimpleHashFn)
{
  HashFn H(2);
  int hash = H("hi", 2);

  CHECK(hash == ((int)'h') * pow(2, 1) + ((int)'i') * pow(2, 0));
}
