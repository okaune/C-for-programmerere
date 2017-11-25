#include "likhet.cpp"
#include <iostream>

using namespace std;

int main() {
  cout << boolalpha;
  cout << "\"a\" = \"a\"? " << likhet("a", "a") << endl;
  cout << "\"a\" = \"b\"? " << likhet("a", "b") << endl;
  cout << "0.00001 = 0.0000011? " << likhet(0.00001, 0.0000011) << endl;
  cout << "0.001 = 0.00011? " << likhet(0.001, 0.00011) << endl;
}