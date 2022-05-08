
#ifndef dept_search_h
#define dept_search_h

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "stack.h"


int next_unvisited(list_graph* graph, int index);
void depth_first_search(list_graph* graph, int s_index, stack* g_stack, stack* pop_order);

stack* src_topo_sort(mat_graph* graph, int s_index);
stack* dept_topo_sort(list_graph* graph, int s_index);

void reducible_dfs(list_graph* graph, int s_index, stack* stack)
{
    graph->visited[s_index] = 1;
    push(stack, s_index);
    g_node* itr = graph->array[s_index]->next;
    while(itr != NULL)
    {
        if(graph->visited[itr->index] == 0)
            reducible_dfs(graph, itr->index, stack);
        itr = itr->next;
    }
}

void depth_first_search(list_graph* graph, int s_index, stack* g_stack, stack* pop_order)
{
	if(graph->n_present != graph->n_node)
	{
		printf("ERROR_DEPT_FIRST_SEARCH : GRAPH_INCOMPLETE");
		return;
	}
	//push(g_stack, graph->array[s_index]->value);
    push(g_stack, s_index);
	graph->visited[s_index] = 1;
	//printf("%d ", peek(g_stack));

	g_node* y_node = graph->array[s_index];
    
	while(y_node != NULL)
	{
		if(y_node->next == NULL)
        {
            if(next_unvisited(graph, y_node->index) != -1)
                depth_first_search(graph, y_node->index, g_stack, pop_order);
            push(pop_order, pop(g_stack));
        }
		else if(next_unvisited(graph, y_node->index) != -1)
			depth_first_search(graph, next_unvisited(graph, y_node->index), g_stack, pop_order);
		y_node = y_node->next;
	}
}

int next_unvisited(list_graph* graph, int index)
{
    g_node* temp = graph->array[index]->next;
    while(temp != NULL)
    {
        if(graph->visited[temp->index] == 0)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
//  GRAPH OPERATIONS
// // // // // // // // // // // // // // // // // // // // // // // // // // // //


stack* dept_topo_sort(list_graph* graph, int s_index)
{
    stack* g_stack = create_stack(graph->n_present);
    stack* g_pop_order = create_stack(graph->n_present);

    depth_first_search(graph, s_index, g_stack, g_pop_order);

    free_stack(g_stack);

    reverse_array(g_pop_order->array, graph->n_present);
    return g_pop_order;
}

stack* src_topo_sort(mat_graph* graph, int s_index)
{
    stack* topo_sort = create_stack(graph->n_present);
    
    while(1)
    {
        if(topo_sort->top+1 == graph->n_present)
            break;
        int indegree = 0;
        for(int i = 0; i < graph->n_present; i++)
        {
            if(is_in(topo_sort, i) != -1)
                continue;
            
            indegree = 0;
            for(int j = 0; j < graph->n_present; j++)
            {
                //printf("%d ", graph->array[j][i]);
                if(graph->array[j][i] == 1)
                    indegree++;
            }
                
            if(indegree == 0)
            {
                push(topo_sort, i);
                for(int j = 0; j < graph->n_present; j++)
                    graph->array[i][j] = 0;
            }
        }
    }
    return topo_sort;
}


#endif //dept_search_h
