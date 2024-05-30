//ID : 208565820    
//Mail : danielcohen1717@gmail.com
#include "Graph.hpp"
#include <iostream>


namespace ariel
{
    //empty constructor
    Graph::Graph() 
    {

    }
    //loading the graph
    void Graph::loadGraph(const vector<vector<int>>& adjMatrix)
    {
        adjacencyMatrix = adjMatrix; 
    }
    //print for each vertex thier nighboors
    void Graph::printGraph() const
    {
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            cout << "Adjacency list of vertex " << i << ": ";
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0) // Only print non-zero edges cause if edge = 0 there is no edge
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
    //get the num of the vertices in the graph
    int Graph::getNumVertices() const
    {
        return adjacencyMatrix.size(); //return the num of vertex rows = cols = vertex
    }
    //get the adj matrix that represnting the graph
    const vector<vector<int>>& Graph::getgraph() const //
    {
        return adjacencyMatrix; //return the adj matrix of the graph
    }

    int Graph::getEdgeWeight(int src, int dest) const
    {
        return adjacencyMatrix[src][dest]; //return the edge value of edge(src ,dest)
    }


    // Arithmetic operators
//+ operator
Graph Graph::operator+(const Graph& other) const {
    if (this->getNumVertices() != other.getNumVertices()) {
        //if num of vertices is diff between the graphs cannot add between them
        cerr << "Error: The size of the matrices is not equal." << endl;
        exit(1);
    }
    //set new matrix that will represent the result of this + other (graphs).
    vector<vector<int>> resultMatrix(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            //do the + operator for each ij index 
            resultMatrix[i][j] = this->adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
        }
    }

    Graph result; // set the new graph
    result.loadGraph(resultMatrix); // loading the graph
    return result; // return the result.
}

// += operator
Graph& Graph::operator+=(const Graph& other) {
    if (this->getNumVertices() != other.getNumVertices()) {
        //checking if the sizes of both matrices is the same
         cerr << "Error: The size of the matrices is not equal." << endl;
        exit(1);
    }
    
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            //do the += operator for each ij index
            this->adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
        }
    }

    return *this; // return the matrix.
}

//unary +
 Graph Graph::operator+() const {
    // create a copy of the current graph
    Graph positiveGraph = *this;

    // iterate over each element in the adjacency matrix
    for (size_t i = 0; i < positiveGraph.adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < positiveGraph.adjacencyMatrix[i].size(); ++j) {
            // convert to the absolute value function to each element
            positiveGraph.adjacencyMatrix[i][j] = abs(positiveGraph.adjacencyMatrix[i][j]);
        }
    }

    // return the graph with all values converted to positive
    return positiveGraph;
}

//onary -
Graph Graph::operator-() const { //took the defenition to this from https://stackoverflow.com/questions/1602464/what-does-unary-minus-mean-for-matrices
    // Create a copy of the current graph
    Graph negatedGraph = *this;

    // negate all edge weights
    for (int i = 0; i < negatedGraph.getNumVertices(); ++i) {
        for (int j = 0; j < negatedGraph.getNumVertices(); ++j) {
            //if the edge < 0 the edge is staying
            if (negatedGraph.getEdgeWeight(i,j) < 0)
            {
                negatedGraph.adjacencyMatrix[i][j] = negatedGraph.adjacencyMatrix[i][j];
            }else{
            //else the edge is positive, change to negative
            negatedGraph.adjacencyMatrix[i][j] = -negatedGraph.adjacencyMatrix[i][j];
            }
        }
    }
    // Return the negated graph
    return negatedGraph;
}

//operator -
Graph Graph::operator-(const Graph& other) const {
    if (this->getNumVertices() != other.getNumVertices()) {
        cerr << "Error: The size of the matrices is not equal." << endl;//checking if the sizes of both matrices is the same
        exit(1);
    }

    //set new matrix that will represent the - of those 2.
    vector<vector<int>> resultMatrix(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    

for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            //do the - operator for each ij index
            resultMatrix[i][j] = this->adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
        }
    }

    Graph result; // set the new graph
    result.loadGraph(resultMatrix); // loading the graph
    return result; // return the result.
}
//-= operator
Graph& Graph::operator-=(const Graph& other) {
    if (this->getNumVertices() != other.getNumVertices()) {
        cerr << "Error: The size of the matrices is not equal." << endl;//checking if the sizes of both matrices is the same
        exit(1);
    }
    
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            //do the -= operator for each ij index
            this->adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
        }
    }

    return *this; // return the matrix.
}


// prefix increment operator: ++graph
Graph& Graph::operator++() {
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            // increment each edge weight by 1 if there is an edge
            if (this->adjacencyMatrix[i][j] != 0) {
                this->adjacencyMatrix[i][j]++;
            }
        }
    }
    return *this;
}

// prefix decrement operator: --graph
Graph& Graph::operator--() {
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            // decrement each edge weight by 1 if there is an edge
            if (this->adjacencyMatrix[i][j] != 0) {
                this->adjacencyMatrix[i][j]--;
            }
        }
    }
    return *this;
}

// postfix increment operator: graph++
Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

// postfix decrement operator: graph--
Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}


// Comparison operators

//== operator
bool Graph::operator==(const Graph& other) const {
    // check if the number of vertices is the same
    if (this->getNumVertices() != other.getNumVertices()) {
        return false;
    }

    // checking if all the edges is equals
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            if (this->getEdgeWeight(i, j) != other.getEdgeWeight(i, j)) {
                return false;
            }
        }
    }

    // checking if this is graeter then other and other is greater then this
    if ((*this <= other) || (other <= *this)) {
        return false;
    }

    return true;  
}


