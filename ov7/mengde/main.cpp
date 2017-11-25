#include "mengde.hpp"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

ostream &operator<<(ostream &stream, Mengde &mengde) {
  stream << "{";
  vector<int> verdier = mengde.getVerdier();
  for(auto &val : verdier) {
    stream << val;
    if(&val != &verdier.back()) {
      stream << ", ";
    }
  }
  stream << "}";
  return stream;
}

int main() {
  // a
  Mengde tom;
  cout << "Tom: " << tom << endl;

  // b
  vector<int> v = {1, 4, 3};
  vector<int> w = {4, 7};
  Mengde mengde1(v);
  Mengde mengde2(w);
  Mengde unionMengde = mengde1 + mengde2;
  cout << "Union {1, 4, 3} og {4, 7}: " << unionMengde << endl;

  //c
  Mengde mengde3 = mengde1 + 1;
  cout << "mengde1 + 1: " << mengde3 << endl;
  Mengde mengde4 = mengde1 + 2;
  cout << "mengde1 + 2: " << mengde4 << endl;

  // d
  mengde1 = mengde2;
  cout << "mengde1 = mengde2: " << mengde1 << endl;
  Mengde n = mengde1 + mengde2;

  // e
  cout << "mengde1 + mengde2: " << n << endl;


  return 0;
}
