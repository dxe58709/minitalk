/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:13:12 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/24 20:30:16 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
	int	bit_shift;
	int	kill_status;

	while (*str != '\0')
	{
		bit_shift = 0;
		while (bit_shift < 8)
		{
			if ((*str >> bit_shift) & 0b00000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			if (kill_status == -1)
				write(STDERR_FILENO, "Different PID\n", 14);
			bit_shift++;
			usleep(200);
		}
		str++;
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
