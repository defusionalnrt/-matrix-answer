#include <iostream>
#include <sstream>
using namespace std;
#include <string>
 class Account {
  protected:
    int _id;
    double _balance;
    bool _valid;
    static int _total_account;
  public:
    Account();
    ~Account();
    int id() const;
    double balance() const;
    bool valid() const;
    std::string profile() const;
    void reset();
    bool deposit(const double &num);
    bool draw(const double &num);
    static int get_total_account();
};
int Account::_total_account=0;

Account::Account(){
    _id=0;
    _balance=0.0;
    _valid=false;
    _total_account++;
}
Account::~Account(){
    _total_account--;
}
int Account::id() const{
    return _id;
}
double Account::balance() const{
    return _balance;
}
bool Account::valid() const{
    return _valid;
}
std::string Account::profile() const{
    string res="ID:";
    res+=to_string(_id);
    res+="\nBALANCE:";
    res+=to_string(_balance);
    res+="\nVALID:N\n";
    return res;
}

void Account::reset(){
    _valid=false;
    _balance=0.0;
}
bool Account::deposit(const double &num){
    if(_valid){
        _balance+=num;
    }
    return _valid;
}
bool Account::draw(const double &num){
    if(_balance>num){
      _balance-=num;
      return true;
    }
    else{
      return false;
    }
}
int Account::get_total_account(){
    return _total_account;
}
class VIPAccount : public Account {
  private:
    static int _total_vip_account;
    static int _acc_id_ptr;
  protected:
    double _loan;
    double _loan_limit;  // initial as 1k
  public:
    VIPAccount();
    ~VIPAccount();
    bool loan(const double &num);
    bool repay(const double &num);
    // override
    std::string profile() const;
    void reset();
    // static
    static int get_total_vip_account();
};
int VIPAccount::_total_vip_account=0;
int VIPAccount::_acc_id_ptr=0;
 VIPAccount::VIPAccount(){
     _id=_acc_id_ptr+12050000 ;
     _acc_id_ptr++;
     
     _total_vip_account++;
     _balance=10;
     _valid=true;
     _loan=0;
     _loan_limit=1000;
 }
    VIPAccount::~VIPAccount(){
        _total_vip_account--;
        _total_account--;
    }
    bool VIPAccount::loan(const double &num){
        if(num+_loan>_loan_limit){
            return false;
        }
        else{
            _loan+=num;
            _balance+=num;
            return true;
        }
    }
    bool VIPAccount::repay(const double &num){
        if(num>_balance||num>_loan){
            return false;
        }
        else{
            _balance-=num;
            _loan-=num;
            return true;
        }
    }
    // override
    std::string VIPAccount::profile() const{
      string res="ID:";
      res+=to_string(_id);
      res+="\nBALANCE:";
      res+=to_string(_balance);
      res+="\nVALID:Y\nTYPE:VIP\nLOAN:";
      res+=to_string(_loan);
      res+=",LIMIT:";
      res+=to_string(_loan_limit);
      res+="\n";
      return res;
    }
    void VIPAccount::reset(){
        _balance=10;
        _valid=true;
        _loan=0;
        _loan_limit=1000;
    }
    // static
    int VIPAccount::get_total_vip_account(){
        return _total_vip_account;
    }
class PersonalAccount : public Account {
  private:
    static int _total_per_account;
    static int _acc_id_ptr;
  public:
    PersonalAccount();
    ~PersonalAccount();
    // override
    std::string profile() const;
    void reset();
    // static
    static int get_total_per_account();
};
int PersonalAccount::_total_per_account=0;
int PersonalAccount::_acc_id_ptr=0;
PersonalAccount::PersonalAccount(){
  _id=12010000 +_acc_id_ptr;
  _balance=10.0;
  _valid=true;
  
  _acc_id_ptr++;
  _total_per_account++;
}
PersonalAccount::~PersonalAccount(){
  _total_per_account--;
  _total_account--;
}
std::string PersonalAccount::profile() const{
  string res="ID:";
  res+=to_string(_id);
  res+="\nBALANCE:";
  res+=to_string(_balance);
  res+="\nVALID:Y\nTYPE:PERSONAL\n";
  return res;
}
int PersonalAccount::get_total_per_account(){
  return _total_per_account;
}
void PersonalAccount::reset(){
  _balance=10;
  _valid=true;
}
void display_count() {
  cout << Account::get_total_account() << ",";
  cout << PersonalAccount::get_total_per_account() << ",";
  cout << VIPAccount::get_total_vip_account() << endl;
}

 
int main() {
  display_count();
  if (true) {
    Account a0, a1, a2;
    display_count();
    PersonalAccount b0, b1;
    display_count();
  }
  VIPAccount c0, c1, c2, c3;
  display_count();
 
  Account *bptr = new Account();
  cout << bptr->profile() << endl;
  cout << bptr->id() << bptr->balance() << bptr->valid() << endl;
  delete bptr;
 
  PersonalAccount *pptr = new PersonalAccount();
  cout << pptr->profile() << endl;
  for (int i = 0; i < 5; ++i) {
    double t;
    int op;
    cin >> op >> t;
    if (op < 5) {
      cout << pptr->deposit(t) << ", ";
    } else {
      cout << pptr->draw(t) << ", ";
    }
    cout << pptr->balance() << endl;
  }
  cout << pptr->profile() << endl;
  pptr->reset();
  cout << pptr->profile() << endl;
  delete pptr;
 
  VIPAccount *vptr = new VIPAccount();
  cout << vptr->profile() << endl;
  for (int i = 0; i < 5; ++i) {
    double t;
    int op;
    cin >> op >> t;
    if (op < 5) {
      cout << vptr->loan(t);
    } else {
      cout << vptr->repay(t);
    }
    cout << "\n" << vptr->profile() << endl;
  }
  vptr->reset();
  cout << vptr->profile() << endl;
  delete vptr;
 
  return 0;
}
