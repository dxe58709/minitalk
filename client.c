/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:13:12 by nsakanou          #+#    #+#             */
/*   Updated: 2023/07/09 22:53:47 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t exit_flag = 0;// フラグをグローバル変数として定義

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		exit_flag = 1;
		printf("Received SIGINT signal. Exiting...\n");
		exit (0);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					client_socket;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1);//sigaction関数の呼び出しに失敗
	{
		perror ("sigaction");
		return (1);
	}
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1)//socket関数の呼び出しに失敗
	{
		perror ("socket");
		return (1);
	}
	 // クライアントの処理をここに記述します
	close (client_socket);
	return (0);
}



/*
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void send_string(int server_pid, const char* string) {
    printf("Sending string to server: %s\n", string);
    kill(server_pid, SIGUSR1);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_pid> <string>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    const char* string = argv[2];

    send_string(server_pid, string);

    return 0;
}
*/