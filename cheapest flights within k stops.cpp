#include<bits/stdc++.h>
using namespace std;
int flight(int n,vector<vector<int>>&flights,int src,int dest,int k)
{
    vector<pair<int,int>>adj[n];
    for(auto it:flights)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }
    ///using queue for storing stops,source,destination as: {stops,{node,dist}}
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    vector<int>distance(n,1e9);
    distance[src]=0;
    while(!q.empty())
    {
       auto it=q.front();
       q.pop();
       int stops=it.first;
       ///cout<<stops<<endl;
       int node=it.second.first;
       ///cout<<node<<endl;
       int cost=it.second.second;
       ///cout<<cost<<endl;
       if(stops>k)continue;
       for(auto iter: adj[node])
       {
           int first=iter.first;///1
           int second=iter.second;///100
           cout<<cost<<" "<<second<<" "<<distance[first]<<endl;
           if (cost + second < distance[first] && stops <= k)
                {
                    distance[first] = cost + second;
                    q.push({stops + 1, {first, cost + second}});
                }

       }
    }
    if (distance[dest] == 1e9)///destination unreachable
            return -1;
        return distance[dest];

}
int main()
{
    int n=4,src=0,dest=3,stops=1;
    vector<vector<int>>flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    int ans=flight(n,flights,src,dest,stops);
    cout<<ans;
    cout<<endl;
}
