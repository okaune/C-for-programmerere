#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

int task4() {

  string ord1;
  string ord2;
  string ord3;

  cout << "Skriv Ord 1" << endl;
  cin >> ord1;
  cout << "Skriv Ord 2" << endl;
  cin >> ord2;
  cout << "Skriv Ord 3" << endl;
  cin >> ord3;

  string setning = ord1 + " " + ord2 + " " + ord3 + ".";
  cout << "Setning: " << setning << endl;
  cout << "Lengde ord1: " << ord1.length() << endl;
  cout << "Lengde ord2: " << ord2.length() << endl;
  cout << "Lengde ord3: " << ord3.length() << endl;
  cout << "Lengde setning: " << setning.length() << endl;

  string setning2 = setning;

  if(setning.length() >= 12)
    setning2.replace(10, 2, "xx");

  cout << setning << endl;
  cout << setning2 << endl;

  cout << "Setning: " << setning << endl;
  if(setning.length() >= 5) {
    string begynnelsen = setning.substr(0, 5);
    cout << "Begynnelsen: " << begynnelsen << endl;
  }

  cout << "Inneholder hallo: " << std::boolalpha << (setning.find("hallo") > 0 && setning.find("hallo") <= setning.length()) << endl;

  int index = 0;
  int length = setning.length();

  string sub = setning;
  while(index < length && index >= 0) {
    index = sub.find("er");
    if(index > 0) {
      cout << "Fant 'er' på plass: " << index << endl;
      sub = sub.substr(index + 2, sub.length());
    }
  }

  return 0;
}
