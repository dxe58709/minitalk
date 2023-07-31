/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:13:12 by nsakanou          #+#    #+#             */
/*   Updated: 2023/07/31 16:15:16 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(const pid_t pid, char *str)
{
	int	i;
	int	bit;
	int	kill_status;

	i = 0;
	while (str[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 0b00000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			if (kill_status == -1)
			{
				write(STDOUT_FILENO, "kill error\n", 11);
				return;
			}
			bit++;
			usleep(500);
		}
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{    
		write(STDOUT_FILENO, "Invalid arguments\n", 18);
		return (0);
	}
	if (ft_strlen(argv[1]) > 5)//7?
	{
		write(STDOUT_FILENO, "Invalid PID\n", 12);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		write(STDOUT_FILENO, "Invalid PID\n", 12);
		return (0);
	}
	ft_send(pid, argv[2]);
	return (0);
}

