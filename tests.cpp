#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>

#include "BST.h"

// A whole bunch of helper functions come below. You don't need to think about
// them unless you want to read them for fun!

// --------------------   HELPER FUNCTIONS   --------------------

void ugly_print_tree_helper(const Node* node) {
    if (node == nullptr) {
        return;
    }
    Node* left = node->left;
    Node* right = node->right;
    std::cout << node->data << ": ";
    if (left == nullptr) {
        std::cout << "__";
    } else {
        std::cout << left->data;
    }
    std::cout << ' ';
    if (right == nullptr) {
        std::cout << "__";
    } else {
        std::cout << right->data;
    }
    std::cout << std::endl;

    ugly_print_tree_helper(left);
    ugly_print_tree_helper(right);
}

int tree_height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return std::max(tree_height(node->left), tree_height(node->right)) + 1;
}

constexpr int num_spaces_for_level(int height, int level) {
    return (1 << (height - level + 1)) - 2;
}

constexpr int num_nodes_in_level(int level) {
    return 1 << level;
}

void print_spaces(int quantity) {
    for (int i = 0; i < quantity; ++i) {
        std::cout << ' ';
    }
}

// -------------------- END HELPER FUNCTIONS --------------------

// You don't need to understand the following function (unless you want to read
// it for fun!). All you need to know is that you can use it to print out your
// tree. The advantage of this function over `ugly_print_tree` is that the
// resulting printout is easier to read since it's in a tree-like shape. For
// instance, if `tree` has the following structure:
//
//        15
//       /  \
//      /    \
//    13      17
//   /       /  \
// 12      16    18
//
// then `pretty_print_tree(tree)` will output the following:
//
//       15
// 
//   13      17
// 
// 12      16  18
//
// The disadvantages of this function are:
//   1) The width of the printout explodes as the tree gets taller. For
//      instance, the printout of a tree with height 6 will be about 125
//      characters wide, and the width about doubles with each additional level.
//   2) The function is only written to deal with numbers that have at most 2
//      digits.
//
// If you need to visualize a tree that is either taller or has bigger numbers,
// look at `ugly_print_tree`, which is under `pretty_print_tree`. Its printout
// is a bit harder to read, but can work for bigger trees.
void pretty_print_tree(const BST& tree) {
    Node* root = tree.getRootNode();
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return;
    }

    std::queue<Node*> traversal;
    traversal.push(root);

    int height = tree_height(root);
    for (int level = 0; level < height; ++level) {
        int spaces_in_between = num_spaces_for_level(height, level);
        int spaces_before = spaces_in_between / 2 - 1;
        print_spaces(spaces_before);

        int nodes = num_nodes_in_level(level);
        bool print_spaces_before = false;
        for (int ni = 0; ni < nodes; ++ni) {
            if (print_spaces_before) {
                print_spaces(spaces_in_between);
            }
            print_spaces_before = true;

            Node* node = traversal.front();
            traversal.pop();

            if (node == nullptr) {
                std::cout << "  ";
                traversal.push(nullptr);
                traversal.push(nullptr);
            } else {
                std::cout << std::setw(2) << std::right << std::setfill(' ') << node->data;
                traversal.push(node->left);
                traversal.push(node->right);
            }
        }
        if (level != height - 1) {
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

// You don't need to understand the following function (unless you want to read
// it for fun!). All you need to know is that you can use it to print out your
// tree. The advantages of this function over `pretty_print_tree` is that the
// resulting printout doesn't explode in width as the height of the tree
// increases and it can handle numbers with more than 2 digits. The disadvantage
// is that `ugly_print_tree`'s printout is harder to read than
// `pretty_print_tree`'s. For instance, if `tree` has the following structure:
//
//        15
//       /  \
//      /    \
//    13      17
//   /       /  \
// 12      16    18
//
// then `ugly_print_tree(tree)` will output the following:
//
// 15: 13 17
// 13: 12 __
// 12: __ __
// 17: 16 18
// 16: __ __
// 18: __ __
//
// If you need to visualize a tree that is shorter and has small enough numbers,
// you could also use `pretty_print_tree`, which is above. Its printout can be
// easier to read if the tree is not too tall and doesn't have too big of
// numbers.
void ugly_print_tree(const BST& tree) {
    Node* root = tree.getRootNode();
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
    } else {
        ugly_print_tree_helper(root);
    }
}

void part1() {
    std::cout << "--- Part 1 output ---" << std::endl;

    BST tree;

    std::cout << "\nPretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 8 into the tree..." << std::boolalpha << tree.insert(8) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 10 into the tree..." << std::boolalpha << tree.insert(10) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 11 into the tree..." << std::boolalpha << tree.insert(11) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 13 into the tree..." << std::boolalpha << tree.insert(13) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 12 into the tree..." << std::boolalpha << tree.insert(12) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 15 into the tree..." << std::boolalpha << tree.insert(15) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 11 into the tree..." << std::boolalpha << tree.insert(11) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 2 into the tree..." << std::boolalpha << tree.insert(2) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 6 into the tree..." << std::boolalpha << tree.insert(6) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to insert 14 into the tree..." << std::boolalpha << tree.insert(14) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);

    std::cout << "\nAttempting to insert 6 into the tree..." << std::boolalpha << tree.insert(6) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);

    std::cout << "\nAttempting to insert 9 into the tree..." << std::boolalpha << tree.insert(9) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);

    std::cout << "\nAttempting to insert 4 into the tree..." << std::boolalpha << tree.insert(4) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);

    std::cout << "\nAttempting to insert 1 into the tree..." << std::boolalpha << tree.insert(1) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);

    std::cout << "\nAttempting to insert 3 into the tree..." << std::boolalpha << tree.insert(3) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);

    std::cout << "\nAttempting to insert 5 into the tree..." << std::boolalpha << tree.insert(5) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);

    std::cout << "\nAttempting to insert 7 into the tree..." << std::boolalpha << tree.insert(7) << std::endl;
    std::cout << "Ugly printing the tree...\n" << std::endl;
    ugly_print_tree(tree);
}

void part2() {
    std::cout << "--- Part 2 output ---" << std::endl;

    BST tree;

    std::cout << "\nPretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nInserting 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7,\n          9, 11, 13, and 15 into the tree..." << std::endl;
    tree.insert(8);
    tree.insert(4);
    tree.insert(12);
    tree.insert(2);
    tree.insert(6);
    tree.insert(10);
    tree.insert(14);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.insert(9);
    tree.insert(11);
    tree.insert(13);
    tree.insert(15);

    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\ntree.contains(14) = " << std::boolalpha << tree.contains(14) << std::endl;
    std::cout << "tree.contains(4) = " << std::boolalpha << tree.contains(4) << std::endl;
    std::cout << "tree.contains(5) = " << std::boolalpha << tree.contains(5) << std::endl;
    std::cout << "tree.contains(15) = " << std::boolalpha << tree.contains(15) << std::endl;
    std::cout << "tree.contains(2) = " << std::boolalpha << tree.contains(2) << std::endl;
    std::cout << "tree.contains(-3) = " << std::boolalpha << tree.contains(-3) << std::endl;
    std::cout << "tree.contains(17) = " << std::boolalpha << tree.contains(17) << std::endl;
    std::cout << "tree.contains(35) = " << std::boolalpha << tree.contains(35) << std::endl;
}

void part3() {
    std::cout << "--- Part 3 output ---" << std::endl;

    BST tree;

    std::cout << "\nPretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nInserting 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7,\n          9, 11, 13, and 15 into the tree..." << std::endl;
    tree.insert(8);
    tree.insert(4);
    tree.insert(12);
    tree.insert(2);
    tree.insert(6);
    tree.insert(10);
    tree.insert(14);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.insert(9);
    tree.insert(11);
    tree.insert(13);
    tree.insert(15);

    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 6 from the tree..." << std::boolalpha << tree.remove(6) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 5 from the tree..." << std::boolalpha << tree.remove(5) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 7 from the tree..." << std::boolalpha << tree.remove(7) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 2 from the tree..." << std::boolalpha << tree.remove(2) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 1 from the tree..." << std::boolalpha << tree.remove(1) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 9 from the tree..." << std::boolalpha << tree.remove(9) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 11 from the tree..." << std::boolalpha << tree.remove(11) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 2 from the tree..." << std::boolalpha << tree.remove(2) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 10 from the tree..." << std::boolalpha << tree.remove(10) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 9 from the tree..." << std::boolalpha << tree.remove(9) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 15 from the tree..." << std::boolalpha << tree.remove(15) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 13 from the tree..." << std::boolalpha << tree.remove(13) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 14 from the tree..." << std::boolalpha << tree.remove(14) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 12 from the tree..." << std::boolalpha << tree.remove(12) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 8 from the tree..." << std::boolalpha << tree.remove(8) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 10 from the tree..." << std::boolalpha << tree.remove(10) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 3 from the tree..." << std::boolalpha << tree.remove(3) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nAttempting to remove 4 from the tree..." << std::boolalpha << tree.remove(4) << std::endl;
    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);
}

void part4() {
    std::cout << "--- Part 4 output ---" << std::endl;

    BST tree;

    std::cout << "\nPretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nInserting 1, 2, and 3 into the tree..." << std::endl;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);

    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);

    std::cout << "\nClearing the tree..." << std::endl;
    tree.clear();

    std::cout << "Pretty printing the tree...\n" << std::endl;
    pretty_print_tree(tree);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [TEST]" << std::endl;
        std::cerr << "where TEST is one of 1, 2, 3, 4, or all" << std::endl;
        return 1;
    }

    std::string test = argv[1];

    if (test == "1") {
        part1();
    } else if (test == "2") {
        part2();
    } else if (test == "3") {
        part3();
    } else if (test == "4") {
        part4();
    } else if (test == "all") {
        part1();

        std::cout << "\n\n";
        part2();

        std::cout << "\n\n";
        part3();

        std::cout << "\n\n";
        part4();
    } else {
        std::cerr << test << " is not a valid test to run. The valid options are 1, 2, 3, 4, and all"
            << std::endl;
        return 1;
    }

    return 0;
}
