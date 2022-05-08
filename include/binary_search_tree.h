#ifndef binary_search_tree_h
#define binary_search_tree_h

#include <stdlib.h>

#include "utils.h"
#include "dy_array.h"

typedef struct bst_node
{
    int data, balance;
    struct bst_node *left, *right;
}bst_node;

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
bst_node* bst_create_node(int node_val);
void bst_add_node(bst_node* root, int item);
int bst_diameter(bst_node* root, int node_small, int node_big);
int bst_height(bst_node* root);

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
//Traversals// // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
void bst_traversal_postorder(bst_node* root, int* data_arr, int* data_idx, int* bal_arr, int* bal_idx);
void bst_traversal_inorder(bst_node* root, int* data_arr, int* data_idx, int* bal_arr, int* bal_idx);
void bst_traversal_preorder(bst_node* root, int* data_arr, int* data_idx, int* bal_arr, int* bal_idx);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// WARNING: "bst_balance_factor" is not compatible with "dy_array" of
// type anything other than "pairs" aka "struct pairs".
void bst_balance_factor(bst_node* root);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //




bst_node* bst_create_node(int node_val)
{
    bst_node* node = (bst_node*)malloc(sizeof(bst_node));
    node->data = node_val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bst_add_node(bst_node* root, int item)
{
    if(root == NULL)
        return;
    bst_node* temp = root;
    while(1)
    {
        if(item <= temp->data)
        {
            if(temp->left == NULL)
                break;
            temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
                break;
            temp = temp->right;
        }
    }
    if(item <= temp->data)
        temp->left = bst_create_node(item);
    else
        temp->right = bst_create_node(item);
}

int bst_diameter(bst_node* root, int node_small, int node_big)
{
    bst_node* temp = root;
    while(1)
    {
        if(node_small <= temp->data && node_big > temp->data)
            break;
        else if(node_small <= temp->data && node_big < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    bst_node* i_small = temp;
    int small_length = 0;
    while(node_small != i_small->data)
    {
        if(node_small <= i_small->data)
            i_small = i_small->left;
        else
            i_small = i_small->right;
        small_length++;
    }
    bst_node* i_large = temp;
    int big_length = 0;
    while(node_big != i_large->data)
    {
        if(node_big <= i_large->data)
            i_large = i_large->left;
        else
            i_large = i_large->right;
        big_length++;
    }
    return small_length + big_length + 1;
}

int bst_count_nodes(bst_node* root)
{
    if(root == NULL)
        return 0;
    return bst_count_nodes(root->left) + bst_count_nodes(root->right) + 1;
}

int bst_height(bst_node* root)
{
    if(root == NULL)
        return -1;
    return max(bst_height(root->left), bst_height(root->right)) + 1;
}

void bst_traversal_preorder(bst_node* root, int* data_arr, int* data_idx, int* bal_arr, int* bal_idx)
{
    if(root == NULL)
        return;
    // The index points to the top element
    data_arr[++(*data_idx)] = root->data;
    bal_arr[++(*bal_idx)] = root->balance;
    
    bst_traversal_preorder(root->left, data_arr, data_idx, bal_arr, bal_idx);
    bst_traversal_preorder(root->right, data_arr, data_idx, bal_arr, bal_idx);
}

void bst_traversal_inorder(bst_node* root, int* data_arr, int* data_idx, int* bal_arr, int* bal_idx)
{
    if(root == NULL)
        return;
    // The index points to the top element
    bst_traversal_preorder(root->left, data_arr, data_idx, bal_arr, bal_idx);
    data_arr[++(*data_idx)] = root->data;
    bal_arr[++(*bal_idx)] = root->balance;
    bst_traversal_preorder(root->right, data_arr, data_idx, bal_arr, bal_idx);
}

void bst_traversal_postorder(bst_node* root, int* data_arr, int* data_idx, int* bal_arr, int* bal_idx)
{
    if(root == NULL)
        return;
    // The index points to the top element
    bst_traversal_preorder(root->left, data_arr, data_idx, bal_arr, bal_idx);
    bst_traversal_preorder(root->right, data_arr, data_idx, bal_arr, bal_idx);
    
    data_arr[++(*data_idx)] = root->data;
    bal_arr[++(*bal_idx)] = root->balance;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //

void bst_balance_factor(bst_node* root)
{
    if(root == NULL)
        return;
    root->balance = bst_height(root->left) - bst_height(root->right);
    bst_balance_factor(root->left);
    bst_balance_factor(root->right);
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //



// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// AVL Trees// // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //

void bst_avl_rotate_left(bst_node* root)
{
    
}

bst_node* bst_to_avl(bst_node* root)
{
    return NULL;
}


#endif //binary_search_tree_h
