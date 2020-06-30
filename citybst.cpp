// Rutigliano, Matthew
// citybst.cpp
// 5/18/20

// Description: Implementation of CityBST class

// Assumptions: None

// Sources: Dr. Kong's "formatting.txt"
//          "Lecture7-BST.pdf"
//          My own "lab3.cpp"
//          carjalal's post on 
//          https://stackoverflow.com/questions/7276826/c-format-number-with-commas

#include "citybst.h"

// Default Constructor
CityBST::CityBST(){
  root = nullptr;
}

// Copy Constructor
CityBST::CityBST(const CityBST& obj){
  root = clone(obj.root);
}

// Overloaded Assignment Operator
CityBST& CityBST::operator=(const CityBST& obj){
  if (&obj != this){
    deleteTree(root);
    root = clone(obj.root);
  }
  return *this;
}

// Clone (helper function for copying tree)
CityBST::TreeNode* CityBST::clone(TreeNode* t){
  if (!t)
    return nullptr;
  else
    return new TreeNode{t->key, t->country, t->population, 
     clone(t->left), clone(t->right)};
}

// Destructor
CityBST::~CityBST(){
  deleteTree(root);
}

// deleteTree (Helper function for destructor)
void CityBST::deleteTree(TreeNode* &n){
  if (n){
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
  }
}

// Insert
void CityBST::insert(string name, string ctry, int pop){
  TreeNode* newNode = new TreeNode;
  newNode->key = name;
  newNode->country = ctry;
  newNode->population = pop;
  newNode->left = nullptr;
  newNode->right = nullptr;
  insert(root, newNode);
}

// Insert helper function
void CityBST::insert(TreeNode*& root, TreeNode*& newNode){
  if (!root){
    root = newNode;
  }
  else if (root->key > newNode->key)
    insert(root->left, newNode);
  else if (root->key < newNode->key)
    insert(root->right, newNode);
  else
    delete newNode;
}

// Remove
bool CityBST::remove(string name){
  return remove(root, name);
}

// Remove helper function
bool CityBST::remove(TreeNode*& n, string name){
  if (!n)
    return false;
  if (name < n->key)
    return remove(n->left, name);
  else if (name > n->key)
    return remove(n->right, name);
  else if (n->left && n->right){
    n->key = findMin(n->right)->key;
    remove(n->right, n->key);
    return true;
  } else {
    TreeNode* oldNode = n;
    n = (n->left) ? n->left : n->right;
    delete oldNode;
    return true;
  }
}

// findMin (remove helper function)
CityBST::TreeNode* CityBST::findMin(TreeNode* node){
  if (!node)
    return nullptr;
  if (!node->left)
    return node;
  return findMin(node->left);
}

// getHeight
int CityBST::getHeight(){
  return getHeight(root);
}

// getHeight helper function
int CityBST::getHeight(TreeNode* n){
  if (!n)
    return -1;
  else
    return 1 + max(getHeight(n->left), getHeight(n->right));
}

// Print
void CityBST::print(){
  print(root);
}

// Print helper function
void CityBST::print(TreeNode* n){
  if (n){
    print(n->left);
    cout << n->key << endl;
    print(n->right);
  }
}

// printCity
void CityBST::printCity(string name){
  printCity(root, name);
}

// printCity helper function
void CityBST::printCity(TreeNode* node, string i){
  if (!node)
    return;
  else if (node->key == i){
    string numWithCommas = to_string(node->population);
    int insertPosition = numWithCommas.length() - 3;
    while (insertPosition > 0) {
        numWithCommas.insert(insertPosition, ",");
        insertPosition-=3;
    }
    cout << "City: " + node->key << "\nCountry: " + node->country
     << "\nPopulation: " << numWithCommas << endl;
  }
  else if (node->key > i)
    printCity(node->left, i);
  else
    printCity(node->right, i);
}

// biggestCity
string CityBST::biggestCity(){
  string  cityName = "";
  TreeNode* bigCity = biggestCity(root);
  if (bigCity)
    cityName = bigCity->key;
  return cityName;
}

// biggestCity helper function
CityBST::TreeNode* CityBST::biggestCity(TreeNode* n){
  if (!n)
    return nullptr;
  else{
    TreeNode* left =  biggestCity(n->left);
    TreeNode* right =  biggestCity(n->right);
    TreeNode* max = nullptr;
    
    if (left && right){
      max = (left->population > right->population) ? left : right;
      max = (max->population > n->population) ? max : n;
    }
    else if (left){
      max = (left->population > n->population) ? left : n;
    }
    else if (right){
      max = (right->population > n->population) ? right : n;
    }
    else {
      max = n;
    }
    return max;
  }
}