#include "double_linked_list.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*append_node(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(data);
	if (!new_node)
		return (NULL);
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return (new_node);
}

void	remove_node(t_node **head, t_node *node_to_remove)
{
	if (*head == NULL || node_to_remove == NULL)
		return ;
	if (*head == node_to_remove)
		*head = node_to_remove->next;
	if (node_to_remove->next != NULL)
		node_to_remove->next->prev = node_to_remove->prev;
	if (node_to_remove->prev != NULL)
		node_to_remove->prev->next = node_to_remove->next;
	free(node_to_remove);
}

void	free_list(t_node **head)
{
	t_node	*current;
	t_node	*next_node;

	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL;
}

void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
