#ifndef __sentence_h__
#define __sentence_h__
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "word.h"
using namespace ::std;

class Sentence_level {
 public:
  Sentence_level() : _levels(vector<int>{0}) {}
  Sentence_level(const Sentence_level& _x) : _levels(_x._levels) {}

  string label() const;
  void add_level();
  void rmv_level();
  void add_line();

 private:
  vector<int> _levels;
};

class Sentence {
 public:
  Sentence(string __c) : _content(__c), _sentence_level(Sentence_level()) {
    add_keywords();
  }
  Sentence(string __c, Sentence_level __s)
      : _content(__c), _sentence_level(__s) {
    add_keywords();
  }
  void analysis() const;

 private:
  string _content;
  Sentence_level _sentence_level;
  /**
   * @brief 单词空间
   * 
   * 第一项为内置运算符
   * 第二项为内置关键字
   */
  vector<Wordspace> _wordspaces;
  const set<char> _neglect_chars{' ', '\t', '\n'};
  const set<char> _symbol_chars{',', '.', '/', '<', '>', '?', '\'', ';', ':', '\"', '[', ']', '{', '}', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '|', '\\'};

  void add_keywords();
};

#endif