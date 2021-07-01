#ifndef __sentence_h__
#define __sentence_h__
#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Sentence {
 public:
  void input_file(std::string filename);

 private:
  vector<int> level;
};
#endif