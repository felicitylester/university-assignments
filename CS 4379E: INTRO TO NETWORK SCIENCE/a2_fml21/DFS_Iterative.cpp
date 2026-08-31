#include <iostream>
#include <fstream>
#include <stack>
#include "AdjList.h"

using namespace std;

AdjList *createAdjList(string file, int &V, int &E){
    ifstream fin;
    fin.open(file);
    if(!fin){
        cout << "Input file not found! Please ensure you have the required file in the correct location\n";
        exit(EXIT_FAILURE);
    }
    fin >> V >> E;
	
    AdjList *list = new AdjList[V];
    for(int i = 0; i < E; i++){
        int src, dest;
        fin >> src >> dest;
        list[src].AddNode(dest);
    }
	
    return list;
}

// g++ -o DFS_Iterative DFS_Iterative.cpp
// ./DFS_Iterative graph.txt
void DFS_iter(AdjList *list, int startID, bool *isVisited) {
    stack<int> S;
    S.push(startID);    // initialize

    cout << "Starting DFS from node " << startID << endl;

    while (!S.empty()) {
        int v = S.top();
        S.pop();        // remove top node

        if (!isVisited[v]) {
            isVisited[v] = true;    // mark visited
            cout << "Visiting node " << v << endl;

            // traverse through all unvisited neighbors
            Node* neighbor = list[v].GetHeadNode();
            while (neighbor) {
                if (!isVisited[neighbor->nodeID]) {
                    S.push(neighbor->nodeID);       // push unvisited neighbors
                }
                neighbor = neighbor->next;
            }
        }
    }
}

int main(int argc, char *argv[]){
	
    int vertexSize, edgeCount;
    
	if(argc < 2){
		fprintf(stderr, "ERROR: Must include edge list file as command line argument\n"); 
		exit(-1);
	}
    string file = argv[1];
    
	AdjList *adjList = createAdjList(file, vertexSize, edgeCount);
    
	bool *isVisited = new bool[vertexSize];
    for(int i = 0; i < vertexSize; i++){
        isVisited[i] = false;
    }
	
    DFS_iter(adjList, 0, isVisited);
	
    return 0;
}