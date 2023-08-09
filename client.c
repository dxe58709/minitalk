/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:13:12 by nsakanou          #+#    #+#             */
/*   Updated: 2023/08/09 18:24:39 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	check_args(int argc, char **argv, pid_t *pid)
{
	if (argc != 3)
	{
		write(STDERR_FILENO, "Invalid arguments\n", 18);
		return (false);
	}
	*pid = (pid_t)ft_atoi(argv[1]);
	if (*pid < 100 || *pid > 99998)
	{
		write(STDERR_FILENO, "Invalid PID\n", 12);
		return (false);
	}
	return (true);
}

void	ft_send(const pid_t pid, char *str)
{
	int	i;
	int	bit_shift;
	int	kill_status;

	i = 0;
	while (str[i] != '\0')
	{
		bit_shift = 0;
		while (bit_shift < 8)
		{
			if ((str[i] >> bit_shift) & 0b00000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			bit_shift++;
			usleep(200);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (!check_args(argc, argv, &pid))
		return (EXIT_FAILURE);
	ft_send(pid, argv[2]);
	return (0);
}
