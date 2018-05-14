//bst.cpp
//Aaron Nicanor
//anicanor

//libraries
#include<iostream>
#include<vector>
#include<string>
#include<queue>

#include"bst.h"

//Constructor
BST::BST(){

	m_root = NULL;
}

//Function for insertion from the vector
void BST::VectorInsert(vector<string> & values){

	if (values.size() == 0)
	  return;
	
	int start = 0;
	int last = values.size() - 1;
	VectorInsert(values,start,last);
}
void BST::VectorInsert(vector<string> & values, int firstIndex, int lastIndex){

	if (firstIndex == lastIndex){
  
		insert(values[firstIndex]);
		return;
	}
  
	if (lastIndex == -1 || lastIndex < firstIndex)
	  return;
	
	int middleIndex;
	int vectorSize;
	vectorSize = lastIndex - firstIndex;
	if(firstIndex == 0){
  
		middleIndex = vectorSize/2;
		insert(values[middleIndex]);
	}
	else{
  
		middleIndex = vectorSize/2 + firstIndex;
		insert(values[middleIndex]);
	}
	VectorInsert(values, middleIndex + 1, lastIndex);
	VectorInsert(values, firstIndex, middleIndex - 1);
}

//Balanced function
int BST::returnBalanced(){

	return balanced (m_root);
}

int BST::balanced(Node* currentRoot){

	if(currentRoot == NULL)
	  return 0;

	int rightHeight;
	int leftHeight;
	leftHeight = 1 + balanced(currentRoot -> m_left);
	rightHeight = 1 + balanced(currentRoot -> m_right);
	int diff = leftHeight - rightHeight;
	if (abs(diff) > 1)
		return -1;
	
	else if (leftHeight == 0 || rightHeight == 0)
		return -1;
	
	else
	{
		if(rightHeight < leftHeight)
		  return leftHeight;
		
		else
		  return rightHeight;
		
	}
}

//This function will provide the number of Nodes for the tree
int BST::numNodes(){

	return numNodes(m_root);
}

int BST::numNodes(Node* currentRoot){

	if (!currentRoot)
	  return 0;

	return 1 + numNodes(currentRoot -> m_left) + numNodes(currentRoot -> m_right);
}

//Functions for inserting
bool BST::insert(string input){

	return insert(input, m_root);
}

bool BST::insert(string input, Node* & currentRoot){

	if (currentRoot == NULL){
  
		currentRoot = new Node(input, currentRoot);
		return true;
	}

	if(input == currentRoot -> m_string)
		return false;
	

	if (input < currentRoot -> m_string)
		insert(input, currentRoot -> m_left);
		
	else
		insert(input, currentRoot -> m_right);
	
	return true;	
}

//Function that gets the value
bool BST::find(string input){

	return find(input, m_root);
}

bool BST::find(string input, Node* currentRoot){

	if (currentRoot == NULL){  
		return false;
	
	if (currentRoot -> m_string == input)	
		return true;
	
	if (input > currentRoot -> m_string)
		return find(input, currentRoot -> m_right);
	
	else if (input < currentRoot -> m_string)
		return find(input, currentRoot -> m_left);
	
	return false;
}

//Gets the distance
double BST::distance(){

	double total = 0;
	double avg;
	double size = (double) numNodes();
	total = distance(m_root, total);
	avg = total/size;
  
	return avg;
}
double BST::distance(Node* currentRoot, double d){

	if (currentRoot == NULL)
	  return 0;
	
	return d + distance(currentRoot -> m_right, d + 1) + distance(currentRoot -> m_left, d + 1);
}

//Functions for printing
void BST::print(vector<string> & values){

	print(values, m_root);
}

void BST::print(vector<string> & values, Node* currentRoot){

	if (currentRoot == NULL)
	  return;
    
	print(values, currentRoot -> m_left);
	values.push_back(currentRoot -> m_string);
	print(values, currentRoot -> m_right);
}

//Sets width
void BST::width(vector<string> & values){

	width(values, m_root);
}

void BST::width(vector<string> & values, Node* currentRoot){

	queue<Node*> Queue;
	Queue.push(m_root);
	while (Queue.size() > 0){
  
		if (Queue.front() -> m_right != NULL)
			Queue.push(Queue.front() -> m_right);
		
		if (Queue.front() -> m_left != NULL)
			Queue.push(Queue.front() -> m_left);
		
		values.push_back(Queue.front() -> m_string);
		Queue.pop();
	}
}

//Function for removal
void BST::remove(){

	remove(m_root);
}

void BST::remove(Node* & currentRoot){

	if(currentRoot == NULL)
	  return;

	remove(currentRoot -> m_left);
	remove(currentRoot -> m_right);
	delete currentRoot;
	currentRoot = NULL;
}
