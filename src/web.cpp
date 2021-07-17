//
// Sky Hoffert
// Web data structure implementations.
// Created Jul-12-2021.
// Last modified Jul-12-2021.
//

#include "web.hpp"

#include <cstdio>

///////////////////////////////////////////////////////////////////////////////
// WebNode implementations.

WebNode::WebNode(int n_children) {
    _n_children = n_children;

    _children = new WebNode*[_n_children];

    for (int i = 0; i < _n_children; ++i) {
        printf("DEBUG:Creating child %d as nullptr.\n", i);
        _children[i] = nullptr;
    }
}

WebNode::~WebNode() {
    for (int i = 0; i < _n_children; ++i) {
        printf("DEBUG:Deleting child %d.\n", i);
        if (_children[i] != nullptr) {
            delete _children[i];
            _children[i] = nullptr;
        }
    }
}

WebNode* WebNode::FirstChildWithAtMost(int v) {
    // TODO(sky): implement.
    return nullptr;
}

// WebNode implementations.
///////////////////////////////////////////////////////////////////////////////
// Web implementations.

Web::Web(int n_children) {
    _n_children = n_children;
    _size = 0;

    _root = nullptr;
}

Web::~Web() {
    if (_root != nullptr) {
        delete _root;
        _root = nullptr;
    }
}

int Web::Insert(int v) {
    // TODO(sky): implement with WebNode methods. First find.
    return -1;
}

int Web::Remove(int v) {
    // TODO(sky): implement with WebNode methods. First find.
    return -1;
}

int Web::Find(int v) {
    // TODO(sky): use this method.
    _root->FirstChildWithAtMost(v);

    return -1;
}

int Web::Size() { return _size; }

// Web implementations.
///////////////////////////////////////////////////////////////////////////////
