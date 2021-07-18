//
// Sky Hoffert
// Web data structure definitions.
// Created Jul-12-2021.
// Last modified Jul-18-2021.
//

// TODO(sky): not ALL nodes need these functions...
class WebNode {
public:

    WebNode(int n_children, int value);
    ~WebNode();

    // Adds a value to this or child webnodes. This function call will either
    // add a new child with value v on THIS node or call Insert on suitable
    // child. Recursively does this.
    //
    // @param v(int): value to be inserted.s
    // @return int: 0 on success, error code otherwise.
    int Insert(int v);

    // Removes node from web, if possible.
    //
    // @param v(int): value to be removed.
    // @return int: 0 on success, error code otherwise.
    int Remove(int v);

    // Finds and returns the appropriate child that goes towards value v.
    //
    // @param int v: value being searched for.
    // @return WebNode*: Pointer to child in direction of v.
    WebNode* ChildTowardsValue(int v);

    // Getter for _value.
    //
    // @return int: _value
    int Value();

private:

    // TODO(sky): this should be templated!
    int _value;

    int _n_children;

    WebNode* _parent;
    WebNode** _children;

};

class Web {
public:

    Web(int n_children);
    ~Web();

    // Adds a value to this web instance.
    //
    // @param v(int): value to be inserted.
    // @return int: 0 on success, error code otherwise.
    int Insert(int v);

    // Removes a value from this web instance.
    // 
    // @param v(int): value to be removed.
    // @return int: 0 on success, error code otherwise.
    int Remove(int v);

    // Finds a node in this web, if possible.
    //
    // @param v(int): value to be found.
    // @return WebNode*: ptr to the node, nullptr if not found.
    WebNode* Find(int v);

    // Determines if a value exists in this instance.
    //
    // @param v(int): value to be searched for.
    // @return bool: true if value exists in this instance.
    bool Contains(int v);
    
    // Returns the number of "nodes" within this web instance.
    //
    // @return int: number of nodes in this web.
    int Size();

private:

    int _n_children;
    WebNode* _root;

    int _size;

};
