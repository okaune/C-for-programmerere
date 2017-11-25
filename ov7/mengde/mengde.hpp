#include <vector>

#ifndef MENGDE
#define MENGDE
class Mengde {
public:
  Mengde();
  Mengde(std::vector<int> verdier);
  Mengde operator+(Mengde &mengde) const;
  Mengde operator+(const int val) const;
  void operator=(Mengde &mengde);
  std::vector<int> getVerdier() { return verdier; };

private:
  std::vector<int> verdier;
};
#endif
