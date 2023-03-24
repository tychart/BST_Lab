//
// Created by tychart on 3/23/23.
//

#include "BST.h"

BST::BST() {
    rootNode = nullptr;
//    println("No input, so initialized rootNode to nullptr");
}

//BST::BST(Node inputNode) : rootNode(&inputNode) {
//    rootNode = &inputNode;
//    println("test?????");
//}

BST::~BST() {
    println("I'm supposed to be deleted now");
}

Node* BST::getRootNode() const {
    Node tempNode(100);
//    return &tempNode;
    return rootNode;
}

bool BST::_search(int data, Node *currNode) {
    if(currNode-> data == data) {
        return true;
    }

    if(data < currNode-> data) {
        if(currNode-> left == nullptr) {return false;}
        return _search(data, currNode-> left);
    } else {
        if(currNode-> right == nullptr) {return false;}
        return _search(data, currNode-> left);
    }

}

bool BST::insert(int data) {
    if(rootNode == nullptr) {
        rootNode = new Node(data);
        return true;
    }


    return _insert(data, rootNode);
}

bool BST::_insert(int data, Node* currNode) {

    if(currNode-> data == data) {
        std::cout << "Warning: Value already exists, so nothing will be done." << std::endl;
        return false;
    }

    if(data < currNode-> data) {
        if(currNode-> left == nullptr) {
            currNode-> left = new Node(data);
            return true;
        }
        return _insert(data, currNode-> left);

    } else {
        if(currNode-> right == nullptr) {
            currNode-> right = new Node(data);
            return true;
        }
        return _insert(data, currNode-> right);
    }



//    rootNode-> right = new Node(data);

}


bool BST::remove(int data) {

}

bool BST::contains(int data) {

}

void BST::clear() {

}
