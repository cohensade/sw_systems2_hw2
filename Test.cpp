//ID : 208565820    
//Mail : danielcohen1717@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"


TEST_CASE("Graph Operator g1 + g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    ariel::Graph result = graph1 + graph2;

    // Ensure the result matrix is correct
    vector<vector<int>> expected = {
        {1, 1, 1}, 
        {1, 0, 2}, 
        {1, 2, 0}
    };

    CHECK(result.getgraph() == expected);
}

TEST_CASE("Graph Operator g1 += g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    graph1 += graph2;

    // Ensure the result matrix is correct
    vector<vector<int>> expected = {
        {1, 1, 1}, 
        {1, 0, 2}, 
        {1, 2, 0}
    };

    CHECK(graph1.getgraph() == expected);
}

TEST_CASE("Graph Operator g1 - g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    ariel::Graph result = graph1 - graph2;

    // Ensure the result matrix is correct
    vector<vector<int>> expected = {
        {-1, 1, -1}, 
        {1, 0, 0}, 
        {-1, 0, 0}
    };

    CHECK(result.getgraph() == expected);
}

TEST_CASE("Graph Operator g1 -= g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    graph1 -= graph2;

    // Ensure the result matrix is correct
    vector<vector<int>> expected = {
        {-1, 1, -1}, 
        {1, 0, 0}, 
        {-1, 0, 0}
    };

    CHECK(graph1.getgraph() == expected);
}

TEST_CASE("Graph Prefix Increment Operator ++g") {
    ariel::Graph graph;

    vector<vector<int>> adjMatrix = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };

    graph.loadGraph(adjMatrix);
    ++graph;

    vector<vector<int>> expected = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}
    };

    CHECK(graph.getgraph() == expected);
}

TEST_CASE("Graph Prefix Decrement Operator --g") {
    ariel::Graph graph;

    vector<vector<int>> adjMatrix = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };

    graph.loadGraph(adjMatrix);
    --graph;

    vector<vector<int>> expected = {
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}
    };

    CHECK(graph.getgraph() == expected);
}

TEST_CASE("Graph Postfix Increment Operator g++") {
    ariel::Graph graph;

    vector<vector<int>> adjMatrix = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };

    graph.loadGraph(adjMatrix);
    ariel::Graph result = graph++;

    vector<vector<int>> expected = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}
    };

    CHECK(result.getgraph() == adjMatrix);
    CHECK(graph.getgraph() == expected);
}

TEST_CASE("Graph Postfix Decrement Operator g--") {
    ariel::Graph graph;

    vector<vector<int>> adjMatrix = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };

    graph.loadGraph(adjMatrix);
    ariel::Graph result = graph--;

    vector<vector<int>> expected = {
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}
    };

    CHECK(result.getgraph() == adjMatrix);
    CHECK(graph.getgraph() == expected);
}

TEST_CASE("Graph Operator g1 == g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // Ensure the result matrix is correct
    bool expected = false;

    CHECK((graph1 == graph2) == expected);
}

TEST_CASE("Graph Operator g1 != g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // Ensure the result matrix is correct
    bool expected = true;

    CHECK((graph1 != graph2) == expected);
}

TEST_CASE("Graph Operator g1 < g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;
    ariel::Graph graph3;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    vector<vector<int>> adjMatrix3 = {
        {-1, -1, -1}, 
        {-1, -1, -1}, 
        {-1, -1, -1}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);
    graph3.loadGraph(adjMatrix3);

    // Ensure the result matrix is correct
    bool expected1 = true;

    CHECK((graph1 < graph2) == expected1);
    CHECK((graph1 < graph3) == expected1);
    CHECK((graph2 < graph3) == expected1);
}



TEST_CASE("Graph Operator g1 <= g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // Ensure the result matrix is correct
    bool expected = true;

    CHECK((graph1 <= graph2) == expected);
}

TEST_CASE("Graph Operator g1 > g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // Ensure the result matrix is correct
    bool expected = false;

    CHECK((graph1 > graph2) == expected);
}

TEST_CASE("Graph Operator g1 >= g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // Ensure the result matrix is correct
    bool expected = false;

    CHECK((graph1 >= graph2) == expected);
}

TEST_CASE("Graph Operator g1 contains g2") {
    // Creating two graphs
    ariel::Graph graph1;
    ariel::Graph graph2;

    // Loading adjacency matrices for graph1 and graph2
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };
    vector<vector<int>> adjMatrix2 = {
        {1, 0, 1}, 
        {0, 0, 1}, 
        {1, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    // Ensure the result is correct
    bool expected = false;

    CHECK((graph1.isContain(graph2)) == expected);
}

TEST_CASE("Graph Operator g1 * 2") {
    // Creating a graph
    ariel::Graph graph1;

    // Loading adjacency matrix for graph1
    vector<vector<int>> adjMatrix1 = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };

    graph1.loadGraph(adjMatrix1);
    graph1 = graph1 * 2;

    vector<vector<int>> expected = {
        {0, 2, 0}, 
        {2, 0, 2}, 
        {0, 2, 0}
    };

    CHECK(graph1.getgraph() == expected);
}

TEST_CASE("Graph Multiplication Operator g1 * g2") {
    ariel::Graph graph1;
    ariel::Graph graph2;

    vector<vector<int>> adjMatrix1 = {
        {1, 2}, 
        {3, 4}
    };
    vector<vector<int>> adjMatrix2 = {
        {2, 0}, 
        {1, 2}
    };

    graph1.loadGraph(adjMatrix1);
    graph2.loadGraph(adjMatrix2);

    ariel::Graph result = graph1 * graph2;

    vector<vector<int>> expected = {
        {4, 4}, 
        {10, 8}
    };

    CHECK(result.getgraph() == expected);
}

TEST_CASE(" Output Operator <<") {
    ariel::Graph graph;

    vector<vector<int>> adjMatrix = {
        {1, 2}, 
        {3, 4}
    };

    graph.loadGraph(adjMatrix);

    ostringstream oss;
    oss << graph;

    string expected = "[1, 2]\n[3, 4]\n";

    CHECK(oss.str() == expected);
}

TEST_CASE("Graph Edge Counter") {
    ariel::Graph graph;

    vector<vector<int>> adjMatrix = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
    };

    graph.loadGraph(adjMatrix);

    int expected = 4;  // Total number of edges with non-zero weight

    CHECK(graph.countEdges() == expected);
}

TEST_CASE("Unary Minus Operator") {
    // Create a graph with some initial values
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, -8, 9}
    };
    graph.loadGraph(adjMatrix);

    // Apply the unary minus operator
    ariel::Graph negatedGraph = -graph;

    // Ensure that each element in the result is negated
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
            if (adjMatrix[i][j]>0)
            {
               CHECK(negatedGraph.getgraph()[i][j] == -adjMatrix[i][j]); 
            }else{
            CHECK(negatedGraph.getgraph()[i][j] == adjMatrix[i][j]);
            }
        }
    }
}

TEST_CASE("Unary Plus Operator") {
    // Create a graph with some initial values
    ariel::Graph graph;
    vector<vector<int>> adjMatrix = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, -8, 9}
    };
    graph.loadGraph(adjMatrix);

    // Apply the unary plus operator
    ariel::Graph positiveGraph = +graph;

    // Ensure that each element in the result is positive
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        for (size_t j = 0; j < adjMatrix[i].size(); ++j) {
            CHECK(positiveGraph.getgraph()[i][j] == abs(adjMatrix[i][j]));
        }
    }
}

TEST_CASE("Edges Cases") {
    SUBCASE("Empty Graph") {
        // Test adding, subtracting, and multiplying an empty graph
        ariel::Graph emptyGraph;
        ariel::Graph nonEmptyGraph;

        // Loading adjacency matrix for non-empty graph
        vector<vector<int>> adjMatrix = {
            {1, 2}, 
            {3, 4}
            };

            vector<vector<int>> adjMatrix2 = {
            {0, 0}, 
            {0, 0}
            };
            nonEmptyGraph.loadGraph(adjMatrix);
            emptyGraph.loadGraph(adjMatrix2);

        // Add empty graph to non-empty graph
        ariel::Graph resultAddEmpty = emptyGraph + nonEmptyGraph;
        CHECK(resultAddEmpty.getgraph() == adjMatrix);

        // Subtract empty graph from non-empty graph
        ariel::Graph resultSubtractEmpty = nonEmptyGraph - emptyGraph;
        CHECK(resultSubtractEmpty.getgraph() == adjMatrix);

        // Multiply empty graph with non-empty graph
        ariel::Graph resultMultiplyEmpty = emptyGraph * nonEmptyGraph;
        CHECK(resultMultiplyEmpty.getgraph() == adjMatrix2); // Result should be an empty graph
}

    SUBCASE("Multiple 2 graphs with different numbers of vertices") {
        // Test multiplying two graphs with different numbers of vertices
        ariel::Graph graph1;
        ariel::Graph graph2;

        // Loading adjacency matrices for graphs
        vector<vector<int>> adjMatrix1 = {
            {1, 0}, 
            {0, 4}
        };

        vector<vector<int>> adjMatrix2 = {
            {1, 2, 3}, 
            {3, 4, 5},
            {6, 7, 8}
        };

        graph1.loadGraph(adjMatrix1);
        graph2.loadGraph(adjMatrix2);

        // Multiply the graphs only if they have the same number of vertices
        ariel::Graph resultGraph;
        if (graph1.getNumVertices() == graph2.getNumVertices()) {
            resultGraph = graph1 * graph2;
        }

        // Verify the result is as expected
    
        if (graph1.getNumVertices() != graph2.getNumVertices()) {
            CHECK(resultGraph.getgraph().empty());
        } else {
            // Verify other conditions if the multiplication is possible
            CHECK(resultGraph.getNumVertices() == graph1.getNumVertices());
        
        }
}


//     SUBCASE("Algortihms") {
//         //create 2 graphs
//         ariel::Graph graph1;
//         ariel::Graph graph2;
        
//         vector<vector<int>> adjMatrix1 = {
//             {1, 2, 3}, 
//             {3, 4, 5},
//             {6, 7, 8}
//         };

//         vector<vector<int>> adjMatrix2 = {
//             {-1, -1, -1}, 
//             {-1, -1, -1},
//             {-1, -1, -1}
//         };

//         //loading the graphs
//         graph1.loadGraph(adjMatrix1);
//         graph2.loadGraph(adjMatrix2);


//         CHECK(Algorithms::isConnected(graph1) == true);
        
// }

}