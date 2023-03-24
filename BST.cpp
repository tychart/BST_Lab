//
// Created by tychart on 3/23/23.
//

#include "BST.h"

BST::BST() : rootNode(nullptr) {
    println("No input, so initialized rootNode to nullptr");
}

BST::BST(Node rootNode) : rootNode(nullptr) {
    println("test?????");
}

BST::~BST() {
    println("I'm supposed to be deleted now");
}

Node* BST::getRootNode() const {
    return rootNode;
}

bool BST::insert(int data) {

}

bool BST::remove(int data) {

}

bool BST::contains(int data) {

}

void BST::clear() {

}
