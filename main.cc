#include <iostream>
#include <fstream>
#include <string>

#include "cpplab/compiler.h"
#include "cpplab/word.h"
using namespace ::std;

struct Testmachine
{
  string head;
  int num;
  int success;
  int part;
} testmachine;
int parts, success_parts;
ofstream fout;

//  @brief  To test our section
//  @param  __judgement  判断语句，如果正确，则打印1，如果错误，则打印0
//  @param  __prints  接下来打印的注释内容
template <typename... Types>
void test(bool __judgement, const Types &...__prints);

// @brief Divide test to parts.
void testpart(string testpart);

int main()
{
  fout.open("testLog.txt");
  cout << "Welcome to language" << endl;
  cout << "-------------------------\n"
       << endl;
  fout << "Welcome to language" << endl;
  fout << "-------------------------\n"
       << endl;

  testmachine.head = "J.";
  testmachine.num = 0;
  testmachine.part = 0;
  parts = 0;
  success_parts = 0;
  testpart("Checking example/example1.txt");
  {
    Compiler compiler;
    compiler.input_file("example/example1.txt");
    test(true);
  }
  testpart("Checking wordspace"); {
    Wordspace wordspace;
    test(!wordspace.has_word("big_bang"));

    test(wordspace.add_word("big_bang"));

    test(!wordspace.add_word("big_bang"));

    test(wordspace.has_word("big_bang"));

    test(wordspace.add_word("big"));

    test(wordspace.has_word("big"));

    test(wordspace.add_word("bigfat"));

    test(wordspace.has_word("bigfat"));

    test(!wordspace.has_word("bi"));
  }
  testpart("STOP TEST");

  return 0;
}

void print() {}

template <typename Type, typename... Types>
void print(const Type &arg, const Types &...args)
{
  cout << arg;
  fout << arg;
  print(args...);
}

template <typename... Types>
void test(bool judge, const Types &...args)
{
  cout << testmachine.head << testmachine.part << '.' << testmachine.num << "=" << judge << " ";
  fout << testmachine.head << testmachine.part << '.' << testmachine.num << "=" << judge << " ";
  print(args...);
  cout << endl;
  fout << endl;
  testmachine.num++;
  if (judge)
    testmachine.success++;
}

void testpart(string s)
{
  if (testmachine.part != 0)
  {
    cout << "} succeeded(" << testmachine.success << '/' << testmachine.num << "). ";
    fout << "} succeeded(" << testmachine.success << '/' << testmachine.num << "). ";
    if (testmachine.success == testmachine.num)
    {
      success_parts += 1;
      cout << "Pass test " << testmachine.head << testmachine.part << '.';
      fout << "Pass test " << testmachine.head << testmachine.part << '.';
    }
    else
      cout << "\n ! Not Pass Test, have " << -testmachine.success + testmachine.num << " bug(s).";
    cout << endl;
    cout << endl;
    fout << endl;
    fout << endl;
  }
  if (s == "STOP TEST")
    return;
  cout << ">> Start Test " << testmachine.head << testmachine.part << " " << s << " {" << endl;
  fout << ">> Start Test " << testmachine.head << testmachine.part << " " << s << " {" << endl;
  testmachine.part += 1;
  testmachine.num = 0;
  testmachine.success = 0;
  parts += 1;
}