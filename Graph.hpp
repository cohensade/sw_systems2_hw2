//ID : 208565820    
//Mail : danielcohen1717@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel
{
    class Graph {
    private:
        vector<vector<int>> adjacencyMatrix; // Adjacency matrix

    public:
        Graph();
        //Functions from exe1
        void loadGraph(const vector<vector<int>>& adjacencyMatrix); //loading the graph
        void printGraph() const; //print graph
        int getNumVertices() const; //get the number of vertices in the graph
        const vector<vector<int>>& getgraph() const; //get the adj matrix of the graph
        int getEdgeWeight(int src, int dest) const; //get the edge between vertex src and vertex dest
        
        // Arithmetic operators
        Graph operator+(const Graph& other) const; // + operator for 2 graphs
        Graph& operator+=(const Graph& other); // this graph += other graph
        Graph operator+() const; //unary plus (all the negative num become positive)
        Graph operator-() const; // unary minus (all the positive num become negative)
        Graph operator-(const Graph& other) const; // - operator for 2 graphs
        Graph& operator-=(const Graph& other); // this graph -= other graph
        Graph& operator++(); //prefix
        Graph& operator--(); //prefix
        Graph operator++(int);//postfix
        Graph operator--(int);//postfix


        // Comparison operators
        bool operator==(const Graph& other) const; //check if 2 graphs are equals
        bool operator!=(const Graph& other) const; //check if 2 graphs are unequals
        bool operator<(const Graph& other) const; //check if this graph < other graph
        bool operator<=(const Graph& other) const;//check if this graph <= other graph
        bool operator>(const Graph& other) const; //check if this graph > other graph  
        bool operator>=(const Graph& other) const; //check if this graph >= other graph
         bool isContain(const Graph& other) const;   //helper for comarison operators
        

        // Scalar multiplication
        Graph operator*(int scalar) const; //mult with scalar(int)

        // Graph multiplication
        Graph operator*(const Graph& other) const; //mult two graphs

        // Output operator
        friend ostream& operator<<(ostream& os, const Graph& graph); //print the graph (stream)

        //edge counter
        int countEdges() const; // count the edges number of the graph
    };
}

#endif /* GRAPH_HPP */