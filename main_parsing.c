#include "push_swap.h"
#include <stdio.h>

static const char	*strategy_name(t_strategy s, int d)
{
	if (s == STRAT_SIMPLE)
		return ("Simple / O(n^2)");
	if (s == STRAT_MEDIUM)
		return ("Medium / O(n*sqrt(n))");
	if (s == STRAT_COMPLEX)
		return ("Complex / O(n log n)");
	if (d < 2000)
		return ("Adaptive / O(n^2)");
	if (d < 5000)
		return ("Adaptive / O(n*sqrt(n))");
	return ("Adaptive / O(n log n)");
}

static void	print_bench(t_config *cfg, int d)
{
	fprintf(stderr, "[bench] disorder: %d.%02d%%\n", d / 100, d % 100);
	fprintf(stderr, "[bench] strategy: %s\n", strategy_name(cfg->strategy, d));
	fprintf(stderr, "[bench] total_ops: 0\n");
	fprintf(stderr, "[bench] sa: 0 sb: 0 ss: 0 pa: 0 pb: 0\n");
	fprintf(stderr, "[bench] ra: 0 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0\n");
}

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_node		*a;

	if (argc == 1)
		return (0);
	a = NULL;
	if (!parse_args(argc, argv, &a, &cfg))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (cfg.bench)
		print_bench(&cfg, compute_disorder(a));
	list_free(&a);
	return (0);
}