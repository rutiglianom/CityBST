// Rutigliano, Matthew
// citybst.h
// 5/18/20

// Description: The CityBST class creates an ordered binary search
// tree holding information about cities. Each node holds a city name,
// country, and population. The nodes are ordered alphabetically by
// the city name. In addition to the expected insert, remove and getHeight,
// print prints the entire list inorder, printCity prints the known
// information of a specific city, and biggestCity returns the city with
// the highest population.

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"

#include <iostream>
#include <cstring>

using namespace std;

#ifndef CITYBST_H
#define CITYBST_H

class CityBST {
  private:
  
    // Node Structure
    struct TreeNode{
      string key; //name of the city
      string country; 
      int population;
      TreeNode* left;
      TreeNode* right;
    }; 
 
    TreeNode* root;
    
    void deleteTree(TreeNode*&);
    // Helper function for destructor
    // Pre: CityBST has been initialized
    // Post: Dynamic memory has been deallocated
    
    TreeNode* clone(TreeNode*);
    // Helper function for copy constructer and assignment operator
    // Pre: None
    // Post: Root of duplicate tree has been returned
    
    void printCity(TreeNode*, string);
    // Helper function for printCity
    // Pre: CityBST has been initialized
    // Post: City has been located and its information printed
    
    void insert(TreeNode*&, TreeNode*&);
    // Helper function for insert
    // Pre: CityBST has been initialized, 
    // Node has been created holding new information
    // Post: Node has been sorted into the proper location
    
    bool remove(TreeNode*&, string);
    // Helper function for remove
    // Pre: CityBST has been initialized
    // Post: Node has been located, removed, and the tree
    // has been resorted
    
    TreeNode* findMin(TreeNode*);
    // Helper function for remove
    // Pre: CityBST has been initialized
    // Post: Min in a tree has been returned
    
    void print(TreeNode*);
    // Helper function for print
    // Pre: CityBST has been initialized
    // Post: Tree has been printed inorder
    
    TreeNode* biggestCity(TreeNode*);
    // Helper function for biggestCity
    // Pre: CityBST has been initialized
    // Post: City with largest population has been returned
    
    int getHeight(TreeNode*);
    // Helper function for getHeight
    // Pre: CityBST has been initialized
    // Post: Height of tree has been returned
    
  public:
  
    CityBST();
    // Default Constructor
    // Pre: None
    // Post: CityBST is initialized
    
    CityBST(const CityBST&);
    // Copy Constructor
    // Pre: CityBST to the right of operator has been initialized
    // Post: New CityBST is initialized, identical to the other
    
    CityBST& operator=(const CityBST&);
    // Overloaded Assignment Operator
    // Pre: Two CityBSTs have been initialized
    // Post: First CityBST is identical to the second
    
    ~CityBST();
    // Destructor
    // Pre: CityBST has been initialized
    // Post: Dynamic memory has been deallocated
    
    void insert(string, string, int);
    // Inserts new city with a country and population
    // Pre: CityBST has been initialized
    // Post: New node has been sorted into tree
    
    bool remove(string);
    // Removes city from tree, returning false if node isn't present
    // Pre: CityBST has been initialized
    // Post: Node has been removed if present
    
    int getHeight();
    // Returns height of tree, -1 if empty
    // Pre: CityBST has been initialized
    // Post: Height has been returned
    
    void print();
    // Prints tree using inorder traversal
    // Pre: CityBST has been initialized
    // Post: Contents of tree have been printed
    
    void printCity(string);
    // Prints information about specific city
    // Pre: CityBST has been initialized
    // Post: Information about city has been printed
    
    string biggestCity();
    // Returns city with highest population
    // Pre: CityBST has been initialized
    // Post: City with largest population has been returned
 
};

#endif // CITYBST_H