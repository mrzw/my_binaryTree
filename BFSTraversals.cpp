// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// BFS遍历 时间复杂度O(V+E)
#include <iostream>
#include <list>
#include <queue>
using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    int V;    // No. of vertices
 
    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;
public: 
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // BFS traversal
    void BFS();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::BFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    for(int i=0; i<V; ++i) {
    	if(!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while(!q.empty()) {
				int s = q.front();
				cout << s << " ";
				q.pop();
				for(auto j=adj[s].begin(); j!=adj[s].end(); ++j) {
					if(!visited[*j]) {
						visited[*j] = true;
						q.push(*j);
					}
				}
			}    	
    	}
    }
}
 
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal" << endl;
    g.BFS();
 
    return 0;
}
