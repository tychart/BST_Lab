# BST Lab

## Purpose
To learn how to add to, remove from, and search in a binary search tree. 

This lab will prepare
you for the upcoming AVL lab.

### A word to the wise

You will build off your code in this lab for the following AVL lab.

An AVL tree is a special kind of binary search tree. 
In order to implement the AVL properly, it is critical that you follow the 
instructions for implementing a regular BST correctly.

1. Implement this lab using recursion. 
   There are other ways to implement a BST, but they do not extend well to AVL.
1. Make sure you understand all the code you write for this lab. Understand how the recursion works.

## Background
A binary search tree (BST), which may sometimes be called an ordered or sorted
binary tree, is a node-based data structure where each node holds a value, a
left child, and a right child. Binary search trees are characterized by the
following properties:

* The left subtree of a node contains only nodes with values less than the
  node's value.
* The right subtree of a node contains only nodes with values greater than the
  node's value.
* There are no duplicate values.
* Both the left and right subtrees of a node also must be binary search trees
  (each subtree must have the first three properties).
  
[Wikipedia: Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)

## Requirements
You will need the files in this repository to complete this assignment. Clone
the repository to get started.

### Part 1 - Inserting nodes into to the tree (20 points)
* Implement the `getRootNode()` and `insert()` methods from the `BSTInterface`.
* A `Node` class is provided for you in `Node.h`. You must use this class in your implementation of BST. 
  You'll make a node with `new Node(data)`, access its left and right
  pointers with `node->left` and `node->right`, and access its data with
  `node->data`.
* If a call to `insert` is attempting to add an element that is already in the
  tree, you should not insert it.
* The return value indicates whether the data was inserted or not.

### Part 2 - Contains (20 points)
* Implement the `contains()` method from `BSTInterface`.

### Part 3 - Remove (20 points)
* Implement the `remove()` method from `BSTInterface`.
* If the element to be removed is not in the tree, `remove` should do nothing.
* The return value indicates whether an element was removed or not.
* There are multiple correct methods for removing nodes from a tree, but each
  method may result in a different tree. In order to make sure that your tree
  matches the tree the tests expect:
  * When removing a node with only one child, replace that node with
  its child. 
  * When removing nodes with two children, use the in-order predecessor
  of the node to be removed.

### Part 4 - Clear (20 points)
* Implement the `clear()` method from `BSTInterface`.

## Testing your code

You are provided with two files for testing: `scratch.cpp` and `tests.cpp`. If
you download this repository and directly open the folder as a project in CLion,
CLion will be automatically configured with both files ready to be compiled and
executed. You can switch between the two using the drop-down menu to the left of
the green play button.

`scratch.cpp` is provided to you as a convenience. You can use it to write your
own test cases.

`tests.cpp` has the actual tests that you will be graded on. The output it
generates using your implementation of a BST will be expected to exactly match
the contents of `key_file1.txt` for part 1, `key_file2.txt` for part 2, and so
on.

`printing.h` defines two functions that will be used in `tests.cpp`, and which
you can also use in `scratch.cpp`: `pretty_print_tree` and `ugly_print_tree`.
`pretty_print_tree` outputs a representation of your tree that is in a tree-like
shape. For instance, if `tree` has the following structure:

```
       15
      /  \
     /    \
   13      17
  /       /  \
12      16    18
```

then `pretty_print_tree(tree)` will output the following:

```
      15

  13      17

12      16  18
```

Hopefully, it shouldn't be too hard to tell which nodes are the children of
which.

One disadvantage of `pretty_print_tree` is that the width of the printout
explodes as the tree gets taller. For instance, the printout of a tree with
height 6 will be around 125 characters wide, and the width about doubles with
each additional level. Secondly, the function is only written to deal with
numbers that have at most 2 digits. Therefore, if you need to visualize a tree
that is either taller or has bigger numbers, `ugly_print_tree` might be a better
option. Its output is a bit harder to read, but can work for bigger trees.

`ugly_print_tree` prints each node in the following format:

```
node: left_child right_child
```

where `node` is replaced with the node's number, and both `left_child` and
`right_child` are replaced with the node's child, or `__` if the node doesn't
have one.

For instance, if the `tree` has the following structure:

```
       15
      /  \
     /    \
   13      17
  /       /  \
12      16    18
```

then `ugly_print_tree(tree)` will output the following:

```
15: 13 17
13: 12 __
12: __ __
17: 16 18
16: __ __
18: __ __
```

Once you have finished implementing your binary search tree, turn your `BST.h`
and any other files you write in to Gradescope.

## Tips

For tips on implementing the lab, see [HelpfulTips.md](HelpfulTips.md).
