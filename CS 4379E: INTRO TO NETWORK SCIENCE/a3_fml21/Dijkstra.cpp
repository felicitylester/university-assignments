#include <iostream>
#include <fstream>
#include "AdjList.h"

using namespace std;

void printSolution(int dist[], int prev[], int vertexSize, int startID) {
    // TODO: Print out the shortest distances and their corresponding paths from the source to all other nodes in the graph
    cout << left << setw(12) << "Vertex" << setw(12) << "Distance" << setw(12) << "Path" << endl;
    for (int i = 0; i < vertexSize; i++) {
        cout << left << setw(12) << (to_string(startID) + " -> " + to_string(i)) << setw(12);
        
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "INF";
        } else {
            cout << dist[i];
        }
        
        cout << setw(5) << ""; // Ensures proper alignment of Path column
        if (dist[i] != numeric_limits<int>::max()) {
            int path[vertexSize];
            int pathIndex = 0;
            for (int v = i; v != -1; v = prev[v]) {
                path[pathIndex++] = v;
            }
            
            cout << left << setw(12); // Ensures alignment for the Path column
            for (int j = pathIndex - 1; j >= 0; j--) {
                cout << path[j] << " ";
            }
        }
        cout << "\n";
    }
}

void Dijkstra(AdjList *list, int startID, int vertexSize) {
    
	int *dist = new int[vertexSize];
    int *prev = new int[vertexSize];
    bool *visited = new bool[vertexSize]();
	
    // TODO: Implement Dijsktra's algorithm
        for (int i = 0; i < vertexSize; i++) {
        dist[i] = numeric_limits<int>::max();
        prev[i] = -1;
    }
    dist[startID] = 0;

    for (int count = 0; count < vertexSize - 1; count++) {
        int u = -1;
        int minDist = numeric_limits<int>::max();
        
        for (int i = 0; i < vertexSize; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        visited[u] = true;
        
        Node* current = list[u].GetHeadNode();
        while (current != nullptr) {
            int v = current->nodeID;
            int weight = current->edgeWeight;
            
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
            current = current->next;
        }
    }
    
    printSolution(dist, prev, vertexSize, startID);
    
	delete[] dist;
    delete[] prev;
    delete[] visited;
}

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
        int src, dest, edgeweight;
        fin >> src >> dest >> edgeweight;
        list[src].AddNode(dest, edgeweight);
    }
	
    return list;
}

int main(int argc, char *argv[]){
	
    int vertexSize, edgeCount;
	
    if(argc < 2){
		fprintf(stderr, "ERROR: Must include edge list file as command line argument\n"); 
		exit(-1);
	}
    string file = argv[1];
	
    AdjList *adjList = createAdjList(file, vertexSize, edgeCount);
    
	int startNode = 0;
    Dijkstra(adjList, startNode, vertexSize);
    
	return 0;
}