/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:51:01 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/12 22:51:34 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	ft_printf("Hello, world!\n");
	ft_printf("This is a character: %c\n", 'A');
	ft_printf("This is a string: %s\n", "Hello");
	ft_printf("This is a decimal number: %d\n", 42);
	ft_printf("This is an unsigned number: %u\n", 123456);
	ft_printf("This is a hexadecimal number: %x\n", 255);
	ft_printf("This is a pointer: %p\n", (void *)0x12345678);
	ft_printf("This is a percent sign: %%\n");
	return (0);
}
