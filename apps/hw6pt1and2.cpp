#include <vector>
#include <iostream>
#include <limits>

template <typename T>
class GraphAdjList {
public:
    GraphAdjList() = default;
    GraphAdjList(int numNodes) : adjList(numNodes) {}

    void addEdge(int fromNode, int toNode, T weight = T{}) {
        adjList[fromNode].push_back({toNode, weight});
    }

    void removeEdge(int fromNode, int toNode) {
        for (auto it = adjList[fromNode].begin(); it != adjList[fromNode].end(); ++it) {
            if (it->first == toNode) {
                adjList[fromNode].erase(it);
                break;
            }
        }
    }

    bool hasEdge(int fromNode, int toNode) const {
        for (auto& edge : adjList[fromNode]) {
            if (edge.first == toNode) {
                return true;
            }
        }
        return false;
    }

    T getEdgeWeight(int fromNode, int toNode) const {
        for (auto& edge : adjList[fromNode]) {
            if (edge.first == toNode) {
                return edge.second;
            }
        }
        return std::numeric_limits<T>::max();
    }

    std::vector<std::pair<int, T>> getNeighbors(int node) const {
        return adjList[node];
    }

    void depthFirstTraversal(int startNode, std::function<void(int)> visitFunc) const {
        std::vector<bool> visited(adjList.size(), false);
        depthFirstTraversalRecursive(startNode, visited, visitFunc);
    }

    void breadthFirstTraversal(int startNode, std::function<void(int)> visitFunc) const {
        std::vector<bool> visited(adjList.size(), false);
        std::queue<int> nodeQueue;
        nodeQueue.push(startNode);
        visited[startNode] = true;

        while (!nodeQueue.empty()) {
            int currNode = nodeQueue.front();
            nodeQueue.pop();
            visitFunc(currNode);

            for (auto& neighbor : adjList[currNode]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    nodeQueue.push(neighbor.first);
                }
            }
        }
    }

private:
    std::vector<std::vector<std::pair<int, T>>> adjList;
};

template <typename T>
class GraphAdjMatrix {
public:
    GraphAdjMatrix() = default;
    GraphAdjMatrix(int numNodes) : adjMatrix(numNodes, std::vector<T>(numNodes, T{})) {}

    void addEdge(int fromNode, int toNode, T weight = T{}) {
        adjMatrix[fromNode][toNode] = weight;
    }

    void removeEdge(int fromNode, int toNode) {
        adjMatrix[fromNode][toNode] = T{};
    }

    bool hasEdge(int fromNode, int toNode) const {
        return adjMatrix[fromNode][toNode] != T{};
    }

    T getEdgeWeight(int fromNode, int toNode) const {
        return adjMatrix[fromNode][toNode];
    }

    std::vector<std::pair<int, T>> getNeighbors(int node) const {
        std::vector<std::pair<int, T>> neighbors;
        for (int i = 0; i < adjMatrix.size(); ++i) {
            if (adjMatrix[node][i] != T{}) {
                neighbors.push_back({i, adjMatrix[node][i]});
            }
        }
        return neighbors;
    }

     void depthFirstTraversal(int startNode, std::function<void(int)> visitNode) const {
        std::vector<bool> visited(adjMatrix.size(), false);
        std::stack<int> stack;
        stack.push(startNode);

        while (!stack.empty()) {
            int currentNode = stack.top();
            stack.pop();

            if (!visited[currentNode]) {
                visitNode(currentNode);
                visited[currentNode] = true;

                for (int i = adjMatrix.size() - 1; i >= 0; --i) {
                    if (adjMatrix[currentNode][i] != T{} && !visited[i]) {
                        stack.push(i);
                    }
                }
            }
        }
    }

    // Breadth-first traversal
    void breadthFirstTraversal(int startNode, std::function<void(int)> visitNode) const {
        std::vector<bool> visited(adjMatrix.size(), false);
        std::queue<int> queue;
        queue.push(startNode);

        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            if (!visited[currentNode]) {
                visitNode(currentNode);
                visited[currentNode] = true;

                for (int i = 0; i < adjMatrix.size(); ++i) {
                    if (adjMatrix[currentNode][i] != T{} && !visited[i]) {
                        queue.push(i);
                    }
                }
            }
        }
    }

private:
    std::vector<std::vector<T>> adjMatrix;
};
