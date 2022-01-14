#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
    float _TotalDistance;
    std::vector<std::vector<float> > _EdgeTable;

public:
    graph(int);
    ~graph() {}
    // Constructing the Graph
    void AddUndirectedEdge(int, int, float); // node1, node2, distance

    // MST
    void PrimAlgorithm();
    void PreorderTraversal();
    void Traversal(node *);
    void CalculateDistance();

    // For Heap Operations
    void Heapify(int);
    void MinHeapify(int);
    void BuildMinHeap();
    node *ExtractMin();
    void DecreaseKey(node *);

    // NN
    void NearestNeighbor();

    // Output
    void PrintSequence(std::ostream&);
    void WriteMSTOutputFile(std::ostream &);
    void WriteNNOutputFile(std::ostream &);
    void WriteMSTOutputStream(std::ostream &);
    void WriteNNOutputStream(std::ostream &);
};
#endif