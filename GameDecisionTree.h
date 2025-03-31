#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        string str;
        ifstream myReadFile(filename);
        root = nullptr;
        //myReadFile.open(filename);
        if (!myReadFile.is_open()) {
            std::cerr << "Could not open file " << filename <<  strerror(errno) << std::endl;

            return;
        }
        while (getline(myReadFile, str, delimiter)) {
            Story *story = new Story();
            for (int i = 0; i < 4; i++) {
                switch (i) {
                    case 0: {
                        //getline(myReadFile, str, delimiter);
                        stringstream s1(str);
                        s1 >> story->eventNumber;
                        break;
                    }
                    case 1: {
                        getline(myReadFile, str, delimiter);
                        story->description = str;
                        break;
                    }
                    case 2: {
                        getline(myReadFile, str, delimiter);
                        stringstream s2(str);
                        s2 >> story->leftEventNumber;
                        break;
                    }
                    case 3: {
                        getline(myReadFile, str);
                        stringstream s3(str);
                        s3 >> story->rightEventNumber;
                        break;
                    }
                }
            }
            if (story->eventNumber == 1) {
                root = new Node<Story*>(story);
            }
            else {
                Node<Story*>* newNode = new Node<Story*>(story);
                insertNode(root, story->eventNumber, newNode);
            }
        }
    }

    void insertNode(Node<Story*>* node, int targetEventNumber, Node<Story*>* newNode) {
        if (node == nullptr) {
            return;
        }
        if (node->data->leftEventNumber == targetEventNumber) {
            node->left = newNode;
        }
        if (node->data->rightEventNumber == targetEventNumber) {
            node->right = newNode;
        }
        else if (node->right == nullptr && node->left == nullptr) {
            return;
        }
        insertNode(node->left, targetEventNumber, newNode);
        insertNode(node->right, targetEventNumber, newNode);
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        int eventLeft = root->data->leftEventNumber;
        int eventRight = root->data->rightEventNumber;
        Node<Story*>* temp = root;
        int choice;
        while (temp->left != nullptr && temp->right != nullptr) {
            cout << temp->data->description + "Enter 1 to go left or 2 to go right"<< endl;
            cin >> choice;
            if (choice == 1) {
                temp = temp->left;
                eventLeft = temp->data->leftEventNumber;
                eventRight = temp->data->rightEventNumber;
                if (eventLeft == eventRight) {
                    cout << temp->data->description << endl;
                }
            }
            else if (choice == 2) {
                temp = temp->right;
                eventLeft = temp->data->leftEventNumber;
                eventRight = temp->data->rightEventNumber;
                if (eventLeft == eventRight) {
                    cout << temp->data->description << endl;
                }
            }
            else {
                cout << "Invalid Input" << endl;
            }
        }
        cout << "Congrats, you finished the game!" << endl;
    }
};

#endif // GAMEDECISIONTREE_H