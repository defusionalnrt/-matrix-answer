#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s;
    while(cin>>s){
        stack<char> st;
        for(auto i:s){
            if(i=='('||i=='{'||i=='['){
                st.push(i);//左括号直接入栈
            }
            else{
                if(i==')'){//右括号的情况，}与]也类似处理
                    if(st.empty()){
                        goto flag;//先判断栈是否为空，若为空则未匹配，用goto直接跳出循环
                    }
                    if(st.top()=='('){
                        st.pop();//如果匹配成功则弹出栈顶
                    }
                    else{
                        goto flag;//匹配失败，goto跳出
                    }
                }
                else if(i=='}'){
                    if(st.empty()){
                        goto flag;
                    }
                    if(st.top()=='{'){
                        st.pop();
                    }
                    else{
                        goto flag;
                    }
                }
                else if(i==']'){
                    if(st.empty()){
                        goto flag;
                    }
                    if(st.top()=='['){
                        st.pop();
                    }
                    else{
                        goto flag;
                    }
                }
                else{
                }
            }
        }
        if(st.empty()==true){//循环结束后还需判断栈是否为空
            cout<<"Yes"<<endl;
        }
        else{
            flag:cout<<"No"<<endl;//匹配失败，输出“No”
        }
    }
    return 0;
}