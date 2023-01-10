/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:52:51 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/10 16:48:37 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

static void	send_char(int pid, int c)
{
	int	biti;

	biti = 0;
	while (biti < 8)
	{
		kill(pid, SIGUSR1 + ((c >> biti) & 0b00000001));
		biti++;
		usleep(100);
	}
}

static void	send_str(int pid, char *str)
{	
	unsigned int	offset;
	unsigned int	sentch;

	offset = 0;
	sentch = 0;
	while (*(str + offset))
	{
		send_char(pid, *(str + offset));
		offset++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(*(argv + 2)))
		return (1);
	send_str(ft_atoi(*(argv + 1)), *(argv + 2));
	return (0);
}
