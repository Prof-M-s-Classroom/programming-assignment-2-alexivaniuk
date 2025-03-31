[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Alex Ivaniuk  
### **Student ID:** `132034835`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
    
This project uses a text file to create a text-based RPG where the player decides the path. Each line of the file is stored in a node, and that node is placed in a binary decision tree. The tree is then traversed based on user input, and ends when a leaf node is reached

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `This is the file that runs the code by calling the loadStoryFromFile and playGame methods  
- **`GameDecisionTree.h`** → `this file contains the loadStoryFromFile method, which reads the text file and stores the data in a node, and then constructs the binary tree. It also contains the playGame method, which traverses through the binary tree until a leaf node is found  
- **`Node.h`** → This file contains the Node template class which stores data of type T, which in this case is a Story object  
- **`Story.h`** → this file contains the Story class, which contains a description, an eventNumber, a leftEventNumber, and a rightEventNumber 
- **`story.txt`** → This file contains the story for the game. Each line has an eventNumber, description, leftEventNumber, and rightEventNumber seperated by delimiters. The loadStoryFromFile function reads the file and stores each line in a node 

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?
  - Story objects are created by reading the file using delimeters. A for loop is used that stores the string in its respective spot (eventNumber, description, etc). The string is converted to int through stringstream for eventNumbers
- How are nodes linked based on left and right event numbers?
  - Nodes are linked through the insertNode method. The insertNode method starts at the root and checks the left and right eventNumbers for the target eventNumber. If it finds the target, then the newNode is inserted at that spot.
- What happens if an event has `-1` as left or right children?
  - If an event has -1 as left or right children, then there is no node that can go there. If it is -1 for both left and right, then that node is a leaf node

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken? 
  - User input determines whether the player will go left or right. If the player inputs 1, they will go left. If the player inputs 2, they will go right
- What happens when the player reaches a leaf node?
  - When a player reaches a leaf node, the code stops traversing through the tree and "Congrats, you finished the game!" is printed
- Explain the special case where multiple events lead to the same outcome.
  - There are two cases where you open a chest that is actually a mimic that kills you. There are also two cases where you enter a room with a dragon that kills you

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?
  - The file is read line by line. There is a for loop that reads each line up to the delimeter, which is then stored in the respective Story variable
- How do you ensure nodes are properly linked?
  - The insertNode method starts at the root and checks the right and left event numbers for the target event number, and if it is found then the node is inserted there. If not, the method recursively calls itself for both the left and right node.
- Any challenges faced while handling file input?
  - One challenge that I had was trying to turn the string into an int, which I ended up solving by using a stringstream 

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

The main problem I had was that my file wasn't being open because my ifstream couldn't find the file, which created a sigmentation error when I tried to traverse through a binary tree that didn't exist. The way I fixed it was I ended up having to move the story.txt file to the cmake-build-debug folder, which fixed the problem.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

You are walking in a forest and find a cave. Do you enter (left) or walk past it (right)? Enter 1 to go left or 2 to go right

2

You keep going and find a tunnel in a tree. Do you go through the tunnel (left) or keep going (right)

1

You go in the tunnel and find a chest. Do you open the chest (left) or keep going (right)?

1

You open the chest. You find a huge pile of gold!

Congrats, you finished the game!

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(4N)`
  - This is O(4N) because there is a while loop that runs N times, and in the while loop is a for loop that always runs 4 times
- **Searching for an event in the tree** → `O(N)`
  - Searching for a node in the tree is O(N) because you need to check every node, because it's not like a BST where the left and right child is always less than or greater than the parent node  
- **Game traversal efficiency** → `O(log(n))`
  - This is O(log(n)) because each time you move down a node, you cut down the size in half

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

I tested a case where the user entered something that wasn't 1 or 2 and ensured that the correct statement was printed

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
