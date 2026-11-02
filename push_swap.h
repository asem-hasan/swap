#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
	int			*values;
	int			count;
}	t_config;

void	stack_init(t_stack *stack);
t_node	*stack_new_node(int value);
void	stack_add_top(t_stack *stack, t_node *node);
void	stack_free(t_stack *stack);
void	assign_index(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	config_init(t_config *cfg);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	free_split(char **tokens);
int		parse_flag(const char *arg, t_config *cfg);
int		check_duplicates(t_stack *stack_a, int value);
int		parse_number(const char *s, int *final);
int		add_number(t_stack *a, int value);
int		handle_arg(char *arg, t_stack *a, t_config *cfg);
int		parse_args(int argc, char **argv, t_stack *a, t_config *cfg);
void	list_add_back(t_stack *a, t_node *node);
int		compute_disorder(t_stack *a);

#endif
