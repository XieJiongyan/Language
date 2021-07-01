#include <iostream>

#include "cpplab/sentence.h"
using namespace ::std;

int main() {
  cout << "Welcome to language" << endl;
  char c{' '};
  for (int i(0); i < 10; i++) {
    c = cin.get();
    cout << i << ": " << c << endl;
  }
  Sentence sentence;
  sentence.print_test();
  return 0;
}