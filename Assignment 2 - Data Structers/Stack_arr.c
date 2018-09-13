#include "Stack_arr.h"
#include "Ex1Declarations.h"

void create_stack (stack *ps)
{
	ps->top = -1;
}

int push_operand(stack_type x, stack *ps)
{
	if (check_operand(x) == -1)
		return -1;

	if (ps->top < MaxStack-1)
	{
		ps->top++;
        ps->items[ps->top] = x;
        return 1;
	}
	return 0;
}

int push_operator(stack_type x, stack *ps)
{
	if (check_operator(x) == -1)
		return -1;
	if (ps->top < MaxStack - 1)
	{
		ps->top++;
		ps->items[ps->top] = x;
		return 1;
	}
	return 0;
}

int push_result(stack_type x, stack *ps)
{
	if (ps->top < MaxStack - 1)
	{
		ps->top++;
		ps->items[ps->top] = x;
		return 1;
	}
	return 0;
}

int pop (stack *ps, stack_type *px)
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
        ps->top--;
        return 1;
	}
	return 0;
}

int stack_top (stack *ps, stack_type *px)
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
        return 1;
	}
	return 0;
}

int stack_is_empty (stack *ps)
{
	return ps->top == -1;
}

int stack_is_full (stack *ps)
{
	return ps->top == MaxStack-1;
}


