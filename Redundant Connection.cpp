
 const int N=1e5;
class Solution {
   
int size[N],parent[N];
public:

void make(int n)
{
  size[n]=1;
  parent[n]=n;
}
int Find(int n)
{
   if(parent[n]==n)return n;
   return parent[n]=Find(parent[n]);
}
void Union(int a,int b)
{
     a=Find(a);
     b=Find(b);

    if(a!=b)
    {
        if(size[a]<size[b])swap(a,b);
        size[a]+=size[b];
        parent[b]=a;
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ///disjoint set union------------
        int n=edges.size();
        ///first make every node as independent node---
        for(int i=1;i<=n;i++)
        make(i);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int x=edges[i][0],y=edges[i][1];
            if(Find(x)==Find(y))
            {
                ans={x,y};
            }
            else
            {
                Union(x,y);
            }
        }
        return ans;
    }
};
