#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
// make sure to include all operations ss.
void result_checker(t_node **a, t_node **b, t_node **tail_a, char **lines)
{
	t_node *tail_b;
	int index = 0;

	tail_b = NULL;
	while (lines[index] != NULL)
	{
		*tail_a = lstlast(*a);
		if (ft_strncmp(lines[index], "sa", 2) == 0)
			swap(a);
		else if (ft_strncmp(lines[index], "sb", 2) == 0)
			swap(b);
		else if (ft_strncmp(lines[index], "pa", 2) == 0)
			push(a, b, 'b');
		else if (ft_strncmp(lines[index], "pb", 2) == 0)
			push(a, b, 'a');
		else if (ft_strncmp(lines[index], "ra", 2) == 0)
			rotate(a, tail_a);
		else if (ft_strncmp(lines[index], "rb", 2) == 0)
			rotate(b, &tail_b);
		else if (ft_strlen(lines[index]) == 2 && ft_strncmp(lines[index], "rr", 2) == 0)
			rr(a, b, tail_a, &tail_b);
		else if (ft_strncmp(lines[index], "rra", 3) == 0)
			reverse_rotate(a, tail_a);
		else if (ft_strncmp(lines[index], "rrb", 3) == 0)
			reverse_rotate(b, &tail_b);
		else if (ft_strncmp(lines[index], "rrr", 3) == 0)
			rrr(a, b, tail_a, &tail_b);
		else
			free_both_and_exit(a, b);
		index++;
	}
}
