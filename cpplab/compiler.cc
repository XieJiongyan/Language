#ifndef __compiler_cc__
#define __compiler_cc__
#include "compiler.h"

#include <fstream>

#include "sentence.h"

using namespace ::std;
void Compiler::print_test() { std::cout << "test Compiler" << std::endl; }

void Compiler::input_file(std::string filename) {
  cout << "opening " << filename << endl;
  ifstream fin(filename);
  if (!fin) {
    cout << "open wrong" << endl;
    return;
  }

  vector<Sentence> sentences;
  char c;

  while (fin.get(c)) {
    cout << "-" << c << endl;
  }
}
#endif