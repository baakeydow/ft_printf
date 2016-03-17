#include "printf.h"
#include <locale.h>

int				main(void)
{
	char	str[]= "cool";
	int		d = 42424242;

	setlocale(LC_ALL, "");
	ft_printf("|%S|\n", L"bÆla");
	ft_printf("|%10s|\n", str);
	ft_printf("------------conv_p\n");
	ft_printf("|%p|\n", d);
	ft_printf("------------conv_o\n");
	ft_printf("|%o|\n", d);
	ft_printf("|%O|\n", d);
	ft_printf("------------conv_d\n");
	ft_printf("|%10.2d|\n", d);
	ft_printf("|%i|\n", d);
	ft_printf("------------conv_u\n");
	ft_printf("|%u|\n", d);
	ft_printf("|%U|\n", d);
	ft_printf("------------conv_x\n");
	ft_printf("|%x|\n", d);
	ft_printf("|%#x|\n", d);
	ft_printf("|%X|\n", d);
	ft_printf("------------conv_c\n");
	ft_printf("|%c|\n", 'A');
	ft_printf("|%C|\n", L'Æ');
	ft_printf("\n---------------------------\n");
	ft_printf("|%S|\n", L"bÆla");
	ft_printf("|%-s|\n", str);
	ft_printf("|%-20s|\n", str);
	ft_printf("|%p|\n", d);
	ft_printf("|%o|\n", d);
	ft_printf("|%O|\n", d);
	ft_printf("|%0d|\n", d);
	ft_printf("|%+i|\n", d);
	ft_printf("|%u|\n", d);
	ft_printf("|%U|\n", d);
	ft_printf("|%#x|\n", d);
	ft_printf("|%X|\n", d);
	ft_printf("|%c|\n", 'A');
	ft_printf("|%C|\n", L'Æ');
	ft_printf("\n---------------------------\n");
	ft_printf("|%ls|\n", L"bÆla");
	ft_printf("|%lc|\n", L'Æ');
	ft_printf("|%ld|\n", d);
	ft_printf("|%hhd|\n", d);
	ft_printf("|%lld|\n", d);
	ft_printf("|%jd|\n", d);
	ft_printf("|%zd|\n", d);
	return (0);
}
