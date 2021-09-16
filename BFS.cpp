#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n,s,t;
    bool success=false;//用success来记录是否成功
    cin>>n>>s>>t;
    vector<vector<int> > mat(n,vector<int>(n,0));//记录矩阵信息
    vector<bool> pass(n,1);//记录第i个节点是否搜索过
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    queue<int> qt;
    qt.push(s);
    while(qt.size()){
        int temp=qt.front();//取队头并弹出
        qt.pop();
        pass[temp]=false;
        for(int i=0;i<n;i++){
            if(pass[i]&&mat[temp][i]){
                if(i==t){//这种情况对应找到路径，直接跳出循环，改变success为true
                    success=true;
                    break;
                }
                qt.push(i);
                pass[i]=false;//标记已经搜索过
            }
        }
    }
    if(success){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}