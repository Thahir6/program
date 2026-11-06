// N-QUEENS PROBLEM
#include<iostream>
using namespace std;

int b[20][20],n;

bool safe(int r,int c){
    for(int i=0;i<r;i++)
        if(b[i][c]) return false;
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
        if(b[i][j]) return false;
    for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++)
        if(b[i][j]) return false;
    return true;
}
bool solve(int r){
    if(r==n) return true;
    for(int c=0;c<n;c++)
        if(safe(r,c)){
            b[r][c]=1;
            if(solve(r+1)) return true;
            b[r][c]=0;
        }
    return false;
}
int main(){
    cin>>n;
    if(solve(0))
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<b[i][j]<<" ";
            cout<<endl;
        }
    else cout<<"No solution";
}