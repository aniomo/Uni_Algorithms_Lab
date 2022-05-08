#ifndef graph_h
#define graph_h

#include <stdlib.h>

#include "stack.h"

typedef struct g_node
{
	int index;
	int value;
	struct g_node* next;
}g_node;

typedef struct list_graph
{
	int n_present, n_node;
	int* visited;
	g_node** array;
}list_graph;


typedef struct mat_graph
{
    int n_present,n_nodes;
    int* nodes_vals;
    int** array;
}mat_graph;


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
g_node* create_node(int value, int index);
list_graph* list_create_graph(int num);
void list_add_node(list_graph* graph, int node_val);
void list_add_edge(list_graph* graph, int from, int to);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// ADJACENCY MATRIX
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
mat_graph* mat_create_graph(int num);
void mat_add_node(mat_graph* graph, int node_val);
void mat_add_edge(mat_graph* graph, int from, int to);


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// GRAPH TYPE CONVERSION
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
mat_graph* list_to_mat(list_graph* l_graph);
list_graph* mat_to_list(mat_graph* m_graph);


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
//  GRAPH OPERATIONS
// // // // // // // // // // // // // // // // // // // // // // // // // // // //




// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
//  DEFINITIONS
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
mat_graph* mat_create_graph(int num)
{
    mat_graph* newGraph = (mat_graph*)malloc(sizeof(mat_graph));
    newGraph->n_present = 0;
    newGraph->n_nodes = num;
    newGraph->nodes_vals = (int*)malloc(sizeof(int) * num);
    newGraph->array = (int**)malloc(sizeof(int*) * num);
    for(int i = 0; i < num; i++)
    {
        newGraph->array[i] = (int*)malloc(sizeof(int) * num);
        for(int j = 0; j < num; j++)
            newGraph->array[i][j] = 0;
    }
    return newGraph;
}

void mat_add_node(mat_graph* graph, int node_val)
{
    if(graph == NULL || graph->n_present == graph->n_nodes)
        return;
    graph->nodes_vals[graph->n_present++] = node_val;
}

void mat_add_edge(mat_graph* graph, int from, int to)
{
    if(graph == NULL || from >= graph->n_nodes || to >= graph->n_nodes)
        return;
    graph->array[from][to] = 1;
}


mat_graph* list_to_mat(list_graph* l_graph)
{
    mat_graph* m_graph = mat_create_graph(l_graph->n_present);
    for(int i = 0; i < l_graph->n_present; i++)
    {
        g_node* temp = l_graph->array[i];
        mat_add_node(m_graph, temp->value);
        temp = temp->next;
        while(temp != NULL)
        {
            mat_add_edge(m_graph, i, temp->index);
            temp = temp->next;
        }
    }
    return m_graph;
}

list_graph* mat_to_list(mat_graph* m_graph)
{
    list_graph* l_graph = list_create_graph(m_graph->n_present);
    
    for(int i = 0; i < m_graph->n_present; i++)
        list_add_node(l_graph, m_graph->nodes_vals[i]);
    
    for(int i = 0; i < m_graph->n_present; i++)
        for(int j = 0; j < m_graph->n_present; j++)
            if(m_graph->array[i][j] == 1)
                list_add_edge(l_graph, i, j);
    
    return l_graph;
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// ADJACENCY LIST
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
g_node* create_node(int value, int index)
{
	g_node* newNode = (g_node*)malloc(sizeof(g_node));
	newNode->index = index;
	newNode-> value = value;
	newNode->next = NULL;
	return newNode;
}

list_graph* list_create_graph(int num)
{
	list_graph* graph = (list_graph*)malloc(sizeof(list_graph));
	graph->n_node = num;
	graph->n_present = 0;
	graph->visited = (int*)malloc(sizeof(int) * num);
	for(int i = 0; i < graph->n_node; i++)
		graph->visited[i] = 0;
	graph->array = (g_node**)malloc(sizeof(g_node*) * num);
	return graph;
}

void list_add_node(list_graph* graph, int node_val)
{
	if(graph == NULL || graph->n_present == graph->n_node)
		return;
	graph->array[graph->n_present] = create_node(node_val, graph->n_present);
	graph->n_present++;
}

void list_add_edge(list_graph* graph, int from, int to)
{
	if(graph == NULL || from >= graph->n_present || to >= graph->n_present)
		return;
    g_node* t_node = graph->array[from];
    while(t_node->next != NULL)
        t_node = t_node->next;
    t_node->next = create_node(graph->array[to]->value, to);
}

#endif //graph_h
