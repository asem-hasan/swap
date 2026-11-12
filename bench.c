/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syaseen <syaseen@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:14:12 by syaseen           #+#    #+#             */
/*   Updated: 2026/11/08 11:45:32 by syaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	stats_record(t_stats *stats, t_operation op)
{
	if (!stats || op >= OP_COUNT)
		return ;
	stats->count[op]++;
	stats->total++;
}

static const char	*strategy_name(t_strategy strategy, int disorder)
{
	if (strategy == STRAT_SIMPLE)
		return ("Simple / O(n^2)");
	if (strategy == STRAT_MEDIUM)
		return ("Medium / O(n*sqrt(n))");
	if (strategy == STRAT_COMPLEX)
		return ("Complex / O(n log n)");
	if (disorder < 2000)
		return ("Adaptive / O(n^2)");
	if (disorder < 5000)
		return ("Adaptive / O(n*sqrt(n))");
	return ("Adaptive / O(n log n)");
}

static void	put_stat(const char *name, int n)
{
	ft_printf(2, " %s:", name);
	ft_printf(2, "%d", n);
}

static void	print_ops(t_stats *s)
{
	ft_printf(2, "%s", "[bench]");
	put_stat("sa", s->count[OP_SA]);
	put_stat("sb", s->count[OP_SB]);
	put_stat("ss", s->count[OP_SS]);
	put_stat("pa", s->count[OP_PA]);
	put_stat("pb", s->count[OP_PB]);
	ft_printf(2, "%s", "\n[bench]");
	put_stat("ra", s->count[OP_RA]);
	put_stat("rb", s->count[OP_RB]);
	put_stat("rr", s->count[OP_RR]);
	put_stat("rra", s->count[OP_RRA]);
	put_stat("rrb", s->count[OP_RRB]);
	put_stat("rrr", s->count[OP_RRR]);
	ft_printf(2, "%s", "\n");
}

void	print_bench(t_config *cfg, t_stats *stats, int disorder)
{
	if (!cfg || !stats)
		return ;
	ft_printf(2, "%s", "[bench] disorder: ");
	put_disorder(disorder);
	ft_printf(2, "%s", "[bench] strategy: ");
	ft_printf(2, "%s", (char *)strategy_name(cfg->strategy, disorder));
	ft_printf(2, "%s", "\n[bench] total_ops: ");2	ft_printf(1, "%d", stats->total);
	ft_printf(2, "%s", "\n");
	print_ops(stats);
}
