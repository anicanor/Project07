//main.cpp
//Aaron Nicanor
//anicanor

//Included Libraries
#include<iostream>
#include<vector>
#include<sstream>
#include<string>

#include"bst.h"

//Prototype
void VectorPrint(vector<string>);

using namespace std;

int main(){
  
  //Variable declaration
  BST tree;
  string input;
  string command;
  
  //This loop handles the user's commands
  while(cin >> command){
        
    if (command == "insert"){
    
      cin >> ws;
      bool insert;
      getline(cin, input);
      insert = tree.insert(input);
      //Error message
      if (!insert)
        cerr << "insert <" << input << "> failed. String already in tree." << endl;
        
    }else if (command == "find"){
      
      cin >> ws;
      bool find;
      getline (cin, input);
      find = tree.find(input);
      if (find == true)
        cout << "<" << input << ">" << " is in tree." << endl;

      else
        cout << "<" << input << ">" << " is not in tree." << endl;

     }else if (command == "size"){
      
        int treeSize; //finds the number of elements in the tree
        treeSize = tree.numNodes();
        cout << treeSize << endl;
        
      }else if (command == "echo"){
      
        cin >> ws;
        getline(cin, input);
        cout << input << endl;
        
       }else if (command == "breadth"){
        
          vector<string> strings;
          tree.width(strings);
          VectorPrint(strings);
          
        }else if (command == "distance"){
        
          cout << "Average distance of nodes to root = " << tree.distance() << endl;
          
        }else if (command == "balanced"){
        
          int balanced = tree.returnBalanced();
          if (balanced == -1)
            cout << "Tree is not balanced." << endl;

          else
            cout << "Tree is balanced." << endl;

         }else if (command == "rebalance"){
          
            vector<string> strings;
            tree.print(strings);
            tree.remove();
            tree.VectorInsert(strings);
            
          }else if (command == "print"){
          
            vector<string> strings;
            tree.print(strings);
            VectorPrint(strings);
            
          }else if (command == "delete"){
          
            tree.remove();
          
          //Will print out error message if input invalid command
          }else{
          
            string bad;
            getline(cin, bad);
            cerr << "Illegal command <" << command << ">." << endl;
          }
        }

        return 0;
}

//function
void VectorPrint (vector<string> values){

  cout << "{";
  for (unsigned int i = 0; i < values.size(); i++){
        
    cout << values[i];
    if (values.size() - 1 == i)
      continue;
    
    cout << ", ";
      
  }
  cout << "}" << endl;
}
