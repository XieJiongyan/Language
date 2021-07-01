#ifndef __sentence_h__
#define __sentence_h__
#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Sentence_level {
 public:
  Sentence_level() : _levels(vector<int>{0}) {}
  Sentence_level(const Sentence_level& _x) : _levels(_x._levels) {}

  string label() const;
  void add_level();
  void rmv_level();

 private:
  vector<int> _levels;
};

class Sentence {
 public:
  Sentence(string __c) : _content(__c), _sentence_level(Sentence_level()) {}
  Sentence(string __c, Sentence_level __s)
      : _content(__c), _sentence_level(__s) {}
  void analysis() const;

 private:
  string _content;
  Sentence_level _sentence_level;
};

#endif