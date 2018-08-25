#include "eval_expr.h"

int greater_prec(char cur, char stack_top)
{
	int op_c;
	int op_st;

	op_c = op(cur);
	op_st = op(stack_top);
	if ((op_c < 2 && op_st < 2) || (op_c > 1 && op_st > 1)
			|| (op_c < 2 && op_st > 1))
		return (0);
	return (1);
}

void del_last(t_intop **op_stack)
{
	t_intop *to_rem;

	to_rem = get_last(*op_stack);
	if (to_rem->daddy)
		to_rem->daddy->junior = 0;
	else
		*op_stack = 0;
	free(to_rem);
}

int eval_expr(char *str)
{
	t_intop *output_q;
	t_intop *op_stack;

	while (*str)
	{
		if (op(*str) == -1 && *str != 32)
			push_intop('.', ft_atoi(&str), &output_q);
		else if (op(*str) > -1 && *str != '(' && *str != ')')
		{
			while (op_stack && greater_prec(*str, get_last(op_stack)->op))
				move_op(&op_stack, &output_q);
			push_intop(*str++, 0, &op_stack);
		}
		else if (*str == '(')
			push_intop(*str++, 0, &op_stack);
		else if (*str == ')')
		{
			while (get_last(op_stack)->op != '(')
				move_op(&op_stack, &output_q);
			del_last(&op_stack);
			str++;
		}

	}
	while (op_stack)
		move_op(&op_stack, &output_q);
	return (do_ops(&output_q));
}
