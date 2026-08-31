#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node {
   int rank;
   int parent;
};

struct Edge {
   int src;
   int dst;
   int weight;
};

// Create a single-node tree with i as the root
void MakeSet(Node *node, int i) {
    //TODO
    node[i].parent = i;
    node[i].rank = 0;
}

// Return the index of the element corresponding to the root of the tree that contains i
int FindSet(Node *nodes, int i) {
    //TODO
    if (nodes[i].parent != i) {
        nodes[i].parent = FindSet(nodes, nodes[i].parent); // Path compression
    }
    return nodes[i].parent;
}

// Link the root of the tree with smaller rank to the root of the tree with larger rank
// when uniting the trees that contain u and v
void UnionByRank(Node *nodes, int u, int v) {
    //TODO
    int uRoot = FindSet(nodes, u);
    int vRoot = FindSet(nodes, v);

    if (uRoot == vRoot) return;

    if (nodes[uRoot].rank < nodes[vRoot].rank) {
        nodes[uRoot].parent = vRoot;
    } else if (nodes[uRoot].rank > nodes[vRoot].rank) {
        nodes[vRoot].parent = uRoot;
    } else {
        nodes[vRoot].parent = uRoot;
        nodes[uRoot].rank++;
    }
}

void Kruskal(Node *nodes, Edge *edgeList, int vertexSize, int edgeCount) {
    //TODO: Implement Kruskal's algorithm to find the minimum spanning tree.
     // Step 1: MakeSet for all nodes
    for (int i = 0; i < vertexSize; i++) {
        MakeSet(nodes, i);
    }

    // Step 2: Sort edges by weight
    sort(edgeList, edgeList + edgeCount, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    Edge MST[vertexSize-1];
    int mstIndex = 0;

    // Step 3: Iterate through sorted edges
    for (int i = 0; i < edgeCount && mstIndex < vertexSize - 1; i++) {
        int u = edgeList[i].src;
        int v = edgeList[i].dst;

        if (FindSet(nodes, u) != FindSet(nodes, v)) {
            MST[mstIndex++] = edgeList[i];
            UnionByRank(nodes, u, v);
        }
    }
	
	
    //TODO: Print out the resulting minimum spanning tree.
    cout << "Edges in the MST:\n";
    for (int i = 0; i < mstIndex; i++) {
        cout << MST[i].src << " -> " << MST[i].dst << ": " << MST[i].weight << endl;
    }	
}

int main(int argc, char *argv[]){
    int vertexSize, edgeCount;
	
    if(argc < 2){
		fprintf(stderr, "ERROR: Must include edge list file as command line argument\n"); 
		exit(-1);
	}
    string file = argv[1];
	
    ifstream fin;
    fin.open(file);
	
    if(!fin){
        cout << "Input file not found! Please ensure you have the required file in the correct location\n";
		exit(EXIT_FAILURE);
    }
    fin >> vertexSize >> edgeCount;
	
    Node nodes[vertexSize];
    for(int i = 0; i < vertexSize; i++){
        nodes[i].rank = 0; 
        nodes[i].parent = -1; 
    }
	
    Edge edgeList[edgeCount];
    for (int i = 0; i < edgeCount; i++) {
        fin >> edgeList[i].src >> edgeList[i].dst >> edgeList[i].weight;
    }

    Kruskal(nodes, edgeList, vertexSize, edgeCount);

	return 0;
}