/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: b3 <b3@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:48:33 by balca             #+#    #+#             */
/*   Updated: 2026/10/31 21:30:42 by b3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>



int	ft_printf(const char *format, ...)
{
	int		i;
	int		sum;
	va_list args;

	sum = 0;
	i = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
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
		return (0);
	else if (chr == 'd' || chr == 'i' )
		return (print_int(va_arg(*args,int)));
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
int main()
{
	ft_printf("c: %c\n", 'A');
	ft_printf("s: %s\n", "Berke");
	ft_printf("s NULL: %s\n  %s", NULL, "berke");
	ft_printf("%%: %%\n");
	ft_printf("%d\n", -2147483648);
	ft_printf("%d\n", -58);
	ft_printf("%u\n", 2);
	ft_printf("%u\n", 4294967295);
	ft_printf("%x\n", 10);
	ft_printf("%x\n\n", 9);
	ft_printf("%X\n", 10);
	ft_printf("%X\n", 255);



}