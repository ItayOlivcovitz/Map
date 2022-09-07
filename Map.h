#pragma once
#include "Binary tree.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using std::string;
using std::to_string;
using std::cout;
using std::endl;

template<class K = int , class V  = string>
class Map
{
	node<K,V>* element;
	int numberOfElements = 0;
	
	/**
    * @brief find the proper place if the key is int
    */
	void placeInt( node<int,V>* head , int const key, int const value )
	{
		//ptr to  newNode
		node<K, V>* newNode = new node<K, V>();
		newNode->value = value;
		newNode->key = key;

		
		if (head->key == NULL)
		{
			head->key = key;
			head->value = value;
		}
		//If the new value should be on the right side
		if(head->key < key)
		{
		    if (head->right == NULL )
		    {
				head->right = newNode;
		    }
			else
			{
				placeInt(head->right, key, value);
			}
		}

		else //If the new value should be on the left side
			if (head->key > key)
			{
				if (head->left == NULL)
				{
					head->left = newNode;
				}
				else
				{
					placeInt(head->left, key, value);
				}
			}

			
	}
	
	void spaces(const int spaces, const int hight) const
	{
		for (int i = 0; i < hight; i++)
		{
			for (int j = 0; j < spaces; j++)
			{
				cout << " " ;
			}
		}
	}
	void printer(node<K, V>* head,int hight) const
	{

		spaces(4, hight);
		if (head == NULL)
		{
			cout << "NULL";
		}
		else
		{
			head->print();
		}
		
			printer(head->left,hight -1);
			printer(head->right , hight-1);
		

		
	}

	/**
	* @brief find the hight of a given tree 
	*
	* @param head - node<int,V>* ptr to the root
	*/
	int treeHight(const node<K, V>* head) const
	{
		if (head == NULL || (head->right == NULL && head->left == NULL))
		{
			return 0;
		}
		if (head->right != NULL && head->left != NULL)
		{
			if (treeHight(head->right) > treeHight(head->left))
			{
				return 1 + treeHight(head->right);
			}
			else
			{
				return 1 + treeHight(head->left);
			}
			
		}

		if (head->right != NULL)
		{
			return 1 + treeHight(head->right);
		}

		if (head->left != NULL)
		{
			return 1 + treeHight(head->left);
		}
	}

public:
	Map()
	{
		element = new node<K,V>;
		element->value = NULL;
		element->key = NULL;
		element->left = NULL;
		element->right = NULL;
	}
	 
	/**
    * @brief insert object.
    *
    * @param key - Item's key
    * @param value - Item's value
    */
	void insert(K const key,V const value) 
	{
		this->numberOfElements +=1;
		placeInt(this->element,key ,value);
	}
	int getHight() const
	{
		return treeHight(this->element);
	}

	/**
	* @brief print tree.
	*/
	void print() const
	{
		printer(this->element, this->getHight());
	}

	~Map()
	{
	}
};
