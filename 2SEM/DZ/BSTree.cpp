#include <iostream>
#include <fstream>
#include <vector>
#include <initializer_list>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent; // опционально, указатель на предыдущий элемент

    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BSTree {
private:
    Node* root;

    Node* find_min(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = find_min(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    void inorder_print(Node* node) {
        if (node != nullptr) {
            inorder_print(node->left);
            std::cout << node->data << " ";
            inorder_print(node->right);
        }
    }

    void delete_tree(Node* node) {
        if (node != nullptr) {
            delete_tree(node->left);
            delete_tree(node->right);
            delete node;
        }
    }

public:
    BSTree() : root(nullptr) {}

    BSTree(std::initializer_list<int> list) : root(nullptr) {
        for (int value : list) {
            add_element(value);
        }
    }

    bool add_element(int value) {
        Node* new_node = new Node(value);
        if (root == nullptr) {
            root = new_node;
            return true;
        }

        Node* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = new_node;
                    new_node->parent = current;
                    return true;
                }
                current = current->left;
            } else if (value > current->data) {
                if (current->right == nullptr) {
                    current->right = new_node;
                    new_node->parent = current;
                    return true;
                }
                current = current->right;
            } else {
                delete new_node;
                return false; // элемент уже существует
            }
        }
    }

    bool delete_element(int value) {
        root = remove(root, value);
        return true;
    }

    bool find_element(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value < current->data) {
                current = current->left;
            } else if (value > current->data) {
                current = current->right;
            } else {
                return true;
            }
        }
        return false;
    }

    void print() {
        inorder_print(root);
        std::cout << std::endl;
    }

    bool save_to_file(const std::string& path) {
        std::ofstream file(path);
        if (!file.is_open()) return false;

        std::vector<Node*> nodes;
        std::vector<Node*> next_level_nodes;
        nodes.push_back(root);

        while (!nodes.empty()) {
            for (Node* node : nodes) {
                if (node != nullptr) {
                    file << node->data << " ";
                    next_level_nodes.push_back(node->left);
                    next_level_nodes.push_back(node->right);
                } else {
                    file << "null ";
                }
            }
            nodes.swap(next_level_nodes);
            next_level_nodes.clear();
        }

        file.close();
        return true;
    }

    bool load_from_file(const std::string& path) {
        std::ifstream file(path);
        if (!file.is_open()) return false;

        std::vector<int> values;
        int value;
        while (file >> value) {
            values.push_back(value);
        }

        delete_tree(root);
        root = nullptr;

        for (int val : values) {
            add_element(val);
        }

        file.close();
        return true;
    }

    ~BSTree() {
        delete_tree(root);
    }
};