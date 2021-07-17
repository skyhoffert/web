//
// Sky Hoffert
// Web data structure definitions.
// Created Jul-12-2021.
// Last modified Jul-12-2021.
//

class WebNode {
public:

    WebNode(int n_children);
    ~WebNode();

    WebNode* FirstChildWithAtMost(int v);

private:

    // TODO(sky): this should be templated!
    int _val;

    int _n_children;

    WebNode* _parent;
    WebNode** _children;

};

class Web {
public:

    Web(int n_children);
    ~Web();

    // Adds a value to this web instance.
    // TODO(sky): are duplicates allowed?
    //
    // @param v(int): value to be inserted.
    // @return int: 0 on success, error code otherwise.
    int Insert(int v);

    // Removes a value from this web instance.
    // 
    // @param v(int): value to be removed.
    // @return int: 0 on success, error code otherwise.
    int Remove(int v);

    // Finds a value in this web, if possible.
    //
    // @param v(int): value to be found.
    // @return int: 0 on success, error code otherwise.
    int Find(int v);
    
    // Returns the number of "nodes" within this web instance.
    //
    // @return int: number of nodes in this web.
    int Size();

private:

    int _n_children;
    WebNode* _root;

    int _size;

};
