#ifndef __word_h__
#define __word_h__
#include <string>
#include <vector>
using namespace ::std;

class Word_node {
 public:
  friend class Wordspace;

 private:
  char _c;
  int _edge;
  bool _is_end;

 public:
  Word_node(char __c) : _c{__c}, _edge{0}, _is_end{false} {}
};

class Word_edge {
  friend class Wordspace;
  unsigned long _to;
  int _next;

 public:
  Word_edge() : _to{0}, _next{0} {}
  Word_edge(unsigned long __to, int __next) : _to(__to), _next(__next) {}
};

class Word {
  string _name;
  bool _is_exist;
};
class Wordspace {
 private:
  vector<Word_node> _nodes;
  vector<Word_edge> _edges;

  // void add_word_node(char __c);
  int find_next_node(int in, char __c) const;

 public:
  Wordspace() : _nodes{vector<Word_node>{Word_node{' '}}},
                _edges{vector<Word_edge>{Word_edge{}}} {}
  Wordspace(initializer_list<string> __s) : _nodes{vector<Word_node>{Word_node{' '}}},
                                            _edges{vector<Word_edge>{Word_edge{}}} {
    for (auto s : __s) add_word(s);
  }
  bool add_word(string word);

  bool has_word(string word) const;

  bool contains_word(string word) const;
};
#endif