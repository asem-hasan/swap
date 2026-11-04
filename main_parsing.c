#include "push_swap.h"


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
	t_stack		a;
	t_stack		b;
	// t_node		*node;

	stack_init(&a);
	stack_init(&b);
	    // prinf("After init A: size = %d, top = %p\n",
      //   a.size, (void *)a.top);t
	if (argc == 1)
		return (0);
	if (!parse_args(argc, argv, &a, &cfg))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (cfg.bench)
		print_bench(&cfg, compute_disorder(&a));
	//     node = a.top;
  //   while (node)
  //   {
  //       printf("%d -> ", node->value);
	// // printf("%d\n", node->index);
  //       node = node->next;
  //   }
  //   printf("NULL\n");

	// 	    printf("After adding nodes:\n");
  //   printf("size = %d\n", a.size);
  //   printf("top = %d\n", a.top->value);
		simple(&a,&b);
// 		printf("after sort\n");
// 		node = a.top;
// 	while (node)
// 	{
// 			printf("%d -> ", node->value);
// // printf("%d\n", node->index);
// 			node = node->next;
// 	}
// 	printf("NULL\n");

// 			printf("After adding nodes:\n");
// 	printf("size = %d\n", a.size);
// 	printf("top = %d\n", a.top->value);
	stack_free(&a);
	stack_free(&b);
	return (0);
}