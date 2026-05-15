#include "checker.h"

//	Loads Stack A with the revieced args
//	\returns
//	1 if ok, 0 if error
static int	load_stack(t_stack **stack_a, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (str_check(stack_a, argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

//	Reads the moves from stdin and stores them
//	in an array of strings
//	\returns
//	the array of moves, NULL if error
static char	**read_moves(void)
{
	char	**moves;
	char	*line;
	int		i;

	moves = malloc(sizeof(char *) * 1000);
	if (!moves)
		return (NULL);
	i = 0;
	line = get_next_line(0);
	while (line)
	{
		moves[i] = line;
		i++;
		line = get_next_line(0);
	}
	moves[i] = NULL;
	return (moves);
}

//	Replays the given move list onto the stacks
//	\returns
//	0 if ok, 1 if error
static int	apply_moves(t_stack **stack_a, t_stack **stack_b, char **moves)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (move_check(stack_a, stack_b, moves[i]) != 0)
		{
			write(2, "Error\n", 7);
			return (1);
		}
		i++;
	}
	return (0);
}

//	Main function for the checker program
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**moves;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (load_stack(&stack_a, argv, argc) != 0)
		return (free_list(&stack_a), free_list(&stack_b), 1);
	if (dup_check(&stack_a) != 0)
		return (free_list(&stack_a), free_list(&stack_b), 1);
	indexer(stack_a);
	moves = read_moves();
	if (!moves)
		return (write(2, "Error\n", 7),
			free_list(&stack_a), free_list(&stack_b), 1);
	if (apply_moves(&stack_a, &stack_b, moves) != 0)
		return (free_list(&stack_a), free_list(&stack_b), 1);
	if (is_sorted(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_matrix(moves);
	return (free_list(&stack_a), free_list(&stack_b), 0);
}
