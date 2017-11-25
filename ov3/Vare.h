#include <iostream>
using namespace std;

double MOMS = 1.24;

class Vare {
public:
    Vare(string navn, int varenr, double pris);
    string finnNavn() const;
    int finnVarenr() const;
    double finnPrisPrEnhet() const;
    void settPris(double nyPris);
    double finnPrisUtenMoms(double enheter) const;
    double finnPrisMedMoms(double enheter) const;

private:
    string varenavn;
    int varenr;
    double pris;
};

Vare::Vare(string navn, int varenr, double pris) : varenavn(navn), varenr(varenr), pris(pris) {}
string Vare::finnNavn() const { return varenavn; }
int Vare::finnVarenr() const { return varenr; }
double Vare::finnPrisPrEnhet() const { return pris; }
void Vare::settPris(double nyPris) { pris = nyPris; }
double Vare::finnPrisUtenMoms(double enheter) const { return pris * enheter; }
double Vare::finnPrisMedMoms(double enheter) const { return (pris * enheter) * MOMS; }
