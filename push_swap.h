/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:33:59 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 15:42:14 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_node
{
	int				value;
	size_t			index;
	struct s_node	*next;
}	t_node;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operation;

typedef struct s_stats
{
	size_t	count[OP_COUNT];
	size_t	total;
}	t_stats;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
	t_stats	*stats;
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
int		is_sorted(t_stack *a);
void	simple(t_stack *stack_a, t_stack *stack_b);
void	chunk_sort(t_stack *stack_a, t_stack *stack_b);
void	complex(t_stack *stack_a, t_stack *stack_b);
void	print_bench(t_config *cfg, t_stats *stats, int disorder);
void	stats_record(t_stats *stats, t_operation op);
size_t	ft_isqrt(size_t n);
void	put_disorder(int disorder);
int	ft_printf_nbr(int fd, int n);
int	ft_printf_chr(int fd, char c);
int	ft_printf_str(int fd, char *str);
int	ft_printf(int fd, const char *str, ...);

#endif
