/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:46:30 by nsakanou          #+#    #+#             */
/*   Updated: 2023/08/20 17:19:53 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	bonus_signal_handler(int signum)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, bonus_signal_handler);
	signal(SIGUSR2, bonus_signal_handler);
	while (1)
		pause();
	return (0);
}
