#ifndef AVLTREE_H
#define AVLTREE_H

#include <QString>
#include <string>
#include <iostream>
#include <vector>

class AVLtree
{
private:
    struct Node
    {
        Node* left;
        Node* right;
        Node *parent;

        long long key;
        std::string value;

        long long bal;

        explicit Node(long long key, std::string value)
        {
            left = nullptr;
            right = nullptr;
            //parent = nullptr;
            this->key = key;
            this->value = value;
            bal = 0;
        }
        //~Node() {}
    };

    Node* root;

    void deleteTraverse(Node* v)
    {
        if (v == nullptr)
            return;

        deleteTraverse(v->left);
        deleteTraverse(v->right);

        delete v;
    }

    long long findMin (Node *v)
    {
        if (v == nullptr)
            return 0;

        if (v->left != nullptr)
            return findMin(v->left);
        else
            return v->key;
    }
    long long findMax (Node *v)
    {
        if (v == nullptr)
            return 0;

        if (v->right != nullptr)
            return findMin(v->right);
        else
            return v->key;
    }
    Node* findNearest (Node* v, long long key)
    {
        if (v == nullptr)
        {
            std::cout << "Error\n";
            return v;
        }

        if (v->key == key)
        {
            return v;
        }
        else if (key < v->key)
        {
            if (v->left == nullptr) return v;
            else return findNearest(v->left, key);
        }
        else if (v->key < key)
        {
            if (v->right == nullptr) return v;
            else return findNearest(v->right, key);
        }
    }

    Node* doBalance(Node* v)
    {
        if (v == nullptr)
            return v;

        if (v->bal == -2)
        {
            if (v->right != nullptr)
            {
                if (v->right->bal == -1 || v->right->bal == 0)
                {
                    return rotateLeft(v);
                }
                else
                {
                    if (v->right->left != nullptr)
                    {
                        return bigRotateLeft(v);
                    }
                }
            }
        }
        else if (v->bal == 2)
        {
            if (v->left != nullptr)
            {
                if (v->left->bal == 1 || v->left->bal == 0)
                {
                    return rotateRight(v);
                }
                else
                {
                    if (v->left->right != nullptr)
                    {
                        return bigRotateRight(v);
                    }
                }
            }
        }

        return v;
    }
    Node* rotateLeft(Node* v)
    {
        std::cout << v->key << std::endl;
        Node* v1 = v->right;
        v->right = v1->left;
        v1->left = v;
        return v1;
    }
    Node* rotateRight(Node* v)
    {
        Node* v1 = v->left;
        v->left = v1->right;
        v1->right = v;
        return v1;
    }
    Node* bigRotateLeft(Node* v)
    {
        v->right = rotateRight(v->right);
        v = rotateLeft(v);
        return v;
    }
    Node* bigRotateRight(Node* v)
    {
        v->left = rotateLeft(v->left);
        v = rotateRight(v);
        return v;
    }

    Node* findNode (Node* v, long long key)
    {
        if (v == nullptr)
        {
            std::cout << "Not found\n";
            return v;
        }

        if (v->key == key)
        {
            std::cout << v->key << " " << v->value << "\n";
            return v;
        }
        else if (key < v->key)
        {
            return findNode(v->left, key);
        }
        else if (v->key < key)
        {
            return findNode(v->right, key);
        }
    }

    Node* insertNode(Node *v, long long key, std::string value) //mnogo doBalance
    {
        if (v == nullptr)
        {
            v = new Node(key, value);
            return v;
        }

        if (v->key == key)
        {
            v->value = value;
            return v;
        }
        else if (key < v->key)
        {
            v->left = insertNode(v->left, key, value);
            v->bal++;
        }
        else if (v->key < key)
        {
            v->right = insertNode(v->right, key, value);
            v->bal--;
        }

        if (v == root)
            root = v = doBalance(v);
        else
            v = doBalance(v);
        //if (bal == 0) ...
        return v;
    }

    Node* deleteNode(Node *v, long long key) //change root
    {
        if (v == nullptr)
        {
            return v;
        }

        if (v->key == key)
        {
            if (v->left != nullptr && v->right != nullptr)
            {
                v->key = findMin(v->right);
                v->right = deleteNode(v->right, key);
                v->bal++;
            }
            else if (v->left != nullptr)
            {
                v = v->left;
            }
            else if (v->right != nullptr)
            {
                v = v->right;
            }
            else
            {
                delete v;
                v = nullptr;
            }

            return v;
        }
        else if (key < v->key)
        {
            v->left = deleteNode(v->left, key);
            v->bal--;
        }
        else if (v->key < key)
        {
            v->right = deleteNode(v->right, key);
            v->bal++;
        }

        if (v == root)
            root = v = doBalance(v);
        else
            v = doBalance(v);
        //if (v == +-1) ...
        return v;
    }

    void preTraverse(Node* v, std::vector <std::pair <long long, std::string> > &res)
    {
        if (v == nullptr)
            return;

        std::cout << v->key << " " << v->value << std::endl;
        res.push_back({v->key, v->value});
        preTraverse(v->left, res);
        preTraverse(v->right, res);
    }
    void postTraverse(Node* v, std::vector <std::pair <long long, std::string> > &res)
    {
        if (v == nullptr)
            return;

        postTraverse(v->left, res);
        postTraverse(v->right, res);
        std::cout << v->key << " " << v->value << "\n";
        res.push_back({v->key, v->value});
    }
    void inTraverse(Node* v, std::vector <std::pair <long long, std::string> > &res)
    {
        if (v == nullptr)
            return;

        inTraverse(v->left, res);
        std::cout << v->key << " " << v->value << "\n";
        res.push_back({v->key, v->value});
        inTraverse(v->right, res);
    }

public:
    AVLtree()
    {
        root = nullptr;
    }
    ~AVLtree()
    {
        deleteTraverse(root);
    }

    void preTraverse(std::vector <std::pair <long long, std::string> > &v)
    {
        preTraverse(root, v);
    }
    void postTraverse(std::vector <std::pair <long long, std::string> > &v)
    {
        postTraverse(root, v);
    }
    void inTraverse(std::vector <std::pair <long long, std::string> > &v)
    {
        inTraverse(root, v);
    }

    std::string find (long long key)
    {
        Node *res = findNode(root, key);
        if (res == nullptr)
            return "Not found";
        else
            return res->value;
    }
    std::string findNearestMinMax ()
    {
        long long key = (findMin(root) + findMax(root)) / 2;
        std::cout << key << " hey ";
        Node *res = findNearest(root, key);

        if (res == nullptr)
            return "Empty tree";
        else
            return res->value;
    }

    void insert(long long key, std::string value) //mnogo doBalance && check root
    {
        if (root == nullptr)
            root = insertNode(root, key, value);
        else
            insertNode(root, key, value);
    }

    void del(long long key) //change root
    {
        if (findNode(root, key) == nullptr)
            return;

        if (root->key == key)
            root = deleteNode(root, key);
        else
            deleteNode(root, key);
    }
};

#endif // AVLTREE_H
