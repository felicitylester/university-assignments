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
    //TODO: create CSR representation from edge list
    // Arrays for CSR representation
    int* rowPointers = new int[vertexSize + 1];
    int* columns = new int[edgeSize];
    int* edgeWeights = new int[edgeSize];

    // Fill in CSR arrays
    int edgeIndex = 0;
    for (int i = 0; i < vertexSize; i++) {
        rowPointers[i] = edgeIndex;
        while (edgeIndex < edgeSize && edgeList[edgeIndex].source == i) {
            columns[edgeIndex] = edgeList[edgeIndex].destination;
            edgeWeights[edgeIndex] = edgeList[edgeIndex].edgeWeight;
            edgeIndex++;
        }
    }
    rowPointers[vertexSize] = edgeIndex; // End of last row
 
    cout << "CSR: \n";
    //TODO: Print CSR
    cout << "Row: ";
    for (int i = 0; i <= vertexSize; i++) {
        cout << rowPointers[i] << " ";
    }
    cout << endl;

    cout << "Column: ";
    for (int i = 0; i < edgeSize; i++) {
        cout << columns[i] << " ";
    }
    cout << endl;

    cout << "Edge Weights: ";
    for (int i = 0; i < edgeSize; i++) {
        cout << edgeWeights[i] << " ";
    }
    cout << endl;
    
    // Clean up dynamically allocated memory
    delete[] rowPointers;
    delete[] columns;
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
