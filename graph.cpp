#include "graph.h"
#include <fstream>

using namespace std;
// @brief Construct a Graph with the given number of vertices.
// @param nV The number of vertices in the graph.
Graph::Graph(int nV)
{
    //  : Add your code here
    this->numVerts = nV;
    vertices.resize(numVerts);
    adjList.resize(numVerts);
}

// @brief destructor
Graph::~Graph()
{
    //  : Add your code here
    numVerts = 0;
    vertices.clear();
    adjList.clear();
}

// @brief add a vertex to the graph
void Graph::addVertex(Vertex v)
{
    //  : Add a vertex to the vertex vector
    //  : Add an empty list to the adjacency list
    vertices.push_back(v);  // is this how you add vertex to vector?
    vector<Edge> empty;
    adjList.push_back(empty);  // pushing empty list into adjList vector; of data type vector<Edge>
    numVerts++;

}

// @brief add a directed edge v1->v2 to the graph
void Graph::addDirectedEdge(int v1, int v2, float weight)
{
    //  : Add an edge to the adjacency list of v1
  Edge e(v1, v2, weight);
  adjList[v1].push_back(e);

}

// @brief add an undirected edge to the graph
void Graph::addUndirectedEdge(int v1, int v2, float weight)
{
    //  : Add edge v1->v2
    //  : Add edge v2->v1
  Edge e(v1, v2, weight);
  Edge e2(v2, v1, weight);
  
    adjList[v1].push_back(e);
    adjList[v2].push_back(e2);
}

// @brief the number of outgoing edges from a vertex
int Graph::outDegree(int v)
{
    //  : Add code here
    // how to count degrees for a vertex??
    int degrees;
    
    unsigned long int test = adjList[v].size();
    degrees = int(test);
    //cout<<"LENGTH OF VECTOR IS: "<< degrees<<endl;

    //for(int i = 0; i > length; i++){
    //  degrees++;
    //}
    return degrees;
}

// @brief depth first search from vertex v
///*
vector<int> Graph::DepthFirstSearch(int v)  // 1st version
{
    //  : Implement the depth first search algorithm
    // Add the vertex ID to a vector when it is visited
  vector<int> list;
  vector<bool> discovered(numVerts, false);
  stack<int> s;

  discovered[v] = true;
  list.push_back(v);
  s.push(v);

  while(!s.empty()){
    int element = s.top();
    s.pop();

    if(!discovered[element]){
      list.push_back(element);
      discovered[element] = true;
    }
    
    for(auto i = adjList[element].rbegin(); i!=adjList[element].rend(); i++){
      int adjV = (*i).to_vertex;
      if(!discovered[adjV])
      s.push(adjV);
      }
    }
  return list;
}
/*

/// @brief 
/// @param v 
/// @return 
vector<int> Graph:: DepthFirstSearch(int v){  // 2nd version
  vector<int> list;
  vector<bool> discovered(numVerts, false);
  stack<int> s;

  discovered[v] = true;
  list.push_back(v);
  s.push(v);

  cout<<"VISITED STUFF:{ ";

  while(!s.empty()){
    int current = s.top();  s.pop(); cout<<current<<" ";  // take top of stack and remove it
    
    if(!discovered[current]){
      list.push_back(current);
      discovered[current] = true;
    } 
  unsigned long int test = adjList[current].size(); int length = int(test);
    for(int i = 0; i < length; i++){
    //for(auto i = adjList[current].rbegin(); i != adjList[current].rend(); i++){
      int adjV = (adjList[current])[i].to_vertex;
      
      if(!discovered[adjV]){
      s.push(adjV);
      //discovered[adjV] = true;
      //list.push_back(adjV);
      }
    }
  }
  cout<<"}"<<endl;
  return list;
}
*/

// @brief breadth first search from a vertex
vector<int> Graph::BreadthFirstSearch(int v)
{
    //  : Implement the breadth first search algorithm
    // Add the vertex ID to a vector when it is visited
  vector<int> list;
  vector<bool> discovered(numVerts, false);
  queue<int> q;
  q.push(v);
  discovered[v] = true;

  while(!q.empty()){
    int current = q.front();
    q.pop();
    list.push_back(current);

    unsigned long int test = adjList[current].size();
    int length = int(test);

    for(int i = 0; i < length; i++){
      int adjV = (adjList[current])[i].to_vertex;
      if(!discovered[adjV]){
        q.push(adjV);
        discovered[adjV] = true;
      }

    }
    
    
    

  }




  //vector<int> loser;
    return list;
}

/**
 * @brief Check if the graph has cycles
 * @return true if the graph has cycles
 */
bool Graph::checkCycle()
{
    //  : Implement the algorithm to check if the graph has cycles
    // Assume an undirected graph
  vector<bool> discovered(numVerts, false);
  Vertex v = vertices[0];
  //discovered[v] = true;

    return false;
}

// @brief print the graph
void Graph::printGraph()
{
    cout << "Graph:" << endl;
    for (int i = 0; i < numVerts; i++)
    {
        cout << i << ": ";
        for(auto j = adjList[i].begin(); j != adjList[i].end(); ++j)
        {
            cout << (*j).to_vertex << " " ;
        }
        cout << endl;
    }
    cout << endl;
}



vector<int> Graph:: Dijkstra(int v){
  vector<int> list;
  vector<int> distance;
  priority_queue<int> PQ;


  return list;
}

void Graph::fillVerts(string file_name){
ifstream fin;
fin.open(file_name.c_str());
if(!fin){cout<<"Error opening file"<<endl; return;}

int c_id; string c_code; string c_name; int pop; int elev;
while(!fin.eof()){
  fin>>c_id>>c_code>>c_name>>pop>>elev;
  Vertex v(c_id, c_code, c_name, pop, elev);
  addVertex(v);
}

fin.close();
}

void Graph::fillEdges(string file_name){
ifstream fin;
fin.open(file_name.c_str());
if(!fin){cout<<"Error opening file"<<endl; return;}

int start, finish; float wweight;
while(!fin.eof()){
  fin>>start>>finish>>wweight;
  addDirectedEdge(start, finish, wweight);
}
fin.close();
}

void Graph::printCities(vector<int> list){
  for(auto i = list.begin(); i!= list.end(); i++){
    cout<<vertices[*i].city_name<<" ";
  }
  cout<<endl;
}