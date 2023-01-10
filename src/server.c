/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarkoh <fsarkoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:31:14 by fsarkoh           #+#    #+#             */
/*   Updated: 2023/01/10 16:45:57 by fsarkoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	recieve_char(int sigid)
{
	static int	bitc = 0;
	static int	c = 0b00000000;

	if (sigid == SIGUSR2)
		c |= (0b00000001 << bitc);
	bitc++;
	if (bitc == 8)
	{
		ft_printf("%c", c);
		bitc = 0;
		c = 0b00000000;
	}
}

int	main(void)
{
	ft_printf("server pid: %i\n", getpid());
	signal(SIGUSR1, recieve_char);
	signal(SIGUSR2, recieve_char);
	while (1)
		pause();
}
