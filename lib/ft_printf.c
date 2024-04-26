/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:16:43 by stopp             #+#    #+#             */
/*   Updated: 2023/12/17 15:20:59 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	chk_format(const char *format, va_list args)
{
	int	re_value;

	re_value = 0;
	if (*format == 'c')
		re_value += print_char(va_arg(args, int));
	else if (*format == 's')
		re_value += print_str(va_arg(args, char *));
	else if (*format == 'p')
		re_value += print_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		re_value += print_nbr(va_arg(args, int));
	else if (*format == 'u')
		re_value += print_unsigned_nbr(va_arg(args, unsigned int));
	else if (*format == 'x')
		re_value += print_hex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		re_value += print_hex(va_arg(args, unsigned int), 1);
	return (re_value);
}

int	ft_printf(const char *format, ...)
{
	int		re_value;
	va_list	args;

	va_start(args, format);
	re_value = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				re_value += chk_format(format, args);
			else if (*format == '%')
				re_value += print_char('%');
		}
		else
			re_value += print_char(*format);
		if (re_value < 0)
			return (-1);
		format++;
	}
	va_end(args);
	return (re_value);
}

// int	main(void)
// {
// 	// char	*test = "hallo";
// 	// void	*ptr = (void *)0xaff9999;
// 	unsigned int	i = 200000;

// 	printf("%i\n", ft_printf("%x\n", i));
// 	printf("%i\n", printf("%x\n", i));
// }
