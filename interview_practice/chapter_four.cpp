#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <chrono>

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int data_)
    :left(NULL), right(NULL), data(data_) 
    {}

};

int find_height(Node* root, bool& is_balanced) {
    int left_height= 0;
    int right_height= 0;

    // Find height of left subtree
    if(root->left!=NULL){
        left_height= find_height(root->left, is_balanced);
    }

    if(root->right!=NULL){ 
        right_height= find_height(root->right, is_balanced);
    }


    int the_height= std::max<int>(left_height, right_height)+1;
    is_balanced= (std::abs(left_height-right_height) <=1);

    return the_height;
}


int check_balanced() {
    Node* root= new Node(1);
    root->right= new Node(1);
    root->left= new Node(1);
    root->right->right= new Node(1);
    //root->right->right->right= new Node(1);

    bool is_balanced= false;
    int the_height= find_height(root, is_balanced);
    std::cout << "The height: " << the_height 
              << " is balanced: " << is_balanced << std::endl;

    return 0;
}

//// right limit is not inclusive
Node* build_search_tree(std::vector<int>& v, int left_limit, int right_limit) {
    /// right_limit is not inclusive
    std::cout << "Sizes are: " << left_limit << " " << right_limit << std::endl;
    if(right_limit-left_limit == 0) {
        return NULL; //new Node(v[left_limit]);
    }

    int len=right_limit- left_limit;
    int mid= len/2 + left_limit;

    //// Assing the value of the root of the tree
    Node* root= new Node(v[mid]);

    /// Recurse to the left (right limit is not inclusive)
    root->left= build_search_tree(v, left_limit, mid);

    //// Recurse to the right
    root->right= build_search_tree(v, mid+1, right_limit);


    return root;
}


void print_binary_search_tree(Node * root) {
    //// Empty tree
    if(root==NULL) {
        return;
    }

    //// Print the left side of the tree
    print_binary_search_tree(root->left);

    //// Print the value of the node
    std::cout << root->data <<" ";

    //// Print the right side of the tree
    print_binary_search_tree(root->right);

}

//// 
int main() {
    std::vector<int> numbers(100);

    for(size_t i=0; i<100; i++) {
        numbers[i]= i;
    }

    std::cout << "Creating search tree" << std::endl;
    Node* root= build_search_tree(numbers, 0, 100);

    std::cout << "This is your tree" << std::endl;
    print_binary_search_tree(root);

    return 0;
}






