#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

double rand0to10();

int main() {

  vector<double> vec;

  for(int i = 0; i < 5; i++) {
    vec.emplace_back(((double)rand() / (RAND_MAX)) * 10);
  }

  cout << "Front: " << vec.front() << endl
       << "Back: " << vec.back() << endl;

  auto r = ((double)rand() / (RAND_MAX)) * 10;
  vec.emplace(vec.begin() + 1, r);
  cout << "Front: " << vec.front() << endl;

  auto answer = find(vec.begin(), vec.end(), r);
  cout << "Fant verdi: " << *answer.base() << endl;
}