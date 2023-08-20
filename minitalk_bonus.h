/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:59:45 by nsakanou          #+#    #+#             */
/*   Updated: 2023/08/20 17:19:44 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <signal.h>
# include <stdbool.h>

bool	check_args(int argc, char **argv, pid_t *pid);
void	ft_send(const pid_t pid, char *str);

void	bonus_signal_handler(int signum);

int		ft_isdigit(int c);
bool	is_space(char c);
int		ft_atoi(const char *str);

#endif
