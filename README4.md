// TRAVELLING SALESPERSON PROBLEM
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int a[10][10],v[10],p[10],best[10],n;
int mn=INT_MAX,edge=INT_MAX;

void TSP(int c,int cnt,int sum){
    if(cnt==n){
        if(a[c][0]&&sum+a[c][0]<mn){
            mn=sum+a[c][0];
            for(int i=0;i<n;i++) best[i]=p[i];
        }
        return;
    }
    if(sum+(n-cnt+1)*edge>=mn) return;

    for(int i=0;i<n;i++)
        if(!v[i]&&a[c][i]){
            v[i]=1; p[cnt]=i;
            TSP(i,cnt+1,sum+a[c][i]);
            v[i]=0;
        }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(i!=j&&a[i][j]>0)
                edge=min(edge,a[i][j]);
        }
    v[0]=1; p[0]=0;
    TSP(0,1,0);

    if(mn==INT_MAX) cout<<"No tour exists";
    else{
        cout<<"Minimum Cost: "<<mn<<"\nPath: ";
        for(int i=0;i<n;i++) cout<<best[i]<<" ";
        cout<<0;
    }
}