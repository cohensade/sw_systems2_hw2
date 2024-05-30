//ID : 208565820    
//Mail : danielcohen1717@gmail.com
#include "Algorithms.hpp"
#include <queue>
#include <limits>
#include <algorithm>

namespace ariel {

void Algorithms::DFS(const Graph& graph, int vertex, vector<bool>& visited) 
{
    visited[vertex] = true; //starting from the vertex that we want so we marked him as visited
    vector<vector<int>> adjMatrix = graph.getgraph(); // Access the adjacency matrix
    for (size_t i = 0; i < adjMatrix[vertex].size(); ++i) 
    {
        if (adjMatrix[vertex][i] != 0 && !visited[i]) 
        {
            //we are checking for vertex all his neighboors and if we didnt visit them we run dfs on them
            DFS(graph, i, visited);
        }
    }
}

vector<int> Algorithms::BellmanFordAlgo(const Graph& graph, int source, int dest) 
{
    vector<int> pathVertices; //vector that hold the path
    const vector<vector<int>>& adjMatrix = graph.getgraph(); // Access the adjacency matrix
    int numVertices = graph.getNumVertices(); //get the num of vertices
    vector<int> distances(numVertices, numeric_limits<int>::max()); //set all verticess distance to infinity
    vector<int> pi(numVertices, -1); // set all verticess pi to -1
    
    distances[source] = 0; // start from vertex 0

    // Relax edges repeatedly (V-1 times)
    for (int i = 0; i < numVertices - 1; ++i) 
    {
        for (int u = 0; u < numVertices; ++u) 
        {
            for (int v = 0; v < numVertices; ++v) 
            {
                if (adjMatrix[u][v] != 0) 
                {
                    int weight = adjMatrix[u][v];
                    if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) 
                    {
                        //for all vertex u we iterates all vertics v and if we found a shortest way 
                        //through u to v we update the distance of v
                        distances[v] = distances[u] + weight;
                        pi[v] = u; // u is the predecessor of v 
                    }
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < numVertices; ++u) 
    {
        for (int v = 0; v < numVertices; ++v) 
        {
            if (adjMatrix[u][v] != 0) {
                int weight = adjMatrix[u][v];
                if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) 
                {
                    // negative cycle detected
                    cerr << "Graph contains a negative cycle." << endl;

                    // extract the cycle vertices
                    vector<int> cycleVertices;
                    int currentVertex = v;
                    while (currentVertex != -1 && currentVertex != u) 
                    {
                        cycleVertices.push_back(currentVertex);
                        currentVertex = pi[currentVertex];
                    }
                    cycleVertices.push_back(u); // Add the starting vertex
                    reverse(cycleVertices.begin(), cycleVertices.end()); // Reverse the path vertices

                    // Print the cycle
                    cout << "Negative cycle vertices: ";
                    for (int vertex : cycleVertices) 
                    {
                        cout << vertex << " ";
                    }
                    cout << endl;

                    return {}; // Return an empty vector to indicate failure
                }
            }
        }
    }

    // Construct the shortest path
    int currentVertex = dest;
    if (pi[currentVertex] == -1) 
    {
        // No path exists from source to destination
        return {};
    }
    while (currentVertex != source) 
    {
        pathVertices.push_back(currentVertex);
        currentVertex = pi[currentVertex];
    }
    pathVertices.push_back(source); // Add the source vertex
    reverse(pathVertices.begin(), pathVertices.end()); // Reverse the path vertices
    
    return pathVertices;
}



bool Algorithms::dfsCycleHelper(const Graph& graph, int vertex, int parent, vector<bool>& visited, std::vector<int>& cyclepath) {
    visited[vertex] = true;  // set the current vertex as visited
    vector<vector<int>> adjMatrix = graph.getgraph(); // access the adjacency matrix

    // iterate over the neighboors vertices of the current vertex
    for (size_t i = 0; i < adjMatrix[vertex].size(); ++i) 
    {
        if (adjMatrix[vertex][i] != 0)  // if there exists an edge from the current vertex to vertex i
        {
            if (!visited[i]) {  // if vertex i has not been visited yet
                cyclepath.push_back(vertex);  // add the current vertex to the cycle path
                if (dfsCycleHelper(graph, i, vertex, visited, cyclepath))  // recursively search for a cycle starting from vertex i
                {
                    return true;  // if a cycle is found, return true
                }
                cyclepath.pop_back();  
            } else if (i != parent) {  // if vertex i has been visited and is not the parent vertex
                cyclepath.push_back(vertex);  // add the current vertex to the cycle path
                cyclepath.push_back(i);  // add vertex i to the cycle path
                return true;  
            }
        }
    }
    return false;  
}


bool Algorithms::isConnected(const Graph& graph) 
{
    vector<bool> visited(graph.getNumVertices(), false); //set all vertices to not visited
    DFS(graph, 0, visited); //run dfs from vertex 0 
    for (bool visit : visited) {
        if (!visit) 
        {
            //if we didnt visit to all vertices with dfs the graph is not connected
            return false;
        }
    }
    return true;
}

int Algorithms::shortestPath(const Graph& graph, int start, int end) 
{
    int totalLength = 0;
    vector<int> pathVertices = BellmanFordAlgo(graph, start, end);//using bellman ford to get shortest path
    if (pathVertices.empty()) //if pathvertices empty there is no path
    {
        cerr << "No path exists from vertex " << start << " to vertex " << end << endl;
        return -1;
    } else 
    {
        // Print the path
       cout << "Shortest path from vertex " << start << " to vertex " << end << ": ";
        for (int vertex : pathVertices) 
        {
            cout << vertex << " ";
        }
        cout << endl;
    for (size_t i = 0; i < pathVertices.size() - 1; ++i) 
        {
            totalLength += graph.getEdgeWeight(pathVertices[i], pathVertices[i + 1]);
        }
        return totalLength; //return the length of the shortest path
    }
}

bool Algorithms::isContainsCycle(const Graph& graph) 
{
    vector<bool> visited(graph.getNumVertices(), false);
    vector<int> cyclePath;
    return dfsCycleHelper(graph, 0, -1, visited, cyclePath); //use dfscyclehelper from vertex 0 that dont have parent
}

bool Algorithms::isBipartite(const Graph& graph) 
{
    vector<int> colors(graph.getNumVertices(), -1);//set all vertices colors to -1
    queue<int> q;
    q.push(0);
    colors[0] = 0; //set color of vertex 0 to 0
    while (!q.empty()) {
        int vertex = q.front(); 
        q.pop();
        vector<vector<int>> adjMatrix = graph.getgraph(); // access the adjacency matrix
        for (size_t i = 0; i < adjMatrix[vertex].size(); ++i) 
        {
            if (adjMatrix[vertex][i] != 0) //if there is edge from vertex to vertex i
            {
                if (colors[i] == -1) //and the color of vertex i is -1 aka not colored yet
                {
                    colors[i] = 1 - colors[vertex]; //we set his color to 1 - color of vertex
                    q.push(i);
                } else if (colors[i] == colors[vertex]) //if vertex i have the same color of current vertex 
                // the graph is not bipartite
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Algorithms::negativeCycle(const Graph& graph) 
{
    const vector<vector<int>>& adjMatrix = graph.getgraph(); // access the adjacency matrix of the graph
    int numVertices = graph.getNumVertices(); // get the number of vertices in the graph
    vector<int> distances(numVertices, numeric_limits<int>::max()); // set distances to all vertices as infinity
    distances[0] = 0; // set the distance to the source vertex (vertex 0) to 0

    // bellman-Ford algorithm to relax edges
    for (int i = 0; i < numVertices - 1; ++i) 
    {
        for (int u = 0; u < numVertices; ++u) // iterate over all vertices
        {
            for (int v = 0; v < numVertices; ++v) // iterate over all vertices to check edges from u to v
            {
                if (adjMatrix[u][v] != 0) // if there is an edge from u to v
                {
                    int weight = adjMatrix[u][v]; // get the weight of the edge
                    // //for all vertex u we iterates all vertics v and if we found a shortest way 
                        //through u to v we update the distance of v
                    if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) 
                    {
                        distances[v] = distances[u] + weight; 
                    }
                }
            }
        }
    }

    // check for negative-weight cycles by trying to relax edges one more time
    for (int u = 0; u < numVertices; ++u) 
    {
        for (int v = 0; v < numVertices; ++v) 
        {
            if (adjMatrix[u][v] != 0) // if there is an edge from u to v
            {
                int weight = adjMatrix[u][v]; // get the weight of the edge
                // if the distance shrink cause of the relax there is a negative cycle
                if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) 
                {
                    return true; 
                }
            }
        }
    }

    return false; 
}
} 
