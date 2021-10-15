#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "graph.h"

int main(int argc, char *argv[])
{
    std::fstream fin("./distance.txt");
    std::fstream fout;
    std::string inFilePath = "./distance.txt";
    std::string outFilePath = "./result.txt";
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

    myGraph->PrimAlgorithm();
    myGraph->PreorderTraversal();
    myGraph->WriteUndirectedOutputFile(fout);
}