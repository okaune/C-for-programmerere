#include "mengde.hpp"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

Mengde::Mengde() {
  verdier = {};
}

Mengde::Mengde(vector<int> vec) {
  verdier = vec;
}

Mengde Mengde::operator+(Mengde &mengde) const {
  set<int> unionMengde;
  for(auto &val : verdier) {
    if(unionMengde.find(val) == unionMengde.end()) {
      unionMengde.insert(val);
    }
  }
  for(auto &val : mengde.getVerdier()) {
    if(unionMengde.find(val) == unionMengde.end()) {
      unionMengde.insert(val);
    }
  }
  vector<int> nyeVerdier(unionMengde.begin(), unionMengde.end());
  Mengde nyMengde(nyeVerdier);
  return nyMengde;
}

Mengde Mengde::operator+(int val) const {
  Mengde m = *this;
  if(find(m.verdier.begin(), m.verdier.end(), val) == m.verdier.end()) {
    m.verdier.push_back(val);
    sort(m.verdier.begin(), m.verdier.end());
  }
  return m;
}

void Mengde::operator=(Mengde &mengde) {
  verdier = mengde.getVerdier();
}