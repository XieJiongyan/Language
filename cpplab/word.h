#ifndef __word_h__
#define __word_h__
#include <string>
#include <vector>
using namespace ::std;

class Word_node
{
private:
    char _c;
    int _edge;
    bool _is_end;
public:
    Word_node(char __c) : _c{__c}, _edge{0}, _is_end{false} {}
};

class Word_edge
{
    int _node;
    int _next;

public:
    Word_edge() : _node{-1}, _next{0} {}
};

class Word
{
    string _name;
    bool _is_exist;
};
class Wordspace
{
private:
    vector<Word_node> _nodes;
    vector<Word_edge> _edges;

    void add_word_node(char __c);

public:
    Wordspace() : _nodes{vector<Word_node>{Word_node{' '}}},
                  _edges{vector<Word_edge>{Word_edge{}}} {}

    /**
     * @brief 分析一句话
     * @usage wordspace.analysis(sentence._content);
     * @detail 期待实现分割, 加词, 给出词类型, 返回所有词的的功能
     * @param __sentence_content a sentence of string
     */
    vector<Word> analysis(string __sentence_content);
};
#endif