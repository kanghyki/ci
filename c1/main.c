#include "double_linked_list.h"

int	main(void)
{
	t_node	*head;
	t_node	*node_to_remove;

	head = (0);
	append_node(&head, 10);
	append_node(&head, 20);
	node_to_remove = append_node(&head, 30);
	append_node(&head, 40);
	remove_node(&head, node_to_remove);
	print_list(head);
	system("leaks -q a.out");
	return (0);
}
