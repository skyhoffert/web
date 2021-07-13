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

    int Size();

private:

    int _n_children;
    WebNode* _root;

    int _size;

};
