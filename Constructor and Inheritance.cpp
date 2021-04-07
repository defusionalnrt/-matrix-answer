#include <iostream>
#include <string>
#include <vector>
using namespace std;


class B
{
public:
    B(int, int);
    void show();
private:
    int b;
};
B::B(int a,int bb){
	A aa(a);
	aa.show();
	b=bb;
}
void B::show(){
	cout<<"b="<<b<<endl;
}