//
// Created by tychart on 3/23/23.
//

#pragma once

#include "PrintStuff.h"
#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface {

    Node* rootNode;



public:
    BST();
    BST(Node rootNode);

    ~BST();

    Node* getRootNode() const;

    bool insert(int data);

    bool remove(int data);

    bool contains(int data);

    void clear();


};
