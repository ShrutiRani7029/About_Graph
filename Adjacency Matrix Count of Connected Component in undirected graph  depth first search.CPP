#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int graph[N][N];
bool visited[N];

void dfs(int j){
    visited[j]=true;
    for(int i=1;i<=N;i++){
        if(!visited[i] && graph[j][i])dfs(i);
    }
}

int main(){
   int n,m;
   cin>>n>>m;
   int count=0;

   for(int i=0;i<m;i++){
    int v1,v2;
    cin>>v1>>v2;
    graph[v1][v2]=1;
    graph[v2][v1]=1;
   }

   for(int i=1;i<=n;i++){
    visited[i]=false;
   }

   for(int i=1;i<=n;i++){
    if(!visited[i])
    {
        dfs(i);
        count++;
    }
   }
   cout<<count;
}
