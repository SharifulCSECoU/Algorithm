#include<bits/stdc++.h>

using namespace std;

#define White 0
#define Black 1

vector <int> Graph[100010];

int Level[100010], Parent[100010], Visited[100010], Node, Edge, i;

void BFS(int S)
{
    for(i = 1; i <= Node; i++)
        Visited[i] = White;

    queue <int> PQ;

    PQ.push(S);

    Visited[S] = Black;
    Level[S] = 0;
    Parent[S] = 0;

    while(!PQ.empty())
    {
        int u = PQ.front();

        PQ.pop();

        for(i = 0; i < Graph[u].size(); i++)
        {
            if(Visited[Graph[u][i]] == White)
            {
                Level[Graph[u][i]] = Level[u] + 1;

                Visited[Graph[u][i]] = Black;

                PQ.push(Graph[u][i]);

                Parent[Graph[u][i]] = u;
            }
        }
    }
}

int main()
{
    int u, v, Source;

    cin >> Node >> Edge;

    for(i = 0; i < Edge; i++)
    {
        cin >> u >> v;

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    cin >> Source;

    BFS(Source);

    for(i = 1; i <= Node; i++)
        cout << "NODE " << i << " , LEVEL " << Level[i] << " , PARENT " << Parent[i] << endl;

    return 0;
}
