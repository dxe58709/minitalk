/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:46:30 by nsakanou          #+#    #+#             */
/*   Updated: 2023/08/20 17:37:57 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	printf("Server PID: %d\n", getpid());//自作printfにする
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
