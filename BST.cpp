//
// Created by tychart on 3/23/23.
//

#include "BST.h"

BST::BST() : rootNode(nullptr) {
    println("No input, so initialized rootNode to nullptr");
}

//BST::BST(Node inputNode) : rootNode(&inputNode) {
////    rootNode = &inputNode;
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

bool BST::insert(int data) {
    if(rootNode == nullptr) {
        rootNode = new Node(data);
        return true;
    }

    rootNode-> right = new Node(data);
    return true;
}

bool BST::_insert(int data, Node* currNode) {

}


bool BST::remove(int data) {

}

bool BST::contains(int data) {

}

void BST::clear() {

}
