/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:51:42 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/24 20:46:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	int_max(int c)
{
	return (c > INT_MAX || c < '0');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (is_space(str[i]))
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	if (int_max(nb))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (!ft_isdigit(nb))
		return (-1);
	return (nb);
}
