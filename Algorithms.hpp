//ID : 208565820    
//Mail : danielcohen1717@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp" 
using namespace std;
namespace ariel
{
class Algorithms {
private:
    //help algos
    static void DFS(const Graph& graph, int vertex, vector<bool>& visited); //dfs algo
    static vector<int>BellmanFordAlgo(const Graph& graph, int source, int dest); //bellmanford algo
    static bool dfsCycleHelper(const Graph& graph, int vertex, int parent, vector<bool>& visited, std::vector<int>& cyclepath);
    
public:
    static bool isConnected(const Graph& graph); //if the graph is connected it will return true else false
    static int shortestPath(const Graph& graph, int start, int end); //return the shortest path from vertex to another
    static bool isContainsCycle(const Graph& graph); //if the graph is contain cycle it will return true else false
    static bool isBipartite(const Graph& graph); //if the graph is bipartite it will return true else false
    static bool negativeCycle(const Graph& graph); //if the graph is contain negative cycle itll return true else false

};
}
#endif /* ALGORITHMS_HPP */
