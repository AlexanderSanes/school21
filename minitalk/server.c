/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:45:46 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/13 14:44:36 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include "utils.h"
#include <stdio.h>

#define BUFFER_SIZE 10000000000

typedef struct s_signal {
	sig_atomic_t	g_signal_status;
	sig_atomic_t	g_sig_pid;
}	t_signal;

volatile t_signal	g_signal = {0, 0};

void	set_signal_pid(siginfo_t *info, \
						int *i, int *bit_shift)
{
	g_signal.g_sig_pid = info->si_pid;
	*i = 0;
	*bit_shift = 0;
}

static void	handler(int signo, siginfo_t *info, void *context)
{
	static int	bit_shift = 0;
	static char	buf[BUFFER_SIZE];
	static int	i = 0;

	(void)context;
	if (g_signal.g_sig_pid != info->si_pid)
		set_signal_pid(info, &i, &bit_shift);
	if (signo == SIGUSR1)
		buf[i] |= 1 << bit_shift;
	else if (signo == SIGUSR2)
		buf[i] &= ~(1 << bit_shift);
	bit_shift++;
	if (bit_shift == 8)
	{
		bit_shift = 0;
		if (buf[i] == '\0')
		{
			write(1, buf, i);
			write(1, "\n", 1);
			i = 0;
		}
		else
			i++;
	}
	g_signal.g_signal_status = 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		while (g_signal.g_signal_status != 1)
		{
		}
		g_signal.g_signal_status = 0;
		kill(g_signal.g_sig_pid, SIGUSR1);
	}
	return (0);
}
