#include <iostream>
#include <cstdlib>
using namespace std;
typedef int ELEMENT;  // 为堆栈元素类型起一个别名
struct NODE {
     ELEMENT element;	// 存放堆栈的元素
     NODE* link;		// 指向下一个结点的链接
};
class STACK {
public:
     STACK();   // 构造函数，设置栈顶为空指针
     ~STACK(); // 析构函数，释放堆栈结点占用的存储空间
	
     void push(ELEMENT obj);  // 将元素obj压入栈顶
     void pop();  // 将当前栈顶的元素弹出栈中。要求：栈不为空。
     ELEMENT get_top() const;  // 返回当前栈顶的元素值。要求：栈不为空。
     bool is_empty() const;  // 判断当前堆栈是否为空，空则返回true，非空则返回false
     void display() const;  // 自顶向下显示堆栈中的元素

private:
    NODE* top;	// 堆栈的栈顶
};
STACK::STACK(){
    top=NULL;
}   // 构造函数，设置栈顶为空指针
STACK::~STACK(){
    NODE* temp=top;
    if(temp){
        temp=temp->link;
        delete top;
        top=temp;
    }

} // 析构函数，释放堆栈结点占用的存储空间

void STACK::push(ELEMENT obj){
    NODE* temp=new NODE ;
    temp->element=obj;
    temp->link=top;
    top=temp;
}  // 将元素obj压入栈顶
void STACK::pop(){
    if(!is_empty()){
        NODE* temp=top;
        top=top->link;
        delete temp;
    }
}  // 将当前栈顶的元素弹出栈中。要求：栈不为空。
ELEMENT STACK::get_top() const{
    return top->element;
}  // 返回当前栈顶的元素值。要求：栈不为空。
bool STACK::is_empty() const{
    if(top){
        return false;
    }
    else{
        return true;
    }
}  // 判断当前堆栈是否为空，空则返回true，非空则返回false
void STACK::display() const{
    NODE* temp=top;
    while(temp){
        cout<<temp->element<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
int main()
{

    STACK turner;       // 声明一个元素为整数类型的堆栈
    ELEMENT user_input; // 用户输入的元素（即整数类型）
    int loop;           // 循环变量
    int max_input = 20;
    for (loop = 1; loop <= max_input; loop++) // 由用户输入若干个元素
    {
        turner.push(loop); // 将用户输入的元素压入栈中
    }

    turner.display(); // 测试堆栈中的内容

    for (loop = 1; loop <= max_input; loop++)
    {
        if (!turner.is_empty()) // 仅当堆栈不为空时才处理
        {
            user_input = turner.get_top();        // 取出栈顶元素的值
            turner.pop();                         // 将栈顶元素弹出
            cout <<loop<<" "<< user_input << endl;
        }
    }


    return 0;
}
