#include <stdio.h>
#include "ft_printf_bonus.h"

int	main(void)
{
	printf("===\t-\t===\n\n");
	printf("%d - ", printf("...%#x...\n", 1358454));
	printf("%d\n\n", ft_printf("...%#x...\n", 1358454));

	printf("%d - ", printf("...%-1u...\n", 0));
	printf("%d\n\n", ft_printf("...%-1u...\n", 0));
}
