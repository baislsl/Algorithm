//
// Created by baislsl on 17-6-8.
//

#ifndef ALGORITHM_BTREE_H
#define ALGORITHM_BTREE_H

template<typename T>
class BNode {
public:
    typedef T *Pointer;
    typedef T Element;
    Pointer left, right;
    Element e;

    BNode() {

    }

    BNode(Element _e) : e(_e), left(nullptr), right(nullptr) {}

};


template <typename T>
class BTree{
    typedef T *Pointer;
    typedef T Element;

    BTree():root(nullptr){}

    void insert(const Element &e){

    }

    void find(const Element &e){
        Pointer cur = root;

    }

private:
    Pointer root;

};


#endif //ALGORITHM_BTREE_H
