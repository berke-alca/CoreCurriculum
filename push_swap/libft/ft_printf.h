/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balca <balca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:59:03 by balca             #+#    #+#             */
/*   Updated: 2026/11/09 12:15:15 by balca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	which_char(char chr, va_list *args);
int	print_percent(void);
int	print_char(char c);
int	print_string(char *str);
int	print_int(int i);
int	print_unsigned(unsigned int u);
int	print_xhex(unsigned int u);
int	print_xhex_big(unsigned int u);
int	print_pointer(void *ptr);

#endif