#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int graph[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        graph[v1][v2]=w;
        graph[v2][v1]=w;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
 }
