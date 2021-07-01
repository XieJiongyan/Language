#ifndef __sentence_h__
#define __sentence_h__
#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Sentence {
 public:
  Sentence(string content) : _content(content) {}
  void analysis();

 private:
  string _content;
};
#endif