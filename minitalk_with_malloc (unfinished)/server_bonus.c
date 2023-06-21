/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:12:24 by wremy             #+#    #+#             */
/*   Updated: 2023/04/29 23:11:59 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	store_chars(char c)
{
	char		*c_str;
	static char	*str = NULL;

	if (str == NULL)
		str = ft_calloc(1, 1);
	c_str = ft_calloc(2, 1);
	c_str[0] = c;
	if (c != '\0')
		str = ft_strjoin(str, c_str);
	else
	{
		ft_printf("%s", str);
		free(str);
		str = NULL;
	}
	free(c_str);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bits;
	static int	bits_received = 0;

	bits = (bits << 1) | (signal == SIGUSR2);
	bits_received++;
	if (bits_received == 8)
	{
		if ((char)bits == '\0')
			kill(info->si_pid, SIGUSR1);
		store_chars((char) bits);
		bits_received = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("%i\n", pid);
	action.sa_sigaction = &signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
