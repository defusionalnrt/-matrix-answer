 #include <iostream>
 using std::cin;
using std::cout;
using std::endl;
using std::string;
 class baseA{
public:
     baseA();
     ~baseA();
 };
 class derivedA:public baseA{
public:
     derivedA();
     ~derivedA();
 };
 class baseB{
public:
     baseB();
     ~baseB();
 };
 class derivedB:public baseA,public baseB{
 public:
     derivedB();
     ~derivedB();
 };

 
 class C:public derivedA,public derivedB{
public:
     C();
     ~C();
     
 };