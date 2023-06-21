/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:12:30 by wremy             #+#    #+#             */
/*   Updated: 2023/04/30 15:46:37 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	letter_to_binary(int pid, int c)
{
	int	bits_send;
	int	binair;

	bits_send = 0;
	while (bits_send < 8)
	{
		binair = (c >> (7 - bits_send)) & 1;
		if (binair == 0)
			kill(pid, SIGUSR1);
		else if (binair == 1)
			kill(pid, SIGUSR2);
		usleep(500);
		bits_send++;
	}
}

void	word_to_letters(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		letter_to_binary(pid, (int) str[i]);
		i++;
	}
	letter_to_binary(pid, (int) '\0');
}

int	main(int argc, char *argv[])
{
	int					pid;

	if (argc != 3)
		return (ft_printf("Error\n"));
	pid = ft_atoi(argv[1]);
	word_to_letters(pid, argv[2]);
}