// != opertator 
bool Graph::operator!=(const Graph& other) const {
    // check if the number of vertices is the same
    if (this->getNumVertices() != other.getNumVertices()) {
        return true;
    }

    // checking if all the edges is equals
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            if (this->getEdgeWeight(i, j) != other.getEdgeWeight(i, j)) {
                return true;
            }
        }
    }

    // checking if this is graeter then other and other is greater then this
    if (!(*this <= other) || !(other <= *this)) {
        return true;
    }

    return false;  
}
// < operator
bool Graph::operator<(const Graph& other) const {
     // check if graph this is contained in graph other
    if (other.isContain(*this)) {
        return true; // if this is contained in other, this < other
    } else {
        // compare the number of edges between this and other
        int edgesThis = this->countEdges();
        int edgesOther = other.countEdges();

        if (edgesThis < edgesOther) {
            return true;
            //if the edges are equals compare by the size of the matrices
        } else if (edgesThis == edgesOther) {
            if (this->adjacencyMatrix.size() < other.adjacencyMatrix.size()) {
                return true;
            }
        }
        return false;
    }
}
// <= operator
bool Graph::operator<=(const Graph& other) const {
     // check if graph this is contained in graph other
    if (other.isContain(*this)) {
        return true; // if this is contained in other, this <= other
    } else {
        // compare the number of edges between this and other
        int edgesThis = this->countEdges();
        int edgesOther = other.countEdges();

        if (edgesThis <= edgesOther) {
            return true;
            //if the edges are equals compare by the size of the matrices
        } else if (edgesThis == edgesOther) {
            if (this->adjacencyMatrix.size() <= other.adjacencyMatrix.size()) {
                return true;
            }
        }
        return false;
    }
}
// > operator
bool Graph::operator>(const Graph& other) const {
    // check if graph other is contained in graph this
    if (this->isContain(other)) {
        return true; // if other is contained in this, this > other
    } else {
        // compare the number of edges between this and other
        int edgesThis = this->countEdges();
        int edgesOther = other.countEdges();

        if (edgesThis > edgesOther) {
            return true;
            //if the edges are equals compare by the size of the matrices
        } else if (edgesThis == edgesOther) {
            if (this->adjacencyMatrix.size() > other.adjacencyMatrix.size()) {
                return true;
            }
        }
        return false;
    }
}
// >= operator
bool Graph::operator>=(const Graph& other) const {
    // check if graph other is contained in graph this
    if (this->isContain(other)) {
        return true; // if other is contained in this, this >= other
    } else {
        // compare the number of edges between this and other
        int edgesThis = this->countEdges();
        int edgesOther = other.countEdges();

        if (edgesThis >= edgesOther) {
            return true;
            //if the edges are equals compare by the size of the matrices
        } 
        else if (edgesThis == edgesOther) {
            if (this->adjacencyMatrix.size() >= other.adjacencyMatrix.size()) {
                return true;
            }
        }
        return false;
    }
}

// scalar multiplication
Graph Graph::operator*(int scalar) const {
   //set new matrix that will represent the matrix * scalar.
    vector<vector<int>> resultMatrix(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            //do the * operator with scalar for each ij index
            resultMatrix[i][j] = this->adjacencyMatrix[i][j] * scalar;
        }
    }

    Graph result; // set the new graph
    result.loadGraph(resultMatrix); // loading the graph
    return result; // return the result.
}

// graph multiplication
Graph Graph::operator*(const Graph& other) const {
    if (this->getNumVertices() != other.getNumVertices()) {
        std::cerr << "Error: The size of the matrices is not equal." << std::endl;
        exit(1);
    }
    
    // set new matrix that will represent the result of graph multiplication
    vector<vector<int>> resultMatrix(this->getNumVertices(), vector<int>(this->getNumVertices(), 0));
    
    // doing matrix multiplication
    for (int i = 0; i < this->getNumVertices(); ++i) {
        for (int j = 0; j < this->getNumVertices(); ++j) {
            for (int k = 0; k < this->getNumVertices(); ++k) {
                resultMatrix[i][j] += this->adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
            }
        }
    }

    Graph result; // Create the new graph
    result.loadGraph(resultMatrix); // Load the resulting matrix into the graph
    return result; // Return the result.
}


// Output operator
 ostream& operator<<(ostream& os, const Graph& graph) {
        // Iterate over each row in the adjacency matrix
        for (size_t i = 0; i < graph.adjacencyMatrix.size(); ++i) {
            os << "["; // Start a new row
            // Iterate over each element in the row
            for (size_t j = 0; j < graph.adjacencyMatrix[i].size(); ++j) {
                os << graph.adjacencyMatrix[i][j]; // Print the element
                if (j < graph.adjacencyMatrix[i].size() - 1) {
                    os << ", "; // Print a comma if it's not the last element
                }
            }
            os << "]\n"; // End the row
        }
    
        return os; // Return the output stream
    }

//helper function for the comparison operators
bool Graph::isContain(const Graph& other) const {
    // Check if the sizes are possible for being contained
    if (this->getNumVertices() < other.getNumVertices()) {
        return false;
    }
    
    for (int i = 0; i < other.getNumVertices(); ++i) {
        for (int j = 0; j < other.getNumVertices(); ++j) {
            // Check that there is not an edge which exists in 'other' but not in 'this'
            if (other.getEdgeWeight(i, j) != 0 && this->getEdgeWeight(i, j) == 0) {
                return false;
            }
        }
    }
    
    // 'other' is contained in 'this'
    return true;
}

//get the number of edges in the graph
int Graph::countEdges() const {
    int count = 0; //counter for edges
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                count++; // check if there is a vertex and increase count by one
            }
        }
    }
    return count;
}


}


