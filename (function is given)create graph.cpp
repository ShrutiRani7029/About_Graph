///agar function fek diya jae to kaise print krenge?? chalo dekhte hai
/*#include <bits/stdc++.h>
using namespace std;
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    vector<int> graph[n];

    // Creation
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    // Printing
    vector<vector<int>> list(n);
    for (int i = 0; i < n; i++) {
        list[i].push_back(i);
        for (int j = 0; j < graph[i].size(); j++) {
            list[i].push_back(graph[i][j]);
        }
    }

    return list;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adjacencyList = printAdjacency(n, m, edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adjacencyList[i].size(); j++) {

            cout << adjacencyList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
