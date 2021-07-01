#ifndef __sentence_cc__
#define __sentence_cc__
#include "sentence.h"

#include <fstream>
using namespace ::std;

void Sentence::input_file(std::string filename) {
  cout << "opening " << filename << endl;
  ifstream fin(filename);
  if (!fin) cout << "open wrong" << endl;
  string word;
  char c;
  for (int i{0}; i < 10; i++) {
    c = fin.get();
    cout << i << ". " << c << " " << static_cast<int>(c) << endl;
  }
}
#endif