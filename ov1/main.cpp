#include <cctype> // char-behandling
#include <cstdlib>
#include <cstring> // strengbehandling
#include <fstream>
#include <iostream> // innlesing/utskrift

using namespace std;


void askTemp(int amt);
void readTemp(double temp[], int amt);
void calcTemp(double temp[], int amt);

int main() {
  const int amt = 5;
  cout << "Oppg a)" << endl;
  askTemp(amt);
  cout << endl
       << "Oppg b)" << endl;
  double temp[amt];
  readTemp(temp, amt);
  calcTemp(temp, amt);

  return 0;
}

void askTemp(int amt) {
  int num;
  int range[3] = {0, 0, 0};
  cout << "Du skal skrive inn 5 temperaturer." << endl;
  for(int i = 0; i < amt; i++) {
    cout << "Temperatur nr " + to_string(i + 1) + ": ";
    cin >> num;
    if(num < 10)
      range[0]++;
    else if(num <= 20)
      range[1]++;
    else
      range[2]++;
  }
  cout << "Antall under 10 er " + to_string(range[0]) << endl;
  cout << "Antall mellom 10 og 20 er " + to_string(range[1]) << endl;
  cout << "Antall over 20 er " + to_string(range[2]) << endl;
}

void readTemp(double temp[], int amt) {
  const char filename[] = "temp.dat";
  ifstream infile;
  infile.open(filename);
  if(!infile) {
    cout << "Feil ved åpning av fil." << endl;
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < amt; i++) {
    infile >> temp[i];
  }

  infile.close();
}

void calcTemp(double temp[], int amt) {
  int range[3] = {0, 0, 0};
  for(int i = 0; i < amt; i++) {
    if(temp[i] < 10)
      range[0]++;
    else if(temp[i] <= 20)
      range[1]++;
    else
      range[2]++;
  }
  cout << "Antall under 10 er " + to_string(range[0]) << endl;
  cout << "Antall mellom 10 og 20 er " + to_string(range[1]) << endl;
  cout << "Antall over 20 er " + to_string(range[2]) << endl;
}
