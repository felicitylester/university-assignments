#include <iostream>
#include <fstream>
#include "AdjListNode.h"

using namespace std;

struct EdgeList{
    int source;
    int destination;
    int edgeWeight;
};

EdgeList *createEdgeList(string file, int &vertexSize, int &edgeSize);

int main(int argc, char* argv[]){
    int vertexSize, edgeSize;
    string file = argv[1];
    EdgeList *edgeList = createEdgeList(file, vertexSize, edgeSize);
    //TODO: create adjacency list from edge list
    // create an array
    AdjListNode* adjList = new AdjListNode[vertexSize];

    // create list
    for (int i = 0; i < edgeSize; i++) {
        adjList[edgeList[i].source].AddNode(edgeList[i].destination, edgeList[i].edgeWeight);
    }

    // Print the adjacency list
    cout << "Adjacency List: \n";
    for (int i = 0; i < vertexSize; i++) {
        cout << i << " : ";
        adjList[i].Display();
    }

    // clean up
    delete[] adjList;

    return 0;
}

EdgeList *createEdgeList(string file, int &vertexSize, int &edgeSize){
    ifstream fin;
    fin.open(file);
    if(!fin){
        cout << "Input file not found! Please ensure you have the required file in the correct location\n";
        exit(EXIT_FAILURE);
    }
    fin >> vertexSize >> edgeSize;
    EdgeList *list = new EdgeList[edgeSize];
    for(int i = 0; i < edgeSize; i++){
        EdgeList entry;
        fin >> entry.source >> entry.destination >> entry.edgeWeight;
        list[i] = entry;
    }
    return list;
}
