#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <functional>


using namespace std;

void visit(int node) {
    cout << node << " ";
}

// Class for representing a directed graph using adjacency list
class GraphAdjList {
public:
    GraphAdjList() {}
    ~GraphAdjList() {}

    bool isValidPath(const vector<int>& path) const {
        for (int i = 0; i < path.size() - 1; i++) {
            if (!adjList.count(path[i]) || !adjList.at(path[i]).count(path[i+1])) {
                return false;
            }
        }
        return true;
    }

    int calculatePathWeight(const vector<int>& path) const {
        int weight = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            weight += adjList.at(path[i]).at(path[i+1]);
        }
        return weight;
    }

    map<int, int> shortestPathsFrom(int source) const {
        map<int, int> dist;
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d != dist[u]) {
                continue;
            }
            for (auto& p : adjList.at(u)) {
                int v = p.first;
                int weight = p.second;
                if (!dist.count(v) || dist[v] > d + weight) {
                    dist[v] = d + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    void addNode(int node) {
        if (m_edges.find(node) == m_edges.end()) {
            m_edges[node] = vector<int>();
        }
    }

    void addEdge(int source, int dest) {
        addNode(source);
        addNode(dest);
        m_edges[source].push_back(dest);
    }

    bool containsCycle(vector<int>& path) {
        unordered_set<int> visited;
        unordered_set<int> onStack;
        for (int node : path) {
            if (visited.find(node) == visited.end()) {
                if (dfs(node, visited, onStack)) {
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(int startNode, function<void(int)> visit) {
        unordered_set<int> visited;
        dfsHelper(startNode, visited, visit);
    }

    void bfs(int startNode, function<void(int)> visit) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(startNode);
        visited.insert(startNode);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visit(node);
            for (int neighbor : m_edges[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }

private:
    unordered_map<int, vector<int>> m_edges;
    unordered_map<int, unordered_map<int, int>> adjList;

    bool dfs(int node, unordered_set<int>& visited, unordered_set<int>& onStack) {
        visited.insert(node);
        onStack.insert(node);
        for (int neighbor : m_edges[node]) {
            if (onStack.find(neighbor) != onStack.end()) {
                // Found cycle
                return true;
            }
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, visited, onStack)) {
                    return true;
                }
            }
        }
        onStack.erase(node);
        return false;
    }

    void dfsHelper(int node, unordered_set<int>& visited, function<void(int)> visit) {
        visited.insert(node);
        visit(node);
        for (int neighbor : m_edges[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(neighbor, visited, visit);
            }
        }
    }
};

// Reads a graph from a file in the format "node list_of_nodes"
GraphAdjList readGraphFromFile(string filename) {
    GraphAdjList graph;
    ifstream infile(filename);
    int node;
    while (infile >> node) {
        char arrow;
        infile >> arrow;
        while (arrow == '-') {
            int dest;
            infile >> dest;
            graph.addEdge(node, dest);
            infile >> arrow;
        }
    }
    return graph;
}

int main() {
    // Read graph from file
    GraphAdjList graph = readGraphFromFile("graph.txt");

    // Get user-specified path
    vector<int> path;
    cout << "Enter a path (space-separated integers): ";
    int node;
    while (cin >> node) {
        path.push_back(node);
    }

    // Check if path contains cycle
    if (graph.containsCycle(path)) {
        cout << "Path contains a cycle" << endl;
    } else {
        cout << "Path does not contain a cycle" << endl;
    }

    // Check if the path is a valid path in the graph
    if (!graph.isValidPath(path)) {
        cout << "Invalid path: path is not a valid path in the graph" << endl;
        return 1;
    }

    // Calculate the total weight of the path
    int totalWeight = graph.calculatePathWeight(path);
    cout << "Total weight of path: " << totalWeight << endl;

    // Find the shortest path from the first node in the user-specified path to all other nodes in the graph
    map<int, int> shortestPaths = graph.shortestPathsFrom(path[0]);
    cout << "Shortest paths from node " << path[0] << " to all other nodes:" << endl;
    for (auto it = shortestPaths.begin(); it != shortestPaths.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}







   