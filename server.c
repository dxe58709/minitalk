/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:46:30 by nsakanou          #+#    #+#             */
/*   Updated: 2023/07/21 16:42:09 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	signal_handler(int signum)
{
	static int	i = 0;
	char		c = 0;

	if (signum == SIGUSR1)
		c = '1';
	else if (signum == SIGUSR2)
		c = '0';
	c <<= 1;
	c |= (signum == SIGUSR2) ? 1 : 0;
		i++;
	printf("Received bit: %c\n", c);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);

	while (1)
		pause();
	return (0);
}
