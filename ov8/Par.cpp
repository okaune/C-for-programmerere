template <class T1, class T2>

class Par {
public:
  T1 t1;
  T2 t2;

  Par(T1 t1, T2 t2) : t1(t1), t2(t2){};

  Par operator+(Par p) {
    T1 nyT1 = t1 + p.t1;
    T2 nyT2 = t2 + p.t2;
    Par out(nyT1, nyT2);
    return out;
  }

  bool operator>(Par p) {
    return sum() > p.sum();
  }

  // Antar at casting mellom typene i paret går.
  // I tilfeller der dette ikke gjelder, må det lages spesialtilfeller.
  T1 sum() {
    return t1 + (T1)(t2);
  }
};
