#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
 int number;
 Node *next;
};

class myStack {
private:
    Node *mtop;
    int _size;
public:
    myStack();
    myStack(const myStack &stack);
    myStack(const int *arr, const int _size); // 用数组构造,按顺序压栈
    ~myStack();
    bool empty() const;  // 栈空则返回true
    int top() const; // 返回栈顶元素，如果栈为空则返回0
    bool pop();
    bool push(int _number); // 请注意push失败的情况，即new失败
    int size() const;

    myStack& operator=(const myStack& stack);
    friend ostream& operator<<(ostream& out, const myStack& stack) {
    Node *t = stack.mtop;
    if (t == NULL) {
    out << "The stack is empty!";
    return out;
    }
    while (t != NULL) {
    out << t->number << ' ';
    t = t->next;
    }
    return out;
    }
    ;
};
myStack::myStack(){
    _size=0;
    mtop=NULL;
}
myStack::myStack(const myStack &stack){
    _size=stack._size;
    if(_size==0){
        mtop=NULL;
    }
    else {
        mtop=new Node;
        mtop->number=stack.mtop->number;
        Node* temp=stack.mtop;
        Node* s=mtop;
        while(temp->next!=NULL){
            s->next=new Node;
            s=s->next;
            temp=temp->next;
            s->number=temp->number;
            s->next=NULL;
        }
    }
}
myStack::myStack(const int *arr, const int size){
    _size=size;
    Node* temp=NULL;
    mtop=NULL;
    Node* s=NULL;
    if(size!=0){
        for(int i=0;i<size;i++){
            temp=new Node;
            temp->next=mtop;
            temp->number=arr[i];
            mtop=temp;
        }
    }
    else{
        _size=0;
        mtop=NULL;
    }
} // 用数组构造,按顺序压栈
myStack::~myStack(){
    Node* temp=NULL;
	while(mtop!=NULL){
        temp=mtop;
        mtop=mtop->next;
        delete temp;
    }
}
bool myStack::empty() const{
    return _size==0;
} // 栈空则返回true
int myStack::top() const{
    if(_size==0){
        return 0;
    }
    else{
        return mtop->number;
    }
} // 返回栈顶元素，如果栈为空则返回0
bool myStack::pop(){
    if(_size!=0){
        Node* temp=mtop;
        mtop=mtop->next;
        delete temp;
        _size--;
        return true;
    }
    else{
        return false;
    }
}
bool myStack::push(int _number){
    Node* temp=new Node;
    temp->next=mtop;
    temp->number=_number;
    mtop=temp;
    _size++;
    return true;
}
    // 请注意push失败的情况，即new失败
int myStack::size() const{
    return _size;
}
myStack& myStack::operator=(const myStack& stack){
    if(_size!=0){
        this->~myStack();
    }
    _size=stack._size;
    if(_size==0){
        mtop=NULL;
    }
    else {
        mtop=new Node;
        mtop->number=stack.mtop->number;
        Node* temp=stack.mtop;
        Node* s=mtop;
        while(temp->next!=NULL){
            s->next=new Node;
            s=s->next;
            temp=temp->next;
            s->number=temp->number;
            s->next=NULL;
        }
    }
    return *this;
}

int main() {
 int a[100];
 int n, m, num;
 cin >> n >> m;
 myStack s1;
 cout << "s1 is empty? " << s1.empty() << endl;
 for (int i = 0; i < n/2; ++i) {
  cin >> num;
  s1.push(num);
 }
 cout << "s1's size is " << s1.size() << endl;
 myStack s2(s1), s3;
 for (int i = 0;  i < m; ++i) {
  s1.pop();
 }
 cout << "now s1's size is " << s1.size() << endl;
 for (int i = n/2; i < n; ++i) {
  cin >> num;
  s1.push(num); s3.push(num);
 }
 cout << "s1's size is " << s1.size() << endl;
 cout << "s1 is " << s1 << endl;
 cout << "s3 is " << s3 << endl;
 cout << "s2's top is " << s2.top() << endl;
 s2.pop();
 cout << "s2 is "  << s2 << endl;
 cout << "s2 is empty?" << s2.empty() << endl;
 s2 = s1;
 cout << "now s2 is " << s2 << endl;
 cin >> n;
 for (int i = 0; i < n; ++i) {
  cin >> a[i];
 }
 myStack s4(a, n);
 cout << "s4's size is " << s4.size() << endl;
 cout << "s4 is " << s4 << endl;
 s3 = s4; s3.pop();
 cout << "s3 is " << s3 << endl;
 return 0;
}
