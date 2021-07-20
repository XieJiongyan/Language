#ifndef __sentence_cc__
#define __sentence_cc__
#include "sentence.h"

#include <fstream>
using namespace ::std;

void Sentence::analysis() const {
  cout << "Sentence " << _sentence_level.label() << "- " << _content << endl;
  vector<string> words;
  /**
   * @brief 当前单词状态
   * 
   * @enum 0 刚刚开始, 或者未属于任何单词
   * @enum 1 当前单词为变量
   * @enum 2 当前单词为符号
   * @enum 3 当前单词为数字
   */
  int status{0};
  for (auto i(_content.begin()); i < _content.end(); i++) {
    /**
     * @brief 当前字符类型
     * 
     * @enum 0 ' ', '\t', '\n'
     * @enum 1 字母, '_'
     * @enum 2 _symbol_char
     * @enum 3 数字
     */
    int ctype{4};
    int cint{static_cast<int>(*i)};
    if (_neglect_chars.find(*i) != _neglect_chars.end())
      ctype = 0;
    else if (cint >= 65 && cint < 91 || cint >= 97 && cint < 123 || cint == 95)
      ctype = 1;
    else if (_symbol_chars.find(*i) != _symbol_chars.end())
      ctype = 2;
    else if (cint >= 48 && cint < 58)
      ctype = 3;
    /**
     * @brief 接下来的动作
     * 
     * @enum 0 啥都不做
     * @enum 1 添加该字符至新单词
     * @enum 2 添加该字符至旧单词
     */
    int x{0};
    if (ctype == 0)
      x = 0;
    else if (status == 2 && ctype == 2) {
      if (_wordspaces[0].contains_word(*words.rbegin() + *i)) 
        x = 2;
      else if (_wordspaces[0].has_word(*words.rbegin())) 
        x = 1;
      else 
        cout << "Error" << endl;
    }
    else if (status == ctype || status == 1 && ctype == 3 ||
    status == 3 && *i == '.') 
      x = 2;
    else
      x = 1;
    switch (x)
    {
    case 1:
      words.emplace_back(string{*i});
    case 0:
      status = ctype;
      break;
    case 2:
      *words.rbegin() += *i;
      break;
    default:
      break;
    }
  }
  for (auto word : words) {
    //TODO 这里可以先加一个数字判断
    cout << "   Word: " << word << " : ";
    bool is_exist{false};
    for (auto wordspace : _wordspaces) if(wordspace.has_word(word)) {
      is_exist = true;
      break;
    }
    if (!is_exist) cout << "not ";
    cout << "exist" << endl; 
  }
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

void Sentence::add_keywords() {
  _wordspaces.emplace_back(Wordspace{".", ",", "/", ":", ";", "\'", "\""
  "[", "]", "{", "}", "```", "~", "!", "@", "#", "$", "%", "^", "*", "(", 
  ")", "-", "+", "=", "|", "\\", "==", "=>", "<=>", "//", "/*", "*/", "::"});
  _wordspaces.emplace_back(Wordspace{"object", "int", "bool", "is", "in", 
  "belongs_to", "equal", "has", "connection", "for", "if"});
}
#endif