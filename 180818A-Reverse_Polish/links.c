#include "links.h"
#include "opp_func.h"

void push_intop(char c, int nb, t_intop **stack)
{
	t_intop	*new;
	t_intop	*last;

	new = (t_intop *)malloc(sizeof(t_intop));
	new->op = c;
	new->nb = nb;
	new->junior = 0;
	last = get_last(*stack);
	if (last)
	{
		last->junior = new;
		new->daddy = last;
	}
	else
	{
		*stack = new;
		new->daddy = 0;
	}
}

t_intop *get_last(t_intop *stack)
{
	while (stack && stack->junior)
		stack = stack->junior;
	return (stack);
}
void move_op(t_intop **op_stack, t_intop **output_q)
{
	t_intop *daddy;
	t_intop *to_move;

	daddy = get_last(*output_q);
	to_move = get_last(*op_stack);
	if (daddy)
		daddy->junior = to_move;
	else
			*output_q = to_move;
	if (to_move->daddy)
		to_move->daddy->junior = 0;
	else
		*op_stack = 0;
	to_move->daddy = daddy;
}

int op(char c)
{
	int i;

	i = 0;
	while (g_opptab[i].c != c && c < 5)
		i++;
	return (i < 5 ? i : -1);
}

int do_ops(t_intop **output_q)
{
	int res;
	t_intop	*ptr;
	t_intop *to_remove;

	ptr = *output_q;
	while (ptr->op == '.' && ptr->junior)
		ptr = ptr->junior;
	if (ptr->op != '.')
	{
		ptr->nb = g_opptab[op(ptr->op)].f(ptr->daddy->daddy->nb, ptr->daddy->nb);
		to_remove = ptr->daddy->daddy;
		ptr->daddy = ptr->daddy->daddy->daddy;
		if (ptr->daddy)
			ptr->daddy->junior = ptr;
		else
			*output_q = ptr;
		free(to_remove->junior);
		free(to_remove);
		return (do_ops(output_q));
	}
	res = ptr->nb;
	free(ptr);
	return (res);
}
