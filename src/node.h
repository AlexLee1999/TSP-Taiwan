#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>

class node
{
    friend class graph;
    typedef std::pair<float, bool> edgeProps; //distance, inMst
    typedef std::pair<node *, edgeProps> AdjacentNode; // Node, distance
private:
    std::vector<AdjacentNode> _AdjacentNodeList;
    int _id;
    float _key;
    bool _isVisited;
    node * _PreviousNode;
    bool _isTraversalVisited;

public:
    node(int);
    ~node() {}
    void AddAdjancentNode(node *, float);
    void SetKey(float);    //For Prim's Algorithm
    float GetKey() const; //For Prim's Algorithm
    void SetVisited();
    void SetTraversalVisited();
};

#endif