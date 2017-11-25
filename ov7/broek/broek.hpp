#ifndef BROEK_DEFINERT
#define BROEK_DEFINERT

class Broek {
public:
  Broek();
  Broek(int initTeller, int initNevner);
  void settBroek(int nyTeller, int nyNevner = 1);
  int finnTeller() const { return teller; }
  int finnNevner() const { return nevner; }
  int toInt() const;
  Broek operator+(const Broek &denAndre) const;
  Broek operator-(const Broek &denAndre) const;
  Broek operator-(const int integer) const;
  Broek operator*(const Broek &denAndre) const;
  Broek operator/(const Broek &denAndre) const;
  Broek operator-() const;
  Broek &operator++(); // Preinkrement
  Broek &operator--(); // Predekrement
  Broek &operator+=(const Broek &denAndre);
  Broek &operator-=(const Broek &denAndre);
  Broek &operator*=(const Broek &denAndre);
  Broek &operator/=(const Broek &denAndre);
  Broek &operator=(const Broek &original);
  bool operator==(const Broek &denAndre) const;
  bool operator!=(const Broek &denAndre) const;
  bool operator<=(const Broek &denAndre) const;
  bool operator>=(const Broek &denAndre) const;
  bool operator<(const Broek &denAndre) const;
  bool operator>(const Broek &denAndre) const;

private:
  void forkort();
  int sammenlikn(const Broek &denAndre) const;
  int teller;
  int nevner;
};
#endif
