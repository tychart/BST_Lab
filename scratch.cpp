#include <iostream>

#include "PrintStuff.h"
#include "BST.h"
#include "printing.h"
#include "Node.h"

int main(int argc, char *argv[]) {
    // Write your test code here. Remember that `printing.h` gives you access to
    // the functions `pretty_print_tree` and `ugly_print_tree`, which you can
    // use to print a representation of your tree like so:
    println("Start of Program:");
    BST tree;
    tree.insert(3);
    tree.insert(4);
    tree.insert(-7);
    tree.insert(-4);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
//    println(tree.getRootNode()-> data);
    pretty_print_tree(tree);
//    ugly_print_tree(tree);
//extra change
    println("test?");

    println("End of Program");
    return 0;
}
