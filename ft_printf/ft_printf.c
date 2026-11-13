/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:48:33 by balca             #+#    #+#             */
/*   Updated: 2026/11/03 14:13:16 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	int		sum;
	va_list	args;

	if (!format)
		return (-1);
	sum = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			sum += which_char(format[i + 1], &args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			sum++;
		}
		i++;
	}
	va_end(args);
	return (sum);
}

int	which_char(char chr, va_list *args)
{
	(void)args;
	if (chr == 'c')
		return (print_char(va_arg(*args, int)));
	else if (chr == 's')
		return (print_string(va_arg(*args, char *)));
	else if (chr == 'p')
		return (print_pointer(va_arg(*args, void *)));
	else if (chr == 'd' || chr == 'i' )
		return (print_int(va_arg(*args, int)));
	else if (chr == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (chr == 'x')
		return (print_xhex(va_arg(*args, unsigned int)));
	else if (chr == 'X')
		return (print_xhex_big(va_arg(*args, unsigned int)));
	else if (chr == '%')
		return (print_percent());
	return (0);
}
// int	main(void)
// {
// 	int		a;
// 	int		*pA;
// 	char	*null_str;

// 	a = 2;
// 	pA = &a;
// 	null_str = NULL;
// 	printf("===== %%c =====\n");
// 	ft_printf("c: %c\n", 'A');
// 	printf("c: %c\n", 'A');

// 	printf("\n===== %%s =====\n");
// 	ft_printf("s: %s\n", "Berke");
// 	printf("s: %s\n", "Berke");
// 	ft_printf("%s\n", null_str);
// 	printf("%s\n", null_str);

// 	printf("\n===== %%%% =====\n");
// 	ft_printf("%%: %%\n");
// 	printf("%%: %%\n");

// 	printf("\n===== %%d =====\n");
// 	ft_printf("%d\n", (int)-2147483648);
// 	printf("%d\n", (int)-2147483648);
// 	ft_printf("%d\n", -58);
// 	printf("%d\n", -58);

// 	printf("\n===== %%u =====\n");
// 	ft_printf("%u\n", 2);
// 	printf("%u\n", 2);
// 	ft_printf("%u\n", 4294967295u);
// 	printf("%u\n", 4294967295u);

// 	printf("\n===== %%p =====\n");
// 	ft_printf("%p\n", pA);
// 	printf("%p\n", pA);
// 	return (0);
// }