#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// The social graph
unordered_map<string, vector<string>> social_graph =
{
    {"You", {"Loid", "Bert", "Kevin Bacon"}},
    {"Loid", {"You", "Bert", "Elaine"}},
    {"Bert", {"You", "Loid", "Dave", "Eddy"}},
    {"Elaine", {"Loid", "Fred", "Grace"}},
    {"Dave", {"Bert", "Eva"}},
    {"Eddy", {"Bert", "Danny"}},
    {"Fred", {"Elaine", "Beth"}},
    {"Grace", {"Elaine", "Jimmy"}},
    {"Eva", {"Dave", "Frank"}},
    {"Danny", {"Eddy", "Kim"}},
    {"Beth", {"Fred", "Kim"}},
    {"Jimmy", {"Grace", "Frank"}},
    {"Frank", {"Eva", "Jimmy"}},
    {"Kim", {"Danny", "Beth"}},
    {"Kevin Bacon", {"You"}}
};


bool dfs(string current_node, unordered_set<string>& visited, vector<string>& path)
{
    visited.insert(current_node);
    //KEVIN BACON?!
    if (current_node == "Kevin Bacon")
    {
        return true;
    }
   
    for (string neighbor : social_graph[current_node])
    {
        if (visited.find(neighbor) == visited.end())
        {
            if (dfs(neighbor, visited, path))
            {
                path.push_back(neighbor);
                return true;
            }
        }
    }
    // No Bacon? :(
    return false;
}


// Function to check if you are connected to Kevin Bacon
bool is_connected_to_kevin_bacon(string start_node, vector<string>& path)
{
    unordered_set<string> visited;
   
    bool result = dfs(start_node, visited, path);
   
    if (result)
    {
        path.push_back("Kevin Bacon");
        reverse(path.begin(), path.end());
    }
   
    return result;
}


int main()
{
    vector<string> path_to_kevin_bacon;
    bool connected = is_connected_to_kevin_bacon("You", path_to_kevin_bacon);
   
    if (connected)
    {
        cout << "You are connected to Kevin Bacon! Path: ";
        for (string node : path_to_kevin_bacon)
        {
            cout << node << " -> ";
        }
        cout << "Kevin Bacon\n";
    }
   
    else
    {
        cout << "You are not connected to Kevin Bacon\n";
    }
    return 0;
}
