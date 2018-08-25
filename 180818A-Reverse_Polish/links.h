#ifndef LINKS_H
# define LINKS_H

# include <stdlib.h>

typedef struct s_intop
{
	char op;
	int nb;
	struct s_intop *daddy;
	struct s_intop *junior;
} t_intop;

void push_intop(char c, int nb, t_intop **stack);
t_intop *get_last(t_intop *stack);
void move_op(t_intop **op_stack, t_intop **output_q);
int op(char c);
int do_ops(t_intop **output_q);

#endif
