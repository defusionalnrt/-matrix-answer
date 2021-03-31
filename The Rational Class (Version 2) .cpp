#include<iostream>
#include<string>
using namespace std;
class Rational {
 public:
  Rational();
  Rational(long numerator, long denominator);
  long getNumerator();
  long getDenominator();
  Rational add(Rational &secondRational);
  Rational subtract(Rational &secondRational);
  Rational multiply(Rational &secondRational);
  Rational divide(Rational &secondRational);
  int compareTo(Rational &secondRational);
  bool equals(Rational &secondRational);
  int intValue(); //Returns the numerator/denominator
  double doubleValue(); //Returns 1.0*numberator/denominator
  string toString();
  bool operator<(Rational &secondRational);
  bool operator<=(Rational &secondRational);
  bool operator>(Rational &secondRational);
  bool operator>=(Rational &secondRational);
  bool operator!=(Rational &secondRational);
  bool operator==(Rational &secondRational);
  Rational operator+(Rational &secondRational);
  Rational operator-(Rational &secondRational);
  Rational operator*(Rational &secondRational);
  Rational operator/(Rational &secondRational);
  Rational operator+=(Rational &secondRational);
  Rational operator-=(Rational &secondRational);
  Rational operator*=(Rational &secondRational);
  Rational operator/=(Rational &secondRational);
  Rational operator++();
  Rational operator--();
  Rational operator++(int dummy);
  Rational operator--(int dummy);
  Rational operator+();
  Rational operator-();
  long& operator[] (int );
  friend ostream &operator<<(ostream &stream, Rational &rational);
  friend istream &operator>>(istream &stream, Rational &rational);
  operator double();
 private:
  long numerator; 
  long denominator; 
  static long gcd(long n, long d);
};
long min(long a,long b){
    return (a>b)?b:a;
}

long gcd(long &n,long &d){
    long x=min(n,d);
    long p=1;
    for(long i=2;i<=x;i++){
        if(n%i==0&&d%i==0){
            p=i;
        }
    }
    n/=p;
    d/=p;
    return 0;
}
long agcd(long &n,long &d){
    long x=min(n,d);
    long p=1;
    for(long i=2;i<=x;i++){
        if(n%i==0&&d%i==0){
            p=i;
        }
    }
    n/=p;
    d/=p;
    return 0;
}
Rational::Rational()
{ 
  numerator = 0;  
  denominator = 1; 
}
Rational::Rational(long numerator, long denominator){
    agcd(numerator,denominator);
    this->numerator=numerator;
    this->denominator=denominator;
}
long Rational::getNumerator(){
    return numerator;
}
long Rational::getDenominator(){
    return denominator;
}
Rational Rational::add(Rational &secondRational){
    long p=numerator*secondRational.denominator+secondRational.numerator*denominator;
    long q=denominator*secondRational.denominator;
    agcd(p,q);
    Rational a(p,q);
    return a;
}
Rational Rational::subtract(Rational &secondRational){
    long p=numerator*secondRational.denominator-secondRational.numerator*denominator;
    long q=denominator*secondRational.denominator;
    agcd(p,q);
    Rational a(p,q);
    return a;
}
Rational Rational::multiply(Rational &secondRational){
    long p=numerator*secondRational.numerator;
    long q=denominator*secondRational.denominator;
    agcd(p,q);
    Rational a(p,q);
    return a;
}
Rational Rational::divide(Rational &secondRational){
    long p=numerator*secondRational.denominator;
    long q=denominator*secondRational.numerator;
    agcd(p,q);
    Rational a(p,q);
    return a;
}
int Rational::compareTo(Rational &secondRational){
    return (numerator*secondRational.denominator>secondRational.numerator*denominator)?1:0;
}
bool Rational::equals(Rational &secondRational){
    return (numerator*secondRational.denominator==denominator*secondRational.numerator)?true:false;
}
int Rational::intValue(){
    return numerator/denominator;
}
//Returns the numerator/denominator
double Rational::doubleValue(){
    return 1.0*numerator/denominator*1.0;
} //Returns 1.0*numberator/denominator
string Rational::toString()
{
  char s[50];
  if ( denominator == 1) {  
    sprintf(s,"%ld",numerator);
  } else {
    sprintf(s,"%ld/%ld",numerator,denominator);
  }
  return string(s);
}
bool Rational::operator<(Rational &secondRational){
    return !compareTo(secondRational)&&equals(secondRational);
}
bool Rational::operator<=(Rational &secondRational){
    return !compareTo(secondRational);
}
bool Rational::operator>(Rational &secondRational){
    return compareTo(secondRational);
}
bool Rational::operator>=(Rational &secondRational){
    if(compareTo(secondRational)==0){
        return equals(secondRational);
    }
    else{
        return false;
    }
}
bool Rational::operator!=(Rational &secondRational){
    return !equals(secondRational);
}
bool Rational::operator==(Rational &secondRational){
    return equals(secondRational);
}
Rational Rational::operator+(Rational &secondRational){
    return add(secondRational);
}
Rational Rational::operator-(Rational &secondRational){
    return subtract(secondRational);
}
Rational Rational::operator*(Rational &secondRational){
    return multiply(secondRational);
}
Rational Rational::operator/(Rational &secondRational){
    return divide(secondRational);
}
Rational Rational::operator+=(Rational &secondRational){
    *this=*this+secondRational;
    return *this;
}
Rational Rational::operator-=(Rational &secondRational){
    *this=*this-secondRational;
    return *this;
}
Rational Rational::operator*=(Rational &secondRational){
    *this=*this*secondRational;
    return *this;
}
Rational Rational::operator/=(Rational &secondRational){
    *this=*this/secondRational;
    return *this;
}
Rational Rational::operator++(){
    numerator+=denominator;
    return *this;
}
Rational Rational::operator--(){
    numerator-=denominator;
    return *this;
}
Rational Rational::operator++(int dummy){
    Rational p(numerator,denominator);
    numerator+=denominator;
    return p;
}
Rational Rational::operator--(int dummy){
    Rational p(numerator,denominator);
    numerator-=denominator;
    return p;
}
Rational Rational::operator+(){
    return *this;
}
Rational Rational::operator-(){
    Rational p(-numerator,denominator);
    return p;
}
long& Rational::operator[] (int a){
    if(a==0){
        return numerator;
    }
    else{
        return denominator;
    }
}
ostream &operator<<(ostream &stream, Rational &rational){
    stream<<rational.toString();
    return stream;
}
istream &operator>>(istream &stream, Rational &rational){
    stream>>rational.numerator>>rational.denominator;
    return stream;
}
Rational::operator double(){
    return doubleValue();
}
int main()
{
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(3, 2);
  Rational r2(2, 3);

  // Test relational operators
  cout << r1 << " > " << r2 << " is " << (r1 > r2) << endl;
  cout << r1 << " >= " << r1 << " is " << (r1 >= r1) << endl; 
  cout << r1 << " < " << r2 << " is " << (r1 < r2) << endl;
  cout << r1 << " <= " << r1 << " is " << (r1 <= r1) << endl;
  cout << r1 << " == " << r2 << " is " << (r1 == r2) << endl;
  cout << r1 << " == " << r1 << " is " << (r1 == r1) << endl;
  cout << r1 << " != " << r2 << " is " << (r1 != r2) << endl;
  cout << r1 << " != " << r1 << " is " << (r1 != r1) << endl;


  // Test toString, add, substract, multiply, and divide operators
  cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
  cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
  cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
  cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;

  // Test shorthand operators
  Rational r3(1, 2);
  r3 += r1;
  cout << "r3 is " << r3 << endl;
  r3 -= r1;
  cout << "r3 is " << r3 << endl;
  
  // Test function operator []
  Rational r4(1, 2);
  r4[0] = 3; r4[1] = 4;
  cout << "r4 is " << r4 << endl;

  // Test function operators for 
  // prefix ++ and --
  // postfix ++ and --
  r3 = r4++;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;
  r3 = r4--;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;


  r3 = ++r4;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;
  r3 = --r4;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;

  // Test function operator for conversion
  cout << "1 + " << r4 << " is " << (1 + r4) << endl;

  return 0;
}
