/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:55:08 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/25 14:52:24 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void	ft_send_message(int pid, char *str)
{
	int	i;

	i = 0;
	str = ft_convert_to_bit(str, 0);
	while (str[i])
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(190);
	}
}*/

void	ft_send_message(int pid, char *str)
{
	int	bit;
	int	i;

	i = 0;
	while (*str)
	{
		bit = 8;
		i = *str++;
		while (bit--)
		{
			if (i >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(190);
		}
	}
}

void	ft_convert_to_dec(char *s)
{
	int				pos;
	unsigned char	c;
	size_t			i;
	int				p;

	pos = 1;
	c = 0;
	i = ft_strlen(s);
	p = 8;
	while (i > 0)
	{
		while (--p >= 0)
		{
			c += pos * (s[p] - 48);
			pos *= 2;
		}
		i -= 8;
		p = 8;
	}
	ft_printf("%c", c);
}

void	ft_sig(int sig)
{
	static char	*str;
	static int	i;

	i++;
	if (str == NULL)
	{
		str = ft_strdup("");
		i = 1;
	}
	if (sig == SIGUSR2)
		str = ft_strjoin(str, "0");
	else if (sig == SIGUSR1)
		str = ft_strjoin(str, "1");
	if (i == 8)
	{
		ft_convert_to_dec(str);
		free(str);
		str = NULL;
	}
}
