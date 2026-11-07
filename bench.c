#include "push_swap.h"

void	stats_record(t_stats *stats, t_operation op)
{
	if (!stats || op >= OP_COUNT)
		return ;
	stats->count[op]++;
	stats->total++;
}

static const char *strategy_name(t_strategy strategy, int disorder)
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

static void put_stat(const char *name, size_t n)
{
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(n, 2);
}

static void put_disorder(int disorder)
{
	ft_putnbr_fd(disorder / 100, 2);
	ft_putstr_fd(".", 2);
	if (disorder % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(disorder % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void print_ops(t_stats *s)
{
	ft_putstr_fd("[bench]", 2);
	put_stat("sa", s->count[OP_SA]);
	put_stat("sb", s->count[OP_SB]);
	put_stat("ss", s->count[OP_SS]);
	put_stat("pa", s->count[OP_PA]);
	put_stat("pb", s->count[OP_PB]);
	ft_putstr_fd("\n[bench]", 2);
	put_stat("ra", s->count[OP_RA]);
	put_stat("rb", s->count[OP_RB]);
	put_stat("rr", s->count[OP_RR]);
	put_stat("rra", s->count[OP_RRA]);
	put_stat("rrb", s->count[OP_RRB]);
	put_stat("rrr", s->count[OP_RRR]);
	ft_putstr_fd("\n", 2);
}

void print_bench(t_config *cfg, t_stats *stats, int disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(cfg->strategy, disorder), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(stats->total, 2);
	ft_putstr_fd("\n", 2);
	print_ops(stats);
}
