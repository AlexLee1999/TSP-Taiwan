#include <iostream>
#include <vector>
#include "graph.h"

graph::graph(int VerticesNumber)
{
    _TotalWeight = (float)0;
    _VerticesNumber = VerticesNumber;
    _NodeList.resize(VerticesNumber);
    _CopyNodeList.resize(VerticesNumber);
    for (int i = 0; i < VerticesNumber; ++i)
    {
        _NodeList[i] = new node(i); // add new node
        _CopyNodeList[i] = _NodeList[i];
    }
}

void graph::AddUndirectedEdge(int id1, int id2, float distance)
{
    node *Node1 = _NodeList[id1];
    node *Node2 = _NodeList[id2];
    Node1->AddAdjancentNode(Node2, distance);
    Node2->AddAdjancentNode(Node1, distance);
}

void graph::PrimAlgorithm()
{
    // std::cout << _NodeList[0]->_id << " ";
    _NodeList[0]->SetKey(0);
    BuildMinHeap();
    for (int i = 0; i < _VerticesNumber; ++i)
    {
        node *n = ExtractMin();
        // std::cout << n->_id << " ";
        n->SetVisited();
        if (n->_PreviousNode != nullptr)
        {
            for (int j = 0; j < n->_PreviousNode->_AdjacentNodeList.size(); ++j)
            {
                if (n->_PreviousNode->_AdjacentNodeList[j].first->_id == n->_id) // add edge in mst
                {
                    n->_PreviousNode->_AdjacentNodeList[j].second.second = true; // change edge properties
                    _TotalWeight += n->GetKey();
                }
            }
            for (int j = 0; j < n->_AdjacentNodeList.size(); ++j)
            {
                if (n->_AdjacentNodeList[j].first->_id == n->_PreviousNode->_id)
                {
                    n->_AdjacentNodeList[j].second.second = true;
                }
            }
        }
        for (int j = 0; j < n->_AdjacentNodeList.size(); ++j)
        {
            if (!n->_AdjacentNodeList[j].first->_isVisited && n->_AdjacentNodeList[j].first->GetKey() > n->_AdjacentNodeList[j].second.first) // if adj not in mst && key < weight
            {
                n->_AdjacentNodeList[j].first->SetKey(n->_AdjacentNodeList[j].second.first);
                DecreaseKey(n->_AdjacentNodeList[j].first);
                n->_AdjacentNodeList[j].first->_PreviousNode = n;
            }
        }
    }
}

void graph::Heapify(int root)
{
    int t = (root - 1) / 2;
    while (t >= 0)
    {
        if (_NodeList[t]->GetKey() > _NodeList[root]->GetKey())
        {
            std::swap(_NodeList[t], _NodeList[root]);
            root = t;
            t = (root - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

void graph::MinHeapify(int root)
{
    int t = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < _NodeList.size() && _NodeList[l]->GetKey() < _NodeList[t]->GetKey())
    {
        t = l;
    }
    if (r < _NodeList.size() && _NodeList[r]->GetKey() < _NodeList[t]->GetKey())
    {
        t = r;
    }
    if (t != root)
    {
        std::swap(_NodeList[t], _NodeList[root]);
        MinHeapify(t);
    }
}

void graph::BuildMinHeap()
{
    int heapSize = _NodeList.size();
    for (int i = heapSize / 2 - 1; i >= 0; i--)
    {
        MinHeapify(i);
    }
}
node *graph::ExtractMin()
{
    node *n = _NodeList[0];
    std::swap(_NodeList[0], _NodeList[_NodeList.size() - 1]);
    _NodeList.pop_back();
    MinHeapify(0);
    return n;
}

void graph::DecreaseKey(node *x)
{
    for (int i = 0; i < _NodeList.size(); i++)
    {
        if (_NodeList[i] == x)
        {
            Heapify(i);
        }
    }
}

void graph::WriteUndirectedOutputFile(std::ostream &fout)
{
    fout << "MST With Prim's Algorithm" << std::endl;
    fout << "MST Total Weight : " << _TotalWeight << std::endl;
    for (int i = 0; i < _VerticesNumber; ++i)
    {
        std::vector<node::AdjacentNode> CurrentNodeAdjacentList = _CopyNodeList[i]->_AdjacentNodeList;
        for (int j = 0; j < CurrentNodeAdjacentList.size(); ++j)
        {
            if (CurrentNodeAdjacentList[j].second.second == true)
            {
                if (_CopyNodeList[i]->_id < CurrentNodeAdjacentList[j].first->_id)
                {
                    fout << _CopyNodeList[i]->_id << ' ' << CurrentNodeAdjacentList[j].first->_id << ' ' << CurrentNodeAdjacentList[j].second.first << std::endl;
                }
            }
            else
            {
                continue;
            }
        }
    }
    fout << std::endl;
    fout << std::endl;
    fout << "Best Sequence" << std::endl;
    fout << "0";
    for (int i = 0; i < _SequenceList.size(); ++i)
    {
        fout << " -> " << _SequenceList[i]->_id;
    }
    fout << std::endl;
}

void graph::PreorderTraversal()
{
    node *Node = _CopyNodeList[0];
    Traversal(Node);
}

void graph::Traversal(node *Node)
{
    for (int i = 0; i < Node->_AdjacentNodeList.size(); ++i)
    {
        if (Node->_AdjacentNodeList[i].second.second == true && Node->_id < Node->_AdjacentNodeList[i].first->_id)
        {
            Traversal(Node->_AdjacentNodeList[i].first);
        }
    }
    _SequenceList.push_back(Node);
}
