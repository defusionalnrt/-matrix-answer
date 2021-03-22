
#include <bits/stdc++.h>
using namespace std;
int movex[4]={1,0,-1,0};
int movey[4]={0,1,0,-1};
int barrnum;
int barx[100],bary[100];
int xx,yy,bx,by,ex,ey;
int res=0;
bool passxy[100][100]={false};
bool bar(int gx,int gy){
    for(int j=1;j<=barrnum;j++){
        if(gx==barx[j]&&gy==bary[j]){
            return true;
        }
    }
    return false;
}

void move(int x,int y){
    if(x==ex&&y==ey){
        res++;
        return;
    }
    else{
        for(int i=0;i<4;i++){
            int gx=x+movex[i];
            int gy=y+movey[i];
            if(passxy[gx][gy]==false&&gx>=1&&gx<=xx&&gy>=1&&gy<=yy&&bar(gx,gy)==false){
                passxy[x][y]=true;
                move(gx,gy);
                passxy[x][y]=false;
            }
        }
        return;
    }
}
int main(){
    cin>>xx>>yy>>barrnum;
    cin>>bx>>by>>ex>>ey;
    for(int i=1;i<=barrnum;i++){
        scanf("%d %d",barx+i,bary+i);
    }
    memset(passxy,0,sizeof(passxy));
    passxy[bx][by]=true;
    move(bx,by);
    cout<<res<<endl;
    return 0;
}
