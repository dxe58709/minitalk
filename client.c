/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:13:12 by nsakanou          #+#    #+#             */
/*   Updated: 2023/07/24 18:06:07y nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(pid_t pid, char *str)
{
	int		i;
	int		bit;

	i = 0;
	while (str[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 0b00000001)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = ft_atoi(argv[1]);
	send(pid, argv[2]);
	return (0);
}
