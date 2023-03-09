// YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

class NodeInterface {
public:
    virtual ~NodeInterface() = default;

    virtual int getData() const = 0;

    virtual NodeInterface* getLeftChild() const = 0;

    virtual NodeInterface* getRightChild() const = 0;
};
