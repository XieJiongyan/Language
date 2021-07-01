#include <iostream>
#include <string>

#include "cpplab/compiler.h"
using namespace ::std;

int main() {
  cout << "Welcome to language" << endl;
  string filename;
  cin >> filename;
  if (filename == "1") filename = "example/example1.txt";
  Compiler compiler;
  compiler.input_file(filename);
  return 0;
}