/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:46:30 by nsakanou          #+#    #+#             */
/*   Updated: 2023/07/26 17:37:56 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	signal_handler(int signum)
{
	static int				i;//ビットの受信数をカウントする変数
	static unsigned char	c;//受信したビットを格納する変数

	i = 0;
	c = 0;

	if (signum == SIGUSR1)
		c |= (1 << i);//i番目のビットを1にセット
	else if (signum == SIGUSR2)
		c &= ~(1 << i);//i番目のビットを０にセット
	i++;
	if (i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);//受信した８ビットを標準出力に出力
		c = 0;
	}
	else//まだ８ビット受信していない場合
		c <<= 1;//受信したビットをcの次のビットにシフト
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
