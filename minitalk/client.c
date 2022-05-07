/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:41:57 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/12 11:26:26 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

volatile sig_atomic_t	g_signal_status = 1;

static void	handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGUSR1)
		g_signal_status = 1;
}

void	send_signal(int pid, int signo)
{
	if (kill(pid, signo) == -1)
	{
		write(1, "Server on this pid not exist!\n", 30);
		exit(1);
	}
}

void	send_symb(pid_t pid, char symb)
{
	int	bit_shift;

	bit_shift = 0;
	while (bit_shift < 8)
	{
		if (g_signal_status)
		{
			g_signal_status = 0;
			if (symb & (1 << bit_shift))
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			bit_shift++;
		}
	}
}

void	send_message(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
		send_symb(pid, message[i++]);
	send_symb(pid, '\0');
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (argc != 3)
	{
		write(1, "./client [server pid] [message]\n", 32);
		return (1);
	}
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
