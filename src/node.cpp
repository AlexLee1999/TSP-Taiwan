#include <iostream>
#include "node.h"

node::node(int id)
{
    _id = id;
    _key = INT_MAX;
    _isVisited = false;
    _PreviousNode = nullptr;
}

void node::SetKey(float key)
{
    _key = key;
}

float node::GetKey() const
{
    return _key;
}

void node::SetVisited()
{
    _isVisited = true;
}

void node::AddAdjancentNode(node *AdjNode, float distance)
{
    edgeProps props = edgeProps(distance, false);
    AdjacentNode adjnode(AdjNode, props);
    _AdjacentNodeList.push_back(adjnode);
}
