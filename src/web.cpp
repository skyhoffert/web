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
    printf("DEBUG:WebNode init started.\n");

    _n_children = n_children;

    _children = new WebNode*[_n_children];

    for (int i = 0; i < _n_children; ++i) {
        printf("DEBUG:Creating child %d as nullptr.\n", i);
        _children[i] = nullptr;
    }

    printf("DEBUG:WebNode init ended.\n");
}

WebNode::~WebNode() {
    printf("DEBUG:WebNode destr started.\n");

    for (int i = 0; i < _n_children; ++i) {
        printf("DEBUG:Deleting child %d.\n", i);
        if (_children[i] != nullptr) {
            delete _children[i];
            _children[i] = nullptr;
        }
    }

    printf("DEBUG:WebNode destr ended.\n");
}

// WebNode implementations.
///////////////////////////////////////////////////////////////////////////////
// Web implementations.

Web::Web(int n_children) {
    printf("DEBUG:Web init started.\n");

    _n_children = n_children;
    _size = 0;

    _root = nullptr;
    
    printf("DEBUG:Web init ended.\n");
}

Web::~Web() {
    printf("DEBUG:Web destr started.\n");

    if (_root != nullptr) {
        delete _root;
        _root = nullptr;
    }
    
    printf("DEBUG:Web destr ended.\n");
}

int Web::Size() { return _size; }

// Web implementations.
///////////////////////////////////////////////////////////////////////////////
