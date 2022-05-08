#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"
#include "graph.h"
#include "stack.h"
#include "dept_search.h"
#include "binary_search_tree.h"
#include "sorting.h"

#include "ameth_array.h"
#include "problems.h"
#include "ppm_img.h"
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
list_graph* a_graph(void);
list_graph* random_graph(int size);
bst_node* a_bst(void);
int* random_array(int size)
{
    srand((unsigned int)time(0));
    int* rarr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
    {
        rarr[i] = (rand()*100000000)%1000;
    }
    return rarr;
}

int* descending_array(int size)
{
    int* rarr = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
    {
        rarr[i] = size - i;
    }
    return rarr;
}
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //




int main()
{
    bst_node* graph = a_bst();
    bst_balance_factor(graph);
    
    int gr_count = bst_count_nodes(graph);
    
    int* dat = (int*)malloc(sizeof(int) * gr_count);
    int* bal = (int*)malloc(sizeof(int) * gr_count);
    int* d_idx = (int*)malloc(sizeof(int));
    int* b_idx = (int*)malloc(sizeof(int));
    *d_idx = -1;
    *b_idx = -1;
    
    bst_traversal_preorder(graph, dat, d_idx, bal, b_idx);
    
    for(int i = 0; i < gr_count; i++)
        printf("%d : %d\n", dat[i], bal[i]);
    
    return 0;
}

// printf("%d\n",bst_count_nodes(a_bst()));

/*
 int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
 merge_sort(&(array[0]), 0, 9);
 for(int i = 0; i < 10; i++)
     printf("%d ", array[i]);
 */


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //

void test()
{
    list_graph* graph = a_graph();
    stack* stack = create_stack(graph->n_present);
    reducible_dfs(graph, 0, stack);
    int temp = stack->top+1;
    for(int i = 0; i < temp; i++)
        printf("%d ", pop(stack));
    printf("\n");
}

bst_node* a_bst()
{
    bst_node* root = bst_create_node(30);
    bst_add_node(root, 10);
    bst_add_node(root, 5);
    bst_add_node(root, 2);
    bst_add_node(root, 7);
    bst_add_node(root, 6);
    bst_add_node(root, 8);// this
    
    bst_add_node(root, 11);
    bst_add_node(root, 13);
    bst_add_node(root, 17);
    bst_add_node(root, 15);
    bst_add_node(root, 14);// this
    bst_add_node(root, 16);
    bst_add_node(root, 19);
    
    return root;
}

list_graph* a_graph()
{
    srand((unsigned int)time(0));
    int num = 5;
    list_graph* graph = list_create_graph(num);
    for(int i = 0; i < num; i++)
        list_add_node(graph, rand()%10);
    list_add_edge(graph, 0, 1);
    list_add_edge(graph, 0, 2);
    list_add_edge(graph, 1, 3);
    list_add_edge(graph, 2, 3);
    list_add_edge(graph, 2, 4);
    list_add_edge(graph, 4, 3);
    return graph;
}

list_graph* random_graph(int size)
{
    int node_val, from, to;
    list_graph* graph = list_create_graph(size);
    for(int i = 0; i < size; i++)
    {

        printf("Enter a node at %d :", graph->n_present);
        scanf("%d", &node_val);
        list_add_node(graph, node_val);
    }
    while(true)
    {
        printf("Enter values to create an edge for [from to] (enter -1 -1 to exit): \n");
        scanf("%d %d", &from, &to);
        if(from == -1)
            break;
        list_add_edge(graph, from, to);
    }
    return graph;
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //