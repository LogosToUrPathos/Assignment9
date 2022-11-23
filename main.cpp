#include <iostream>
//#include <fstream>
#include "graph.cpp"

//#include <vector>

using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    Graph g(0);
    g.fillVerts("city.txt");
    g.fillEdges("road.txt");

    //g.printGraph();
    vector<int> test = g.BreadthFirstSearch(0);  //eventually change this into Dijkstra's alg.
    g.printCities(test);
    



    return 0;
}

