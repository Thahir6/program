// JOB SEQUENCING WITH DEADLINES
#include<iostream>
#include<algorithm>
using namespace std;

struct Job{int id,d,p;};

int main(){
    int n,m=0,profit=0,slot[20]={0};
    Job j[20];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>j[i].id>>j[i].d>>j[i].p;
        m=max(m,j[i].d);
    }
    for(int i=0;i<n;i++)
        for(int k=i+1;k<n;k++)
            if(j[i].p<j[k].p) swap(j[i],j[k]);

    for(int i=0;i<n;i++)
        for(int k=min(j[i].d,m);k>0;k--)
            if(!slot[k]){
                slot[k]=j[i].id;
                profit+=j[i].p;
                break;
            }
    cout<<"Jobs: ";
    for(int i=1;i<=m;i++)
        if(slot[i]) cout<<"J"<<slot[i]<<" ";
    cout<<"\nMaximum Profit: "<<profit;
}