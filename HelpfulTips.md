Below, you'll find tips that'll help you implement the BST lab.

# Passing `Node` pointers by reference

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

## Learning moment - crazy C++ syntax
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
