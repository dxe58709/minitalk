/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:46:30 by nsakanou          #+#    #+#             */
/*   Updated: 2023/07/09 22:48:59 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t received_string = 0;

void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Received string from client: ");
        received_string = 1;
    }
}

int main(void) {
    pid_t pid = getpid();
    printf("Server PID: %d\n", pid);

    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    while (1) {
        if (received_string) {
            // Display the received string
            printf("String received: Hello, world!\n");
            received_string = 0;
        }
        usleep(10000);  // 10 milliseconds
    }

    return 0;
}