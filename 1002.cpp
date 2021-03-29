#include<iostream>
#include<string>
using namespace std;
class Int
{
 int i;
 public:
 
 Int(int n){    
     this->i=n;
 }
 Int(double n){
     i=n;
 }
 int getI() { return i; }
 Int& operator++(){
     i++;
     return *this;
 }
 operator int(){
     return i;
 }
 
 Int operator++(int a){
     Int b(i);
     i++;
     return b;
 }
 Int& operator--(){
     i--;
     return *this;
 }
 Int operator--(int a){
     Int b(i);
     i--;
     return b;
 }
 
 Int operator+=(Int a){
     return i+=a.i;
 }
 Int operator+=(double a){
     return i+=a;
 }
 Int operator=(int &a){
     Int b(a);
     return b;
 }
 Int operator-=(Int a){
     
     return i-=a.i;
 }
 Int operator-=(double a){
     return i-=a;
 }
 Int operator*=(Int a){
     
     return i*=a.i;
 }
 Int operator*=(double a){
     return i*=a;
 }
 Int operator/=(Int a){
     
     return i/=a.i;
 }
 Int operator/=(double a){
     return i/=a;
 }
 Int operator=(double d){
     i=d;
     return *this;
 }
 Int operator=(Int& other){
     i=other.i;
     return *this;
 }
 friend std::ostream& operator<<(std::ostream& out,const Int& a){
     out<<a.i;
     return out;
 }
 friend std::istream& operator>>(std::istream& in,Int& a){
     in>>a.i;
     return in;
 }
};