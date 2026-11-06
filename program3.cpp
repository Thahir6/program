// 0/1 KNAPSACK USING DYNAMIC PROGRAMMING
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,W,wt[20],p[20],dp[20][100]={0};
    cin>>n;
    for(int i=1;i<=n;i++) cin>>wt[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    cin>>W;

    for(int i=1;i<=n;i++)
        for(int w=0;w<=W;w++)
            dp[i][w]=(wt[i]<=w)?
            max(p[i]+dp[i-1][w-wt[i]],dp[i-1][w]):
            dp[i-1][w];

    cout<<"Maximum Profit: "<<dp[n][W];
}