/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:46:30 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/24 20:27:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	signal_handler(int signum)
{
	static int				bit_position = 0;
	static unsigned char	c = 0;

	if (signum == SIGUSR1)
		c |= (1 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		bit_position = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
