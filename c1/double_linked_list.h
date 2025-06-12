#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*create_node(int data);
t_node	*append_node(t_node **head, int data);
void	remove_node(t_node **head, t_node *node_to_remove);
void	free_list(t_node **head);
void	print_list(t_node *head);

#endif
