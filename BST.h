#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <queue>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
    Node<T> *_root;         // Root of the tree nodes

    /* Add new T val to the tree */
    void addHelper(Node<T> *root, T val) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node<T>(val);
            } else {
                addHelper(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new Node<T>(val);
            } else {
                addHelper(root->right, val);
            }
        }
    }

    /* Print tree out in inorder (A + B) */
    void printInOrderHelper(Node<T> *root) {
        if (!root) return;
        printInOrderHelper(root->left);
        cout << root->value << ' ';
        printInOrderHelper(root->right);
    }

    /* Return number of nodes in tree */
    int nodesCountHelper(Node<T> *root) {
        if (!root) {
            return 0;
        } else {
            return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
        }
    }

    /* Return height of tree (root == nullptr -> 0) */
    int heightHelper(Node<T> *root) {
        if (!root) {
            return -1;
        } else {
            return 1 + max(heightHelper(root->left), heightHelper(root->right));
        }
    }

    /* Delete a given <T> value from tree */
    bool deleteValueHelper(Node<T> *parent, Node<T> *current, T value) {
        if (!current) return false;
        if (current->value == value) {
            if (current->left == nullptr || current->right == nullptr) {
                Node<T> *temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                } else {
                    this->_root = temp;
                }
            } else {
                Node<T> *validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                T temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

    /********************************* PUBLIC API *****************************/
public:

    BST() : _root(nullptr) {}               // Basic initialization constructor

    /**
     * Destructor - Needs to free *all* nodes in the tree
     * knock the tree down by deleting the root
     * this isnt minecraft, there are no floating trees.
     */
    ~BST() {
        delete _root;
    }

    /* Public API */
    void add(T val) {
        if (this->_root) {
            this->addHelper(this->_root, val);
        } else {
            this->_root = new Node<T>(val);
        }
    }

    void print() {
        printInOrderHelper(this->_root);
    }

    /**
     * Print the nodes level by level, starting from the root
     */
    void printLevelOrder() {

        // Base Case
        if (_root == NULL) return;

        // queue initialization type: integer Node
        queue<Node<int> *> q;

        // push the root to the tree
        q.push(_root);

        while (!q.empty()) {

            int count = q.size();
            while (count > 0) {

                // set current node to front of queue
                Node<int> *current = q.front();

                // print current node
                cout << current->value << " ";

                // remove current node from queue
                q.pop();

                // push left branch
                if (current->left != NULL)
                    q.push(current->left);

                // push right branch
                if (current->right != NULL)
                    q.push(current->right);

                count--;
            }
            // next level of tree
            cout << endl;
        }
    }

    int nodesCount() {
        return nodesCountHelper(this->_root);
    }

    int height() {
        return heightHelper(this->_root);
    }

    /**
     * Print the maximum path in this tree
     * TODO: Implement printMaxPath
     */
    void printMaxPath() {
        printMaxPathHelper(this->_root);
    }

    void printMaxPathHelper(Node<T> *_root) {
        if (!_root)
            return;

        // print value
        cout << _root->value << " ";

        // use height helper to determine which branch is longer
        if (heightHelper(_root->left) > heightHelper(_root->right)) {
            // recursive call
            printMaxPathHelper(_root->left);
        } else {
            printMaxPathHelper(_root->right);
        }
    }

    bool deleteValue(T value) {
        return this->deleteValueHelper(nullptr, this->_root, value);
    }

    /**
     * Find if the BST contains the value
     */

    // implementation of contains function
    bool containsHelper(Node<T> *_root, T value){

        // if root is empty... false
        if (!_root)
            return false;

        // if root contains value... true
        if (value == _root->value)
            return true;
        // if value is less than root... move branch to left and run again
        else if (value < _root->value)
            return containsHelper(_root->left, value);
        // if value is greater than root... move to right and run again
        else if (value > _root->value)
            return containsHelper(_root->right, value);
    }

    // recursive function ot find value in BST
    bool contains(T value) {
        return containsHelper(this->_root, value);
    }
};

#endif

