<<<<<<< HEAD
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// BFS遍历 时间复杂度O(V+E)
#include <iostream>
#include <list>
#include <queue>
=======
// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
// 判断是否是二叉排序树
#include <iostream>
#include <vector>
>>>>>>> temp
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
 
<<<<<<< HEAD
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
=======
struct node *newNode(int item) {
	struct node *temp = new struct node;
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool isBST(node* root, node* l=NULL, node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;
 
    // if left node exist that check it has
    // correct data or not
    if (l != NULL and root->key < l->key)
        return false;
 
    // if right node exist that check it has
    // correct data or not
    if (r != NULL and root->key > r->key)
        return false;
 
    // check recursively for every node.
    return isBST(root->left, l, root) && isBST(root->right, root, r);
}

void Inorder(node* root, vector<int>& temp) {
    if(root == NULL) return;
    Inorder(root->left, temp);
    temp.push_back(root->key);
    Inorder(root->right, temp);
}

bool isBST1(node* root) {
    vector<int> data;
    Inorder(root, data);
    int n = data.size();
    for(int i=0; i<n-1; i++) {
        if(data[i] >= data[i+1]) return false;   
    }
    return true;
>>>>>>> temp
}
 
int main()
{
<<<<<<< HEAD
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
=======
    struct node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
 
    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
>>>>>>> temp
 
    return 0;
}
