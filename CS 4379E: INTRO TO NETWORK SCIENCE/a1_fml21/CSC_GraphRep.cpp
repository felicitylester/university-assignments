#include <iostream>
#include <fstream>
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
    // TODO: create CSC representation from edge list
    int* columnPointers = new int[vertexSize + 1]();  // Initialize with zeros
    int* rows = new int[edgeSize];
    int* edgeWeights = new int[edgeSize];

    // Step 1: Count the number of edges per column (destination vertex)
    for (int i = 0; i < edgeSize; i++) {
        if (edgeList[i].destination < vertexSize) {  // Ensure within range
            columnPointers[edgeList[i].destination + 1]++;
        }
    }

    // Step 2: Compute prefix sum to get column pointers
    for (int i = 1; i <= vertexSize; i++) {
        columnPointers[i] += columnPointers[i - 1];
    }

    // Step 3: Populate rows and edgeWeights arrays
    int* tempColumnIndex = new int[vertexSize]();  // Track insertion position per column
    for (int i = 0; i < edgeSize; i++) {
        int dest = edgeList[i].destination;
        if (dest < vertexSize) {  // Ensure within range
            int index = columnPointers[dest] + tempColumnIndex[dest]; // Find correct slot
            rows[index] = edgeList[i].source;
            edgeWeights[index] = edgeList[i].edgeWeight;
            tempColumnIndex[dest]++;  // Move to next position
        }
    }
    delete[] tempColumnIndex;  // No longer needed


    // TODO: Print CSC
    cout << "CSC: \n";

    cout << "Row: ";
    for (int i = 0; i < edgeSize; i++) {
        cout << rows[i] << " ";
    }
    cout << endl;

    cout << "Column: ";
    for (int i = 0; i <= vertexSize; i++) {
        cout << columnPointers[i] << " ";
    }
    cout << endl;

    cout << "Edge Weights: ";
    for (int i = 0; i < edgeSize; i++) {
        cout << edgeWeights[i] << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete[] columnPointers;
    delete[] rows;
    delete[] edgeWeights;

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
