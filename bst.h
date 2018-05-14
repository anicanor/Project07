//bst.h
//Aaron Nicanor
//anicanor

#ifndef BST_H_
#define BST_H_

//Included Libraries
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class BST{

	public:
		BST();
		void VectorInsert(vector<string> &);    
		int returnBalanced();
		int numNodes();
		bool insert(string);
		bool find(string);    
		double distance();
		void print(vector<string> &);
		void width(vector<string> &);
		void remove();
    
	private:
    //Node class
		class Node{
    
				public:
					Node(string string_input, Node* root, Node* right = NULL, Node* left = NULL){
            m_string = string_input; m_right = right; m_left = left;
          }
          
					Node* m_left;
					Node* m_right;
					string m_string;
    };
    
	  Node* m_root;
		void VectorInsert(vector<string> &, int, int);
		int balanced(Node*);
		int numNodes(Node*);
		bool insert(string, Node* &);
		bool find(string, Node*);   
		void remove(Node* &);
		void width(vector<string> &, Node*);
		void print(vector<string> &, Node*);
		double distance(Node*, double);
};

#endif
