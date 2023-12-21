#include <iostream>
#include <vector>
using namespace std;

struct tree {
    int value;
    tree *left;
    tree *right;
};

int rec(tree* root, int &result) {
    if (root == NULL) {
        return 0;
    }

    int left_subtree = rec(root->left, result);
    int right_subtree = rec(root->right, result);

    int max_root_sum = max(max(left_subtree, right_subtree) + root->value, root->value);
    int max_path_temp_sum = max(max_root_sum, left_subtree + right_subtree + root->value);

    result = max(result, max_path_temp_sum);

    return max_root_sum;
}

int max_path_sum(tree* root) {
    int result = root->value;
    rec(root, result);
    return result;
}

tree* new_tree(int val) {
    tree* root = (tree*)malloc(sizeof(tree));
    root->value = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

tree* rec_arr_to_tree(vector<int> arr, int i) {
    tree *root = NULL;
    if (i < arr.size()) {
        root = new_tree(arr[i]);
        root->left = rec_arr_to_tree(arr, 2 * i + 1);
        root->right = rec_arr_to_tree(arr, 2 * i + 2);
    }
    return root;
}

void print_tree(tree* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    cout << root->value << " ";
    print_tree(root->right);
}


int main() {
    vector<int> arr = {-10, 9, 20, 0, 0, 15, 7};
    tree* root = rec_arr_to_tree(arr, 0);
    
    print_tree(root);
    cout << "\n" << max_path_sum(root) << "\n";

    return 0;
}