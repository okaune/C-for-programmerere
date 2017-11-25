#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

int finnSum(const int *tabell, int antElementer);

void task6() {
  cout << "Task 6" << endl;

  int tabell[20];
  int length = (sizeof(tabell) / sizeof(tabell[0]));

  for(int i = 0; i < length; i++) {
    tabell[i] = i + 1;
  }

  cout << "Sum 10 første: " << finnSum(tabell, 10) << endl;
  cout << "Sum 5 neste: " << finnSum(&tabell[10], 5) << endl;
  cout << "Sum 5 siste: " << finnSum(&tabell[15], 5) << endl;
}

int finnSum(const int *tabell, int antElementer) {
  int sum = 0;
  for(int i = 0; i < antElementer; i++) {
    sum += *tabell;
    tabell++;
  }
  return sum;
}