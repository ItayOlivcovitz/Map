#pragma once

#include <string>
#include <iostream>

using std::string;
using std::to_string;
using std::cout;
using std::endl; 

template<class K = int, class V = string>
struct node
{
    V value;
    K key;

    struct node* left;
    struct node* right;
public:

    void print() const
    {
        cout << "key :" << this->key << "   value :" << this->value <<endl;
    }
};