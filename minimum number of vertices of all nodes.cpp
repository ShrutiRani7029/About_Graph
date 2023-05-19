///jiska bhi indegree 0 hoga hm usko ans me consider krenge

#include<bits/stdc++.h>
using namespace std;

vector<int>findSmallestSetOfVertices(int n, vector<vector<int>>&edges){
   vector<int>ans;

   vector<int>indegree(n,0);
   for(auto it:edges){
    indegree[it[1]]+=1;
   }
   for(int i=0;i<n;i++)
   {

       if(indegree[i]==0)ans.push_back(i);
   }
   return ans;

}

int main(){
    int t;
    cin>>t;
    while(t--)

    {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(2));

    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<int>hello=findSmallestSetOfVertices(n,edges);

    for(int i=0;i<hello.size();i++){
        cout<<hello[i]<<" ";
    }
    cout<<endl;


    }

}
