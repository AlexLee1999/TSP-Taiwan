#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "graph.h"

int main(int argc, char *argv[])
{
    std::string data = argv[2];
    std::string inFilePath = "./" + data + "_distance.txt";
    std::string algorithm = argv[1];
    std::string outFilePath = "./" + algorithm + data +  ".txt";
    std::string outStreamPath = "./" + algorithm + data +  "stream.txt";
    std::fstream fin(inFilePath);
    std::fstream fout;
    fout.open(outFilePath, std::ios::out | std::ios::trunc);
    std::fstream foutStream;
    foutStream.open(outStreamPath, std::ios::out | std::ios::trunc);
    int VerticesSize;
    fin >> VerticesSize; // get vertices numbers
    graph *myGraph = new graph(VerticesSize);
    int EdgeSize = VerticesSize * (VerticesSize - 1) / 2;
    for (int i = 0; i < EdgeSize; ++i)
    {
        int id1, id2;
        float distance;
        fin >> id1 >> id2 >> distance;
        myGraph->AddUndirectedEdge(id1, id2, distance);
    }
    if (algorithm == "MST")
    {
        myGraph->PrimAlgorithm();
        myGraph->PreorderTraversal();
        myGraph->CalculateDistance();
        myGraph->WriteMSTOutputFile(fout);
        myGraph->WriteMSTOutputStream(foutStream);
    }
    else if (algorithm == "NN")
    {
        myGraph->NearestNeighbor();
        myGraph->CalculateDistance();
        myGraph->WriteNNOutputFile(fout);
        myGraph->WriteNNOutputStream(foutStream);
    }
}