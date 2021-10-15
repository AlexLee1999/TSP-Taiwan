#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "graph.h"

int main(int argc, char *argv[])
{
    std::fstream fin("./distance.txt");
    std::string algorithm = argv[1];
    std::fstream fout;
    std::string inFilePath = "./distance.txt";
    std::string outFilePath = "./" + algorithm + ".txt";
    fout.open(outFilePath, std::ios::out | std::ios::trunc);
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
    }
    else if (algorithm == "NN")
    {
        myGraph->NearestNeighbor();
        myGraph->CalculateDistance();
        myGraph->WriteNNOutputFile(fout);
    }
}