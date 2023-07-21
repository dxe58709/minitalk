/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:13:12 by nsakanou          #+#    #+#             */
/*   Updated: 2023/07/21 16:42:05 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	if (ac != 2)	
	 {
	 	 fprintf(stderr, "Usage: %s <server_pid>\n", av[0]);
	  	 return (1);
	 }
	pid_t server_pid = atoi(av[1]);
	if (server_pid <= 0)
	{
		fprintf(stderr, "Invalid server PID\n");
		return (1);
	}
	if (kill(server_pid, SIGUSR1) == -1)
	{
		fprintf(stderr, "Error sending signal to server: %s\n");
		return (1);
	}
	else
    {
        printf("Signal successfully sent to the server.\n");
    }
	return (0);
}

