#ifndef __word_cc__
#define __word_cc__
#include "word.h"

/**
 * @brief 尝试增加一个 word
 * 
 * @param word 增加的单词
 * @return true 增加成功
 * @return false 增加失败
 */
bool Wordspace::add_word(string word) {
  unsigned iw{0};
  for (auto i(word.begin()); i < word.end(); i++) {
    int iwn{find_next_node(iw, *i)};
    if (iwn) {
      iw = iwn;
    } else {
      _nodes.emplace_back(Word_node{*i});
      _edges.emplace_back(Word_edge{_nodes.size() - 1, _nodes[iw]._edge});
      _nodes[iw]._edge = _edges.size() - 1;
      iw = _nodes.size() - 1;
    }
  }
  bool rev{false};
  if (!_nodes[iw]._is_end) {
    _nodes[iw]._is_end = true;
    rev = true;
  }
  return rev;
}

/**
 * @brief 判断某 node 之后有无某字符
 * 
 * @param in node 位置
 * @param __c 判断的字符
 * @return int 若为0, 则表示未找到, 否则为下一节点位置
 */
int Wordspace::find_next_node(int in, char __c) const {
  int rev{0};
  for (int ie(_nodes[in]._edge); ie != 0; ie = _edges[ie]._next) {
    if (_nodes[_edges[ie]._to]._c == __c)
      rev = _edges[ie]._to;
  }
  return rev;
}

/**
 * @brief 判断一个 word 在不在 wordspace 中
 * 
 * @param word 判断该单词在不在
 * @return true 
 * @return false 
 */
bool Wordspace::has_word(string word) const {
  unsigned iw{0};
  for (auto i(word.begin()); i < word.end(); i++) {
    iw = find_next_node(iw, *i);
    if (!iw)
      return false;
  }
  if (_nodes[iw]._is_end)
    return true;
  return false;
}

/**
 * @brief 判断一个 word 在不在 wordspace 中, 即便只是单词前缀也算
 * 
 * @param word 
 * @return true 
 * @return false 
 */
bool Wordspace::contains_word(string word) const {
  unsigned iw{0};
  for (auto i(word.begin()); i < word.end(); i++) {
    iw = find_next_node(iw, *i);
    if (!iw)
      return false;
  }
  return true;
}

#endif