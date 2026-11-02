// #include "push_swap.h"
// int main(void)
// {
//     t_stack *a;
// //    t_stack  *b;
//     t_node *node;

//     stack_init(a);
//   //  stack_init(b);
//     printf("After init A: size = %d, top = %p\n",
//         a->size, (void *)a->top);

//     node = stack_new_node(10);
//     if (!node)
//         return (1);
//     stack_add_top(a, node);

//     node = stack_new_node(20);
//     if (!node)
//     {
//       stack_free(a);
//         return (1);
//     }
//     stack_add_top(a, node);

//     node = stack_new_node(42);
//     if (!node)
//     {
//       stack_free(a);
//         return (1);
//     }
//     stack_add_top(a, node);

//     printf("After adding nodes:\n");
//     printf("size = %d\n", a->size);
//     printf("top = %d\n", a->top->value);

//     node = a->top;
//     while (node)
//     {
//         printf("%d -> ", node->value);
// 	printf("%d\n", node->index);
//         node = node->next;
//     }
//     printf("NULL\n");
//     assign_index(a);
//         node = a->top;
//     while (node)
//     {
//         printf("%d -> ", node->value);
//         printf("%d\n", node->index);
//         node = node->next;
//     }
//     printf("NULL\n");
// /*
//             printf("After init B: size = %d, top = %p\n",
//         b->size, (void *)b->top);
//        node = stack_new_node(1032);
//     if (!node)
//         return (1);
//     stack_add_top(b, node);

//     node = stack_new_node(43);
//     if (!node)
//     {
//       stack_free(b);
//         return (1);
//     }
//     stack_add_top(b, node);

//     node = stack_new_node(454);
//     if (!node)
//     {
//       stack_free(b);
//         return (1);
//     }
//     stack_add_top(b, node);

//     printf("After adding nodes:\n");
//     printf("size = %d\n", b->size);
//     printf("top = %d\n", b->top->value);

//       node = b->top;
//     while (node)
//     {
//         printf("%d -> ", node->value);
//         node = node->next;
//     }
//     printf("NULL\n");
//     rr(a,b);
//     node = a->top;
//         while (node)
//     {
//         printf("%d -> ", node->value);
//         node = node->next;
//     }
//     printf("NULL\n");
//     node = b->top;
//         while (node)
//     {
//         printf("%d -> ", node->value);
//         node = node->next;
//     }
//     printf("NULL\n");
//         printf("After rr A:\n");
//     printf("size = %d\n", a->size);
//     printf("top = %d\n", a->top->value);
//             printf("After rr B:\n");
//     printf("size = %d\n", b->size);
//     printf("top = %d\n", b->top->value);*/
//   stack_free(a);
//   //stack_free(b);
//     return (0);
// }
  
