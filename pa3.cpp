// Rutigliano, Matthew
// pa3.cpp
// 5/18/20

// Description: Testbench for CityBST class. Scans in "cities.csv"
// file, inserting all of them into a CityBST. Other class functions
// are then rigorously tested.

// Assumptions: "cities.csv" has an initial throwaway header line, is
// formatted "city name, country, population \n

// Sources: Dr. Kong's "formatting.txt"
//          My own "pa1.cpp"

#include <iostream>
#include <fstream>
#include "citybst.h"

using namespace std;

int main() {
  string filename = "cities.csv";
  CityBST tree;
  
  // Scanning list into tree
  cout << "Scanning cities.csv file\n";
  string data[3];
  ifstream infile;
  infile.open(filename);
  if (infile){
    infile.ignore(256, '\n');
    while(!infile.eof()){
      getline(infile, data[0], ',');
      getline(infile, data[1], ',');
      getline(infile, data[2]);
      if (data[0] != ""){   // Avoids whitespace
        tree.insert(data[0], data[1], stoi(data[2]));
      }
    }
  } else {
    cout << "Error reading file." << endl;
  }
  infile.close();
  
  // Height
  cout << "Tree height is " << tree.getHeight() << endl << endl;
  
  // Print
  cout << "Printing tree:\n";
  tree.print();
  
  // printCity
  string city;
  cout << "Which city do you want to print? ";
  getline(cin, city);
  tree.printCity(city);
  
  // Remove
  string removeCity;
  cout << "Which city do you want to remove? ";
  getline(cin, removeCity);
  while (!tree.remove(removeCity)){
    cout << removeCity + " wasn't found in tree. Try again: ";
    getline(cin, removeCity);
  }
  cout << removeCity + " has been removed. Printing updated tree:\n";
  tree.print();
  
  // biggestCity
  cout << "The biggest city is " + tree.biggestCity() + "\n";
  
  // Copy Constructor
  CityBST tree2 = tree;
  cout << "Printing tree2, should be identical to tree\n";
  tree2.print();
  
  // Removing root
  tree2.remove("Tokyo");
  tree2.remove("New York");
  tree2.remove("Mexico City");
  cout << "Printing tree2 after removing early entries\n";
  tree2.print();
  
  // Inserting duplicate
  cout << "Inserting second Moscow to tree2\n";
  tree2.insert("Moscow", "", 0);
  tree2.print();
  
  // Copy Assignment
  tree = tree2;
  cout << "Printing tree, should be identical to tree2\n";
  tree.print();
  
  // Emptying tree
  CityBST emptyTree;
  tree = emptyTree;
  cout << "Printing tree, should be empty\n";
  tree.print();
  cout << "Tree height: " << tree. getHeight() << endl;
  
  // Closing
  cout << "Until next time\n";
  return 0;
}