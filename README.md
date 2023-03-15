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

### Part 1 - Inserting nodes into to the tree (15 points)
* Implement the `getRootNode()` and `insert()` methods from the `BSTInterface`.
* A `Node` class is provided for you in `Node.h`. You must use this class in your implementation of BST. 
  You'll make a node with `new Node(data)`, access its left and right
  pointers with `node->left` and `node->right`, and access its data with
  `node->data`.
* If a call to `insert` is attempting to add an element that is already in the
  tree, you should not insert it.
* The return value indicates whether the data was inserted or not.

### Part 2 - Contains (15 points)
* Implement the `contains()` method from `BSTInterface`.

### Part 3 - Remove (15 points)
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

### Part 4 - Clear (15 points)
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

### Passing `Node` pointers by reference

When you write `insert` and `remove`, you'll need to be
able to update pointers. For instance, in `insert`, when you see a `nullptr`,
that's when you need to insert a node:
```cpp
bool insert_helper(Node* node, int data) {
    if (node == nullptr) {
        // insert a node
        return true;
    }
    // handle other cases
}
```

So you might be tempted to write your function like this:
```cpp
bool insert_helper(Node* node, int data) {
    if (node == nullptr) {
        node = new Node(data);
        return true;
    }
    // handle other cases
}
```
The problem with that, however, is that you'd update `node` to point to the
brand-new node you made...only for the function to return and the parent node's
`left` or `right` pointer to still be `nullptr`. The issue here is that by
default, C++ passes function arguments by value. This means that it copies the
argument into the function, and therefore any changes to arguments don't reflect
outside of the function. But in this case, we actually want the change to affect
the surrounding environment, as otherwise, the parent node won't be able to see
its new child. Fortunately, C++ supports passing by reference by putting an
ampersand after the parameter's type. In this case, the parameter's type is a
`Node*`, so we get the awkward-looking `Node*&`:
```cpp
bool insert_helper(Node*& node, int data) {
    if (node == nullptr) {
        node = new Node(data);
        return true;
    }
    // handle other cases
}
```
Now, when you make `node` point to something else, everyone will see the change.
The same logic applies to `remove`.

### Learning moment - crazy C++ syntax
All these asterisks and ampersands in C++ can be scary, but it might be helpful
to understand that a pointer is just another type, like `int`s, `string`s,
`vector`s, and `map`s. It's just that the way we name a pointer type is by
putting an asterisk after the type it's pointing to. For instance, a pointer to
an `int` is written as `int*`. And in the context of the BST lab, we're working
with pointers to `Node`s, or `Node*`s.

Another use of the asterisk in C++ is as an operator, where the operation is to
follow pointers to where they point to. This is called dereferencing. So, if you
have a pointer to an `int` called `p_int`, and you want to read the value
contained at the address that `p_int` is pointing to, you can dereference
`p_int` with the following code:
```cpp
*p_int
```
And if you want to change the value contained at the address that `p_int` is
pointing to, you can write the following:
```cpp
*p_int = new_value;
```
However, if you want to change where `p_int` points to, you don't dereference
it, but just treat it as a regular C++ variable:
```cpp
p_int = new_pointer_value;
```

The confusing thing about the ampersand in C++ is that like the asterisk, it
also has two jobs. The one that we've already seen is to name a reference type.
For example, a reference to an `int` would be written as `int&`. The other job
of an ampersand is to create a pointer. So, one way to get a pointer in C++ is
by using the `&` operator. This operator takes a variable as an operand and
returns the address that the variable is stored in:
```cpp
int a = 5;
// The next line makes b point to the location that a's value is stored at.
// Confusingly, b also has a location where it is stored. The value at that
// location is a's location.
int* b = &a;
```

Another way to get pointers in C++—which is the way that you'll get `Node*`s in
this lab—is by allocating things on the heap using the `new` keyword.

The last thing that's helpful to understand is the `->` operator. As you'll
recall, we can make classes in C++ that hold data members and have methods. The
way you access those data members and methods is using the `.` operator. So for
example, the `Node` class has a data member called `data` that holds an element
of the BST. So if you had a `Node`, you could access its data by writing:
```cpp
node.data
```
The problem is that you don't have a `Node`; you have a `Node*`. This means that
you need to dereference the pointer to get at its data. Unluckily, the `*`
operator has lower precedence than the `.` operator. So if you were to write:
```cpp
*node.data
```
The compiler would fail to compile your code, since it's first trying to get
`node.data`, then derefence the result of that operation. But since `Node*`s
don't have a data member called `data`, that operation fails. You need to
dereference the pointer first, then access the data member of the `Node` pointed
to by the pointer:
```cpp
(*node).data
```
This is annoying to write over and over, so the creators of C++ made a
shorthand:
```cpp
node->data
```
So all the `->` does is dereference the pointer, then access whatever is
contained in the location pointed to by the pointer.

**In summary:**
* Pointers aren't magic. They're just regular old C++ variables. In fact,
  they're just a number that's interpreted as an address in memory.
* The `*`, `&`, and `->` symbols in C++ aren't magic; all three symbols
  represent a specific operation to do with pointers, and `*` and `&` both
  additionally enable you to name certain types in C++.
* Both `*` and `&` can be used in C++ to name types. `T*` names a
  pointer to a `T`, while `T&` names a reference to a `T`.
* Both `*` and `&` can additionally be used as an operator. `*v` dereferences
  the pointer `v`, while `&v` takes the address of `v`.
* `v->data_member` is just a shorthand for `(*v).data_member`.
