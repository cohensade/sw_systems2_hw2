//ID : 208565820    
//Mail : danielcohen1717@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> matrix1 = {
        {0, 2, 0},
        {0, 0, 3},
        {1, 0, 0}
    };

    vector<vector<int>> matrix2 = {
        {0, 2, 2},
        {0, 0, 3},
        {1, 0, 0}
    };

    vector<vector<int>> matrix3 = {
        {0, 1, 1},
        {0, 0, 2},
        {-1, 0, 0}
    };

    ariel::Graph graph1;
    graph1.loadGraph(matrix1);


    ariel::Graph graph2;
    graph2.loadGraph(matrix2);

    ariel::Graph graph3;
    graph3.loadGraph(matrix3);

    cout << "Graph 1:\n";
    cout << graph1;
    
    cout << "\nGraph 2:\n";
    cout << graph2;

    cout << "\nGraph 3:\n";
    cout << graph3;

    cout << "\nGraph 3 == Graph 2: " << (graph3 == graph2) << endl;
    cout << "Graph 3 != Graph 2: " << (graph3 != graph2) << endl;
    cout << "Graph 3 < Graph 2: " << (graph3 < graph2) << endl;
    cout << "Graph 3 <= Graph 2: " << (graph3 <= graph2) << endl;
    cout << "Graph 3 > Graph 2: " << (graph3 > graph2) << endl;
    cout << "Graph 3 >= Graph 2: " << (graph3 >= graph2) << endl;
    graph3 = +graph3;
    cout << graph3;


    return 0;
}
