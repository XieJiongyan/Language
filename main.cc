#include <iostream>
using namespace ::std;

int main() {
  cout << "Welcome to language" << endl;
  char c{' '};
  for (int i(0); i < 10; i++) {
    c = cin.get();
    cout << i << ": " << c << endl;
  }
  return 0;
}