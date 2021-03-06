#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int num=0;
typedef struct aa{
  int x;
  int y;
}friending;
class person{
public:
    int id;
    
    person(){
      id=num;
      num++;
    }
};
class group {
private:
    bool gp;
public:
    bool at[10000]={0};
    vector <int> list;
    vector <int> listn;
    vector <friending> friendship;
    group(int a){
        list.clear();
        listn.clear();
        if(a){
          gp=true;
        }
        else{
          gp=false;
        }
    }
    void displayGroup(){
        int p=0;
        int k;
        for(int i=0;i<list.size();i++){
          p=0;
          if(list[i]!=-1){
            cout<<"Person_"<<list[i]<<": ";
            for(int j=0;j<friendship.size();j++){
              if(friendship[j].x==list[i]){
                p++;
                k=friendship[j].y;
                if(p==1){
                  cout<<k;
                }
                else{
                  cout<<", "<<k;
                }
              }
              else if(friendship[j].y==list[i]){
                p++;
                k=friendship[j].x;
                if(p==1){
                  cout<<k;
                }
                else{
                  cout<<", "<<k;
                }
              }
            }
            if(p==0){
              cout<<"null";
            }
            cout<<endl;
          }
        }
    }
    void addMember(person &p){
        if(gp){
          for(int i=0;i<list.size();i++){
            if(list[i]!=-1){
              friending a;
              a.x=list[i];
              a.y=p.id;
              friendship.push_back(a);
            }
          }
        }
        list.push_back(p.id);
        listn.push_back(p.id);
    }
    void deleteMember(person &p){
        for(int i=0;i<list.size();i++){
          if(list[i]==p.id){
            list[i]=-1;
          }
        }
    }
    void makeFriend(person &p1, person &p2){
      friending a;
      a.x=p1.id;
      a.y=p2.id;
      friendship.push_back(a);
    }
    void breakRelation(person &p1, person &p2){
      for(int i=0;i<friendship.size();i++){
        if((p1.id==friendship[i].x&&p2.id==friendship[i].y)||(p2.id==friendship[i].x&&p1.id==friendship[i].y)){
          friendship[i].x=friendship[i].y=-1;
        }
      }
    }
};
 void test_1() {
    person mike, jack, lily, carson, sucie;
    group school(0), family_1(1), family_2(1);
    // make group (act as a society)
    school.addMember(mike);
    school.addMember(jack);
    school.addMember(lily);
    family_1.addMember(mike);
    family_1.addMember(carson);
    family_2.addMember(jack);
    family_2.addMember(lily);
    family_2.addMember(sucie);
    // construct relationship in the society
    school.makeFriend(mike, jack);
    school.makeFriend(mike, lily);
    // display the society
    cout << "\n------ SCHOOL -----\n";
    school.displayGroup();
    cout << "\n------ FAMILY_1 -----\n";
    family_1.displayGroup();
    cout << "\n------ FAMILY_2 -----\n";
    family_2.displayGroup();
}
 void test_2() {
    person Baidu, Alibaba, Tencent, NTES, Kingsoft_Antivirus, _360safe;
    group BAT(1), ECommerce(1), Security(1);
    // make group (act as a society)
    BAT.addMember(Baidu);
    BAT.addMember(Alibaba);
    BAT.addMember(Tencent);
    ECommerce.addMember(Baidu);
    ECommerce.addMember(Alibaba);
    ECommerce.addMember(Tencent);
    ECommerce.addMember(NTES);
    Security.addMember(Kingsoft_Antivirus);
    Security.addMember(_360safe);
    // display the society
    cout << "\n------ BAT -----\n";
    BAT.displayGroup();
    cout << "\n------ ECommerce -----\n";
    ECommerce.displayGroup();
    cout << "\n------ Security -----\n";
    Security.displayGroup();
}
 void test_3() {
    person p0, p1, p2, p3, p4;
    group g0(0), g1(0), g2(1);
    // make group (act as a society)
    g0.addMember(p0);
    g0.addMember(p1);
    g0.addMember(p2);
    g1.addMember(p0);
    g1.addMember(p3);
    g2.addMember(p3);
    g2.addMember(p4);
    // construct relationship in the society
    g1.makeFriend(p0, p3);
    g2.breakRelation(p3, p4);
    g0.deleteMember(p2);
    // display the society
    cout << "\n------ G0 -----\n";
    g0.displayGroup();
    cout << "\n------ G1 -----\n";
    g1.displayGroup();
    cout << "\n------ G2 -----\n";
    g2.displayGroup();
}
 void test_4() {
    person p[50];
    group g0(0), g1(1);
    int p_count;
    cin >> p_count;
    // make group (act as a society)
    for (int i = 0; i < p_count/2; i++)
        g0.addMember(p[i]);
    for (int i = p_count/2; i < p_count; i++)
        g1.addMember(p[i]);
    // construct relationship in the society
    for (int i = 0; i < p_count/5; i += 2)
        g0.makeFriend(p[i], p[i+1]);
    for (int i = p_count/2; i < p_count*3/4-1; i += 2)
        g1.breakRelation(p[i], p[i+1]);
    for (int i = p_count/4; i < p_count/2; i++)
        g0.deleteMember(p[i]);
    for (int i = p_count*3/4; i < p_count; i++)
        g1.deleteMember(p[i]);
    // display the society
    cout << "\n------ G0 -----\n";
    g0.displayGroup();
    cout << "\n------ G1 -----\n";
    g1.displayGroup();
}
 int main() {
    int test_id;
    cin >> test_id;
    switch (test_id) {
        case 1:
        test_1();
        break;
        case 2:
        test_2();
        break;
        case 3:
        test_3();
        break;
        case 4:
        test_4();
        break;
        default:
        cout << "wrong input\n";
    }
    return 0;
}
 /* ---------- structure for 'world.h' ----------
 * define the struct and the class functions by yourself #(^_^)#
 * the member function is not complete, add something as you need
 struct person;
 class group {
    void displayGroup();
    bool addMember(person &p);
    bool deleteMember(person &p);
    bool makeFriend(person &p1, person &p2);
    bool breakRelation(person &p1, person &p2);
};
 */
//#($ _ $)#!