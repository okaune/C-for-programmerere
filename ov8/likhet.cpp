#include <cmath>
#include <iostream>

template <class type>

bool likhet(type a, type b) {
  std::cout << "Sjekker med type: ";
  return a == b;
}

bool likhet(double a, double b) {
  std::cout << "Sjekker med double: ";
  return abs(a - b) < 0.00001;
}