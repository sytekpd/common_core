/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:38:46 by prossi            #+#    #+#             */
/*   Updated: 2023/05/05 19:48:38 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_isalpha(unsigned int i)
{
	return ((i | 32) >= 0x61 && (i | 32) <= 0x7A);
}