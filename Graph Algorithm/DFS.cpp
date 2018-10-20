#include<bits/stdc++.h>

using namespace std;

vector <int> Graph[100001];

bool Visited[100001];

int DFS(int Node)
{
    Visited[Node] = 1;

    for(int i = 0; i < Graph[Node].size(); i++)
        if(!Visited[Graph[Node][i]])
            DFS(Graph[Node][i]);

    cout << Node << " ";
}

int main()
{
    int Node, Edge, Start, u, v;

    cin >> Node >> Edge;

    for(int i = 0; i < Edge; i++)
    {
        cin >> u >> v;

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    cin >> Start;

    DFS(Start);

    cout << endl;

    return 0;
}
