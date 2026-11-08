/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:20:43 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:52:44 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_strategy	choose_adaptive_strategy(int disorder)
{
	if (disorder < 2000)
		return (STRAT_SIMPLE);
	if (disorder < 5000)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	run_strategy(t_strategy strategy, t_stack *a, t_stack *b)
{
	if (strategy == STRAT_SIMPLE)
		simple(a, b);
	else if (strategy == STRAT_MEDIUM)
		chunk_sort(a, b);
	else if (strategy == STRAT_COMPLEX)
		complex(a, b);
}

void	solve(t_config *cfg, t_stack *a, t_stack *b, int disorder)
{
	t_strategy	selected;

	selected = cfg->strategy;
	if (selected == STRAT_ADAPTIVE)
		selected = choose_adaptive_strategy(disorder);
	assign_index(a);
	if (!is_sorted(a))
		run_strategy(selected, a, b);
	if (cfg->bench)
		print_bench(cfg, a->stats, disorder);
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_stack		a;
	t_stack		b;
	t_stats		stats;
	int			disorder;

	stack_init(&a);
	stack_init(&b);
	if (argc == 1)
		return (0);
	if (!parse_args(argc, argv, &a, &cfg))
	{
		ft_printf(2, "Error\n");
		stack_free(&b);
		return (1);
	}
	stats = (t_stats){0};
	a.stats = &stats;
	b.stats = &stats;
	disorder = compute_disorder(&a);
	solve(&cfg, &a, &b, disorder);
	stack_free(&a);
	stack_free(&b);
	free(cfg.values);
	return (0);
}
