#include <iostream>
using namespace std;
class Person{
private:	
    string name;
public:
    static int person_num;
    Person(string name);
    virtual ~Person();
    string getName();
    virtual void sayHi();
};
class Student : public Person{
public:
    static int student_num;
    Student(string name);
    ~Student();
    void sayHi();
};
void Person::sayHi(){
    cout<<"Hi! My name is "<<name<<"."<<endl;
}
int Student::student_num=0;
int Person::person_num=0;
Person::Person(string s){
    person_num++;
    name=s;
}

Person::~Person(){
    person_num--;
}
string Person::getName(){
    return name;
}
Student::Student(string name):Person(name){
    student_num++;
}
Student::~Student(){
    student_num--;
}
void Student::sayHi(){
    cout<<"Hi! My name is "<<getName();
    cout<<". I have ";
    if(Student::student_num==1){
        cout<<"no classmates";
    }
    else if(Student::student_num==2){
        cout<<"only 1 classmate";
    }
    else{
        cout<<Student::student_num-1<<" classmates";
    }
    cout<<" here."<<endl;
}
void total(){
    if(Person::person_num){
        cout<<"There are "<<Person::person_num<<" people and ";
        if(Student::student_num==0){
            cout<<"none ";
        }
        else if(Student::student_num==1){
            cout<<"only 1 ";
        }
        else{
            cout<<Student::student_num<<" ";
        }
        cout<<"of them ";
        if(Student::student_num==1){
            cout<<"is";
        }
        else{
            cout<<"are";
        }
        cout<<" students."<<endl;
    }
    else{
        cout<<"There is nobody here."<<endl;
    }
}

void clear(){
	Person::person_num = 0;
	total();
}

int main(){
	int curr_people = 0, person_num = 0;
	cin >> curr_people >> person_num;
	Person* people_list[person_num];
	Person::person_num += curr_people;
	for(int i = 0; i < person_num; ++i){
		string name = "";
		int isStudent = 0;
		cin >> isStudent >> name;
		if(isStudent){
			people_list[i] = new Student(name);
			people_list[i]->sayHi();
		}
		else{
			people_list[i] = new Person(name);
			people_list[i]->sayHi();
		}
	}
	total();
	// 学生以及教职工退场
	cout << endl;
	for(int i = 0; i < person_num; ++i){
		delete people_list[i];
		total();
	}
	clear(); // 嘉宾以及举办方离场
	return 0;
}