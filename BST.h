//
// Created by tychart on 3/23/23.
//

#pragma once

#include "PrintStuff.h"
#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface {

    Node* rootNode;

    bool _insert(int data, Node* currNode);

    bool _search(int data, Node* currNode);

    bool _remove(int data, Node* &currNode);

    bool _isLeaf(Node* currNode);

    int _getLargestValueInTree(Node* currNode);

public:
    BST();
//    BST(Node rootNode);

    ~BST();

    Node* getRootNode() const;

    bool insert(int data);

    bool remove(int data);

    bool contains(int data);

    void clear();


};
