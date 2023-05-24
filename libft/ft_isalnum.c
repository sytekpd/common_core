/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:38:46 by prossi            #+#    #+#             */
/*   Updated: 2023/05/05 20:00:59 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_isdigit(unsigned int i);
static unsigned int	ft_isalpha(unsigned int i);

unsigned int	ft_isalnum(unsigned int i)
{
	return (ft_isalpha(i) || ft_isdigit(i));
}

static unsigned int	ft_isdigit(unsigned int i)
{
	return (i >= '0' && i <= '9');
}

static unsigned int	ft_isalpha(unsigned int i)
{
	return ((i | 32) >= 0x61 && (i | 32) <= 0x7A);
}
