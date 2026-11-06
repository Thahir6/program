// BFS AND DFS GRAPH TRAVERSAL
#include<iostream>
#include<queue>
using namespace std;

int a[10][10],v[10],n;

void BFS(int s){
    queue<int> q;
    v[s]=1; q.push(s);
    while(!q.empty()){
        int x=q.front(); q.pop();
        cout<<x<<" ";
        for(int i=0;i<n;i++)
            if(a[x][i]&&!v[i])
                v[i]=1,q.push(i);
    }
}
void DFS(int s){
    v[s]=1; cout<<s<<" ";
    for(int i=0;i<n;i++)
        if(a[s][i]&&!v[i]) DFS(i);
}
int main(){
    int s;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>a[i][j];
    cin>>s;
    cout<<"BFS: "; BFS(s);
    for(int i=0;i<n;i++) v[i]=0;
    cout<<"\nDFS: "; DFS(s);
}