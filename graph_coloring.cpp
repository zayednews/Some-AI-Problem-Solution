#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
         delete [] adj;
    }

    void addEdge(int v, int w);

    void Coloring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::Coloring()
{
    int result[V];

    result[0]  = 0;

    for (int u = 1; u < V; u++)
        result[u] = -1;

    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;

    for (int u = 1; u < V; u++)
    {

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result[u] = cr;

        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }


    for (int u = 0; u < V; u++)
        {
        cout << "Node " << u << " --->  Color ";
        if(result[u]==0)
             cout<< "Red"<< endl;
        else if(result[u]==1)
             cout<< "Blue"<< endl;
        else if(result[u]==2)
             cout<< "Green"<< endl;
        else if(result[u]==3)
             cout<< "Yellow"<< endl;
        else
                cout<<"Others"<< endl;
        }
}

int main()
{
    Graph g1(10);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 4);
    g1.addEdge(1, 5);
    g1.addEdge(1, 9);
    g1.addEdge(2, 3);
    g1.addEdge(2, 8);
    g1.addEdge(3, 5);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(6, 8);
    g1.addEdge(7, 9);
    g1.addEdge(8, 9);
    cout << "Graph coloring \n";
    g1.Coloring();

    return 0;
}
