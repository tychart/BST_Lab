//
// Created by tychart on 3/23/23.
//

#include "BST.h"

BST::BST() {
    rootNode = nullptr;
}

// Destructor
BST::~BST() {
    clear();
}

Node* BST::getRootNode() const {
    return rootNode;
}

bool BST::_search(int data, Node *currNode) {
    if(currNode == nullptr) {return false;}

    if(currNode-> data == data) {return true;}

    if(data < currNode-> data) {
        return _search(data, currNode-> left);
    } else {
        return _search(data, currNode-> right);
    }

}

bool BST::_isLeaf(Node* currNode) {
    if(currNode->left == nullptr && currNode-> right == nullptr) {
        return true;
    } else {return false;}
}

bool BST::insert(int data) {
    if(rootNode == nullptr) {
        rootNode = new Node(data);
        return true;
    }


    return _insert(data, rootNode);
}

bool BST::_insert(int data, Node* currNode) {

    // Warning: Value already exists, so nothing will be done.
    if(currNode-> data == data) {
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

}


bool BST::remove(int data) {
    return _remove(data, rootNode);
}

bool BST::_remove(int data, Node* &currNode) {
    if(currNode == nullptr) {return false;}

    // Will remove if node has no children
    if(_isLeaf(currNode)) {
        if(currNode-> data == data) {
            delete currNode;
            currNode = nullptr;
            return true;
        }
        // Warning: data to remove not found
        return false;
    }

    if (data == currNode-> data) {
        if (currNode-> left != nullptr && currNode-> right != nullptr) {
            int replaceData = _getLargestValueInTree(currNode-> left);
            currNode-> data = replaceData;
            _remove(replaceData, currNode-> left);
            return true;
        } else if (currNode-> left != nullptr && currNode-> right == nullptr) {
            Node* temp = currNode-> left;
            delete currNode;
            currNode = temp;
            return true;
        } else {
            Node* temp = currNode-> right;
            delete currNode;
            currNode = temp;
            return true;
        }
    }


    if (data < currNode-> data) {
        return _remove(data, currNode-> left);
    } else {
        return _remove(data, currNode-> right);
    }




}

int BST::_getLargestValueInTree(Node* currNode) {
    if (currNode-> right == nullptr) {
        return currNode-> data;
    } else {
        return _getLargestValueInTree(currNode-> right);
    }
}

bool BST::contains(int data) {
    if(rootNode == nullptr) {return false;}

    return _search(data, rootNode);
}

void BST::clear() {
    _clear(rootNode);
}

void BST::_clear(Node* &currNode) {
    if (currNode == nullptr) {return;}
    if (_isLeaf(currNode)) {
        delete currNode;
        currNode = nullptr;
        return;
    }
    if (currNode-> left != nullptr) {
        _clear(currNode-> left);
    }
    if (currNode-> right != nullptr) {
        _clear(currNode-> right);
    }

    delete currNode;
    currNode = nullptr;
    return;
}
