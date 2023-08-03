/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:13:12 by nsakanou          #+#    #+#             */
/*   Updated: 2023/08/03 16:37:42 by nsakanou         ###   ########.fr       */
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
				write(STDERR_FILENO, "kill error\n", 11);
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
		i++;
	return (i);
}

bool check_args(int argc, char **argv, pid_t *pid)
{
      if (argc != 3)
      {    
              write(STDERR_FILENO, "Invalid arguments\n", 18);
              return (false);
      }       
      size_t	pid_len;
	  pid_len = ft_strlen(argv[1]);
	  if (pid_len < 3 || pid_len > 5)
      {
              write(STDERR_FILENO, "Invalid PID\n", 12);
              return (false);
      }       
      *pid = (pid_t)ft_atoi(argv[1]);
      if (*pid == 0)
      {
              write(STDERR_FILENO, "Invalid PID\n", 12);
              return (false);
      }       
	return (true);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	if (!check_args(argc, argv, &pid))
		return (EXIT_FAILURE);
	ft_send(pid, argv[2]);
	return (0);
}

