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

    ~BSTInterface() = default;

    Node *getRootNode() const = 0;

    bool insert(int data) = 0;

    bool remove(int data) = 0;

    bool contains(int data) = 0;

    void clear() = 0;


};
