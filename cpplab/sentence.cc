#ifndef __sentence_cc__
#define __sentence_cc__
#include "sentence.h"

#include <fstream>
using namespace ::std;

void Sentence::analysis() const {
  cout << _sentence_level.label() << "- " << _content << endl;
  vector<string> words;
  
}

void Sentence_level::add_level() { _levels.emplace_back(0); }

void Sentence_level::rmv_level() { _levels.pop_back(); }

void Sentence_level::add_line() { (*_levels.rbegin())++; }
string Sentence_level::label() const {
  string rev;
  for (auto value : _levels) rev += to_string(value) + ".";
  if (!rev.empty()) rev.pop_back();
  return rev;
}
#endif