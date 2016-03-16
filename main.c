#include "printf.h"
#include <locale.h>

int				main(void)
{
   /* char	str[]= "%.3S\n";*/
	char	str2[]= "%.2S\n";
	char	str3[]= "%.2C\n";
	char	str4[]= "%.2s\n";
	int		ret;
	int		ret2;

	setlocale(LC_ALL, "");
   /* ret = printf(str, L"Æbla\n");*/
	/*ret2 = ft_printf(str, L"Æbla\n");*/
	/*ft_printf("%d : %d\n\n", ret, ret2);*/
	ft_printf("------------------------\n\n");
	ret = printf(str2, NULL);
	ret2 = ft_printf(str2, NULL);
	ft_printf("real = %d : mine = %d\n\n", ret, ret2);
	ft_printf("------------------------\n\n");
	ret = printf(str3, NULL);
	ret2 = ft_printf(str3, NULL);
	ft_printf("real = %d : mine = %d\n\n", ret, ret2);
	ft_printf("------------------------\n\n");
	ret = printf(str4, NULL);
	ret2 = ft_printf(str4, NULL);
	ft_printf("real = %d : mine = %d\n\n", ret, ret2);

	return (0);
}
