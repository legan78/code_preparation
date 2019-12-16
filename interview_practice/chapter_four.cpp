#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <chrono>
#include <queue>
#include <list>

typedef std::vector<std::vector<int> > adjacency_list;
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
    // std::cout << "Sizes are: " << left_limit << " " << right_limit << std::endl;
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
int search_tree() {
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



void DFS(const adjacency_list& the_graph, 
         int start_node, 
         std::vector<bool>& explored) {
    std::vector<int> children= the_graph[start_node];

    //// mark starting node as explored
    explored[start_node]= true;

    //// iterate over all edges from given graph
    for(size_t i=0; i<children.size(); i++) {
        //// skip open node if already explored
        int child_idx= children[i];
        if(explored[child_idx]) continue;

        //// recursive calls 
        DFS(the_graph, children[i], explored);
    }

}


void BFS(const adjacency_list& the_graph,
         int start_node,
         std::vector<bool>& explored) {

    std::queue<int, std::list<int> > Q;

    //// Initialize queue
    Q.push(start_node);
    explored[start_node]= true;

    while(!Q.empty()) {
        int node_idx= Q.front();
        std::vector<int> children= the_graph[node_idx];

        //// remove fist element in the list
        Q.pop();

        //// here open all the nodes
        for(size_t i=0; i<children.size(); i++) {
            int child_idx= children[i];

            //// if not explored then explore
            if(!explored[child_idx]) {
                Q.push(child_idx);
                explored[child_idx]= true;
            }
        }
    }
}


////
int is_path_between() {

    int n_nodes= 7;

    adjacency_list the_graph(n_nodes);

    //// Node A
    the_graph[0].push_back(1);
    /// Node B
    the_graph[1].push_back(2);
    the_graph[1].push_back(3);
    the_graph[1].push_back(4);
    /// Node C
    the_graph[2].push_back(4);
    /// Node D
    the_graph[3].push_back(4);
    /// Node E
    the_graph[4].push_back(5);
    /// Node F
    /// Node G
    the_graph[6].push_back(3);

    int start_node= 0;
    std::vector<bool> explored(n_nodes, false);
    // DFS(the_graph, start_node, explored);
    BFS(the_graph, start_node, explored);

    for(size_t i=0; i<n_nodes; i++) {
        std::cout << explored[i] << " ";
    }
    std::cout<<std::endl;

    return 0;
}


//// asume graph adjacency list is allocated
void create_adjacency_list_tree(Node* root, adjacency_list& graph) {
    if(root==NULL) return;

    int node_idx= root->data;
    if(root->left)
        graph[node_idx].push_back(root->left->data);
    if(root->right)
        graph[node_idx].push_back(root->right->data);

    create_adjacency_list_tree(root->left, graph);
    create_adjacency_list_tree(root->right, graph);
}


int main() {

    //// Build binary search tree
    int n_nodes=100;
    std::vector<int> numbers(n_nodes);
    for(size_t i=0; i<n_nodes; i++) {
        numbers[i]= i;
    }

    std::cout << "Creating search tree" << std::endl;
    Node* root= build_search_tree(numbers, 0, n_nodes);

    bool is_balanced= false;
    int the_height= find_height(root, is_balanced);
    std::cout << "The height: " << the_height 
              << " is balanced: " << is_balanced << std::endl;


    std::queue<Node*, std::list<Node*> >  Q;
    Q.push(root);

    std::vector<std::vector<Node*> > lists;
    int n_allowed= 1;
    std::vector<Node*> aux;

    while(!Q.empty()) {
        Node* node= Q.front();

        //// 
        if(node->left!=NULL)
            Q.push(node->left);
        if(node->right!=NULL)
            Q.push(node->right);

        //// Remove node
        Q.pop();

        //// push in auxiliar list
        if(aux.size()<n_allowed)
            aux.push_back(node);
        else {
            lists.push_back(aux);
            aux= std::vector<Node*>();
            n_allowed*=2;
        }
    }

    std::cout<< "The number of lists is: " << lists.size() << std::endl;
    for(size_t i=0; i< lists.size(); i++) {
        std::vector<Node*> level= lists[i];

        std::cout << level[0]->data;
        for(size_t j=1; j< level.size(); j++) 
            std::cout << "->" << level[j]->data;
        std::cout << std::endl;
    }



    return 0;
}






