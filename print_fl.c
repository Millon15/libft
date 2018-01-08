
#include "ft_printf.h"

void		print_fl(t_flags *fl)
{
	printf("is_small_x = %d\n", fl->is_small_x);
	printf("plus = %d\n", fl->plus);
	printf("minus = %d\n", fl->minus);
	printf("space = %d\n", fl->space);
	printf("hesh = %d\n", fl->hesh);
	printf("zero = %d\n", fl->zero);
	printf("hh = %d\n", fl->hh);
	printf("h = %d\n", fl->h);
	printf("l = %d\n", fl->l);
	printf("ll = %d\n", fl->ll);
	printf("j = %d\n", fl->j);
	printf("z = %d\n", fl->z);
	printf("t = %d\n", fl->t);
	printf("L = %d\n", fl->lll);
	printf("precision specifier = %d\n", fl->precs_spec);
	printf("base = %d\n", fl->base);
	printf("precision = %d\n", fl->precision);
	printf("min_lenth = %d\n", fl->min_lenth);
}
