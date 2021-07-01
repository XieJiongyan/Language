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
  Sentence_level sentence_level;
  char c;
  string s;
  while (fin.get(c)) {
    if (c == '\n') {
      sentences.emplace_back(Sentence{s, sentence_level});
      switch (*s.rbegin()) {
        case '(':
        case '[':
        case '{':
          sentence_level.add_level();
          break;
        case ')':
        case ']':
        case '}':
          sentence_level.rmv_level();
          sentence_level.add_line();
          break;
        default:
          sentence_level.add_line();
      }
      s = "";
    } else
      s += c;
  }
  if (s != "") sentences.emplace_back(Sentence{s, sentence_level});
  for (auto sentence : sentences) sentence.analysis();
}
#endif