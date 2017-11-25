#include "broek.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void skriv(const string &tekst, const Broek &broek) {
  cout << tekst << broek.finnTeller() << "/";
  cout << broek.finnNevner() << endl;
}
void skriv(const string &tekst, const int i) {
  cout << tekst << i << endl;
}

int operator-(const int &a, const Broek &b) {
  Broek temp(a, 1);
  return (temp - b).toInt();
}

int main() {
  Broek a(10, 20);
  Broek b(3, 4);
  Broek c(1, 4);
  Broek d = a / b;

  skriv("a = ", a);
  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  cout << endl
       << "b += a; ++c; d *= d;" << endl;
  b += a;
  ++c;
  d *= d;
  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  cout << endl
       << "c = a + b - d * a; c = -c;" << endl;
  c = a + b - d * a;
  c = -c;
  skriv("c = ", c);

  if(a + b != c + d)
    cout << endl
         << "a + b != c + d" << endl;
  else
    cout << endl
         << " a + b == c + d" << endl;

  cout << endl;
  while(b > a) {
    cout << "b -= a;" << endl;
    b -= a;
  }
  skriv("b = ", b);


  // 1a)
  cout << endl
       << "1a)" << endl;
  skriv("a-5=(1/2)-5 ", a - 5);
  skriv("5-a=5-(1/2) ", 5 - a);

  // 1b)
  cout << endl
       << "1b)" << endl;
  // 5-3 = 2
  // 2-a = 2-(1/2) = 1, rundes ned til nærmeste heltall fordi 0 < a < 1
  // 1-7 = -6
  // -6-b = -6-(1/4) = -6, rundes ned til nærmeste heltall fordi 0 < b < 1
  skriv("5-3-(1/2)-7-(1/4): ", 5 - 3 - a - 7 - b);

  return 0;
}
