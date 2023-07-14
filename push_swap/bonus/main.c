#include "get_next_line.h"
# include "../libft/libft.h"
// #include <stdio.h>

// static void	ft_allocate(char **tab, char const *s, char sep)
// {
// 	char		**tab_p;
// 	char const	*tmp;

// 	tmp = s;
// 	tab_p = tab;
// 	while (*tmp)
// 	{
// 		while (*s == sep)
// 			++s;
// 		tmp = s;
// 		while (*tmp && *tmp != sep)
// 			++tmp;
// 		if (*tmp == sep || tmp > s)
// 		{
// 			*tab_p = ft_substr(s, 0, tmp - s);
// 			s = tmp;
// 			++tab_p;
// 		}
// 	}
// 	*tab_p = NULL;
// }

// static int	ft_count_words(char const *s, char sep)
// {
// 	int	word_count;

// 	word_count = 0;
// 	while (*s)
// 	{
// 		while (*s == sep)
// 			++s;
// 		if (*s)
// 			++word_count;
// 		while (*s && *s != sep)
// 			++s;
// 	}
// 	return (word_count);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**new;
// 	int		size;

// 	if (!s)
// 		return (NULL);
// 	size = ft_count_words(s, c);
// 	new = (char **)malloc(sizeof(char *) * (size + 1));
// 	if (!new)
// 		return (NULL);
// 	ft_allocate(new, s, c);
// 	return (new);
// }

void	free_chars(char **head)
{
	char	**current;

	current = head;
	while (*current != NULL)
	{
		free(*current);
		++current;
	}
	free(head);
}

void	update_index(t_node **head)
{
	t_node	*current;
	int		i;

	i = 0;
	current = *head;
	while (current != NULL)
	{
		current->index = i++;
		current = current->next;
	}
}

void	is_dulicate(t_node **head)
{
	t_node	*dup_head;
	t_node	*dup2_head;
	t_node	*value;

	update_index(head);
	dup_head = *head;
	dup2_head = *head;
	while (dup_head)
	{
		value = dup_head->next;
		dup2_head = *head;
		while (dup2_head)
		{
			if (value->index == dup2_head->index)
				dup2_head = dup2_head->next;
			if (dup2_head && value->data == dup2_head->data)
			{
				free_linked_list(*head);
				// write(2, "found duplicate\n", 16);
				quit();
			}
			if (dup2_head)
				dup2_head = dup2_head->next;
		}
		dup_head = dup_head->next;
	}
}

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_isnum(char *data)
{
	int	flag;

	flag = 0;
	while (*data)
	{
		if (!(*data >= '0' && *data <= '9') && (*data != '-' && *data != '+'))
			return (-1);
		if (*data == '-' || *data == '+')
			flag++;
		++data;
	}
	if (flag > 1)
		return (-1);
	return (0);
}

void	check_if_correct_input(char **values)
{
	while (*values)
	{
		if (ft_strlen(*values) == 1
			&& (*values[0] == '-' || *values[0] == '+'))
			quit();
		if (ft_isnum(*values) == -1)
			quit();
		++values;
	}
}

void	free_linked_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

static int	add(t_node *head, int value)
{
	t_node	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_node));
	if (!current)
		return (1);
	current->next->data = value;
	current->next->next = NULL;
	return (0);
}

void	quit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_and_quit(t_node **head)
{
	free_linked_list(*head);
	quit();
}

long	make_and_return_length(t_node **head, char **value)
{
	t_node	*latest_node;
	t_node	*prev_node;
	int		length;

	length = 0;
	latest_node = *head;
	while (++value != NULL && *value != NULL)
	{
		if (add(latest_node, atoi(*value)) == 1)
			free_and_quit(head);
		if (latest_node->data < -2147483648 || latest_node->data > 2147483647)
			free_and_quit(head);
		prev_node = latest_node;
		latest_node = latest_node->next;
		latest_node->prev = prev_node;
		length++;
	}
	return (length);
}

int	make_linked_list(t_node **head, char **value)
{
	int	length;

	length = 1;
	*head = malloc(sizeof(t_node));
	if (!head)
		free_and_quit(head);
	(*head)->next = NULL;
	(*head)->data = atoi(*value);
	if ((*head)->data < -2147483648 || ((*head)->data > 2147483647))
		free_and_quit(head);
	length += make_and_return_length(head, value);
	return (length);
}

int	is_correct_order(t_node **head)
{
	t_node	*dup_head;

	dup_head = *head;
	is_dulicate(head);
	while (dup_head->next != NULL)
	{
		dup_head = dup_head->next;
		if (dup_head->data < dup_head->prev->data)
			return (0);
	}
	return (1);
}

void free_both_and_exit(t_node **a, t_node **b)
{
	free_linked_list(*a);
	free_linked_list(*b);
	write(2, "KO\n", 3);
	exit(EXIT_FAILURE);
}

void	handle_list(t_node **a, t_node **b, char **lines)
{
	t_node	*tail_a;

	tail_a = lstlast(*a);
	is_correct_order(a);
	result_checker(a, b, &tail_a, lines);
	if (!(*b == NULL))
		free_both_and_exit(a, b);
	if (!(is_correct_order(a)))
	{
		write(1, "KO\n", 3);
		free_linked_list(*a);
		exit(EXIT_FAILURE);
	}
	write(1, "OK\n", 3);
	free_linked_list(*a);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**values;
	int		length;

	a = NULL;
	b = NULL;
	if (ac == 2)
	{
		values = ft_split(av[1], ' ');
		check_if_correct_input(values);
		length = make_linked_list(&a, values);
		free_chars(values);
	}
	else if (ac > 2)
	{
		values = &av[1];
		check_if_correct_input(values);
		length = make_linked_list(&a, &av[1]);
	}
	else
		exit(EXIT_FAILURE);
	char *line[10];
	int index = 0;
	int i = 0;

	while ((line[index] = get_next_line(0)) != NULL)
		index++;
	if (index == 0)
		exit(EXIT_FAILURE);
	handle_list(&a, &b, line);
	free_linked_list(a);
	return (0);
}
