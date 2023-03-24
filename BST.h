//
// Created by tychart on 3/23/23.
//

#pragma once

#include "PrintStuff.h"
#include "BSTInterface.h"

class BST : public BSTInterface {
public:
    BST() {
        println("test?????");
    }

    ~BST() = default;

    Node *getRootNode() const;

    bool insert(int data);

    bool remove(int data);

    bool contains(int data);

    void clear();


};
