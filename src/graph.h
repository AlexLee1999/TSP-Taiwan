#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <string>
#include "node.h"

class graph
{
private:
    std::vector<node *> _NodeList;
    std::vector<node *> _CopyNodeList;
    int _VerticesNumber;
    std::string _type;
    float _TotalWeight;
    std::vector<node *> _SequenceList;

public:
    graph(int);
    ~graph() {}
    // Constructing the Graph
    void AddUndirectedEdge(int, int, float); // node1, node2, distance

    //MST
    void PrimAlgorithm();
    void PreorderTraversal();
    void Traversal(node *);

    // For Heap Operations
    void Heapify(int);
    void MinHeapify(int);
    void BuildMinHeap();
    node *ExtractMin();
    void DecreaseKey(node *);


    // Output 
    void WriteUndirectedOutputFile(std::ostream&);
};
#endif