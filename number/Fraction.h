class Fraction
{
 private:
  int mNum;
  int mDen;

  void simplify();

 public:
  Fraction(const Fraction& f) : mNum{f.mNum}, mDen{f.mDen} {}
  Fraction(int num, int den);
  Fraction(int num) : mNum{num}, mDen{1} { simplify(); }
  Fraction() : mNum{0}, mDen{1} {}

  int num() const { return mNum; }
  void num(int num) { mNum = num; }

  int den() const { return mDen; }
  void den(int den) { mDen = den != 0 ? den : 1; } //

  //operator double() { return (double) mNum / (double) mDen; }
  double dbl() const { return (double) mNum / (double) mDen; }
  
  Fraction& operator=(const Fraction& f);
  Fraction& operator+=(const Fraction& f);
  Fraction& operator-=(const Fraction& f);
  Fraction& operator*=(const Fraction& f);
  Fraction& operator/=(const Fraction& f);

  friend Fraction operator+(const Fraction& a, const Fraction& b);
  friend Fraction operator-(const Fraction& a, const Fraction& b);
  friend Fraction operator*(const Fraction& a, const Fraction& b);
  friend Fraction operator/(const Fraction& a, const Fraction& b);

  friend bool operator==(const Fraction& a, const Fraction& b);
  friend bool operator!=(const Fraction& a, const Fraction& b);
  friend bool operator<(const Fraction& a, const Fraction& b);
  friend bool operator>(const Fraction& a, const Fraction& b);
  friend bool operator<=(const Fraction& a, const Fraction& b);
  friend bool operator>=(const Fraction& a, const Fraction& b);
    
  friend Fraction operator+(const Fraction& f);
  friend Fraction operator-(const Fraction& f);

  friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
  friend std::istream& operator>>(std::istream& os, const Fraction& f);
  
};
