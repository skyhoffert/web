//
// Sky Hoffert
// Web data structure implementations.
// Created Jul-12-2021.
// Last modified Jul-18-2021.
//

#include "web.hpp"

#include <cstdio>

///////////////////////////////////////////////////////////////////////////////
// WebNode implementations.

WebNode::WebNode(int n_children, int value) {
    _n_children = n_children;

    _children = new WebNode*[_n_children];

    for (int i = 0; i < _n_children; ++i) {
        _children[i] = nullptr;
    }

    _value = value;
}

WebNode::~WebNode() {
    for (int i = 0; i < _n_children; ++i) {
        if (_children[i] != nullptr) {
            delete _children[i];
            _children[i] = nullptr;
        }
    }
}

int WebNode::Insert(int v) {
    for (int i = 0; i < _n_children; ++i) {
        // If eventually there is an empty child, insert here.
        if (_children[i] == nullptr) {
            _children[i] = new WebNode(_n_children, v);
            return 0;
        }

        // If value already exists, don't do anything.
        if (_children[i]->Value() == v) { return 0; }

        // If this child has a larger value, insert below this child.
        if (_children[i]->Value() > v) {
            return _children[i]->Insert(v);
        }
    }

    // TODO(sky): if all children are less, rotation needed.

    // Otherwise, return error.
    return -1;
}

int WebNode::Remove(int v) {
    // TODO(sky): implement
    return -1;
}

WebNode* WebNode::ChildTowardsValue(int v) {
    for (int i = 0; i < _n_children; ++i) {
        if (_children[i] == nullptr) { continue; }
        if (_children[i]->Value() >= v) {
            return _children[i];
        }
    }

    return nullptr;
}

int WebNode::Value() { return _value; }

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
    if (_root == nullptr) {
        _root = new WebNode(_n_children, v);
        return 0;
    }

    return _root->Insert(v);
}

int Web::Remove(int v) {
    return _root->Remove(v);
}

WebNode* Web::Find(int v) {
    if (_root == nullptr) { return nullptr; }

    if (_root->Value() == v) { return _root; }

    WebNode* node = _root;
    
    while (node != nullptr) {
        node = node->ChildTowardsValue(v);
        if (node == nullptr) { break; }
        if (node->Value() == v) { return node; }
    }

    return nullptr;
}

bool Web::Contains(int v) {
    return Find(v) != nullptr;
}

int Web::Size() { return _size; }

// Web implementations.
///////////////////////////////////////////////////////////////////////////////
