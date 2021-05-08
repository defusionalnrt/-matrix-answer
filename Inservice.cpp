#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(){
        cout<<"Construct Person"<<endl;
    };
    Person(string name,int sex){
        this->name=name;
        this->sex=sex;
        cout<<"Construct Person"<<endl;
    }
    string getName(){
        return name;
    }
    int getSex(){
        return sex;
    }
    ~Person(){
        cout<<"Destruct Person"<<endl;
    }
protected:
    int sex;
    string name;
};
class Student: virtual public Person{
public:
    Student(){
        cout<<"Construct Student"<<endl;
    };
    Student(string s,int sex,string ss):Person(s,sex){
        sno=ss;
    }
    Student(Student&another):Person(another.name,another.sex){
        sno=another.sno;
        cout<<"Construct Student"<<endl;
    }
    
    ~Student(){
        cout<<"Destruct Student"<<endl;
    }
    string getSno(){
        return sno;
    }
protected:
    string sno;
};
class Worker: virtual public Person{
public:
    Worker(){
      cout<<"Construct Worker"<<endl;
    };
    Worker(string s,int sex, string ss):Person(s,sex){
        wno=ss;
    }
    Worker(Worker&another):Person(another.name,another.sex){
        wno=another.wno;
        cout<<"Construct Worker"<<endl;
    }
    ~Worker(){
        cout<<"Destruct Worker"<<endl;
    }
    string getWno(){
        return wno;
    }
protected:
    string wno;
};
class InService: public Student,public Worker{
public:
    InService(string s,int sexb,string ss,string sss){
        name=s;
        sno=ss;
        wno=sss;
        sex=sexb;
        cout<<"Construct InService"<<endl;
    }
    ~InService(){
        cout<<"Destruct InService"<<endl;
    }
};

int main() {
    string name, sno, wno;
    int sex;

    cin >> name;
    cin >> sex;
    cin >> sno;
    cin >> wno;

    InService is(name, sex, sno, wno);

    Person* p = &is;
    Student* s = &is;
    Worker* w = &is; 
 
    cout << p->getName() << endl;
    cout << p->getSex() << endl;
    cout << s->getName() << endl;
    cout << s->getSex() << endl;
    cout << s->getSno() << endl;
    cout << w->getName() << endl;
    cout << w->getSex() << endl;
    cout << w->getWno() << endl;
    return 0;
}