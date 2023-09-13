/*
# LIEF CPP harness
export AFL_HARDEN=1
export AFL_LLVM_CMPLOG=1
mkdir build
cd build
CC=afl-cc CXX=afl-c++ AR=llvm-ar-14 RANLIB=llvm-ranlib-14 AS=llvm-as-14
LD=afl-ld-lto cmake ../ CC=afl-cc CXX=afl-c++ AR=llvm-ar-14
RANLIB=llvm-ranlib-14 AS=llvm-as-14 LD=afl-ld-lto make afl-c++ -O0 harness.cpp
-I ../../../include/ -I ../../../build/include/ ../../libLIEF.a -o harness
afl-cmin -i /bin -o inputs/ -- ./harness
afl-fuzz -D -i inputs/ -t 80 -o sync_dir -M fuzzer00 -- ./harness
*/

#include <LIEF/LIEF.hpp>
#include <vector>
#include <memory>
#include <iostream>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <string>

__AFL_FUZZ_INIT();
static void harness() {
  const uint8_t *data = __AFL_FUZZ_TESTCASE_BUF;
  while (__AFL_LOOP(10000)) {
    int size = __AFL_FUZZ_TESTCASE_LEN;
    std::vector<uint8_t> raw = {data, data + size};
    if (auto b = LIEF::ELF::Parser::parse(raw)) {
      std::stringstream oss;
      oss << *b;
    }
  }
}
namespace fuzz {
static void test() { harness(); }
} // namespace fuzz
int main() {
#ifdef __AFL_HAVE_MANUAL_CONTROL
  __AFL_INIT();
#endif
  fuzz::test();
  return 0;
}
