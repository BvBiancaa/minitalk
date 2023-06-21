/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:55:08 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/21 12:03:07 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin_m(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*ret;

	i = 0;
	n = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[n])
	{
		ret[i + n] = s2[n];
		n++;
	}
	ret[i + n] = '\0';
	return (ret);
}

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
		str = ft_strjoin_m(str, "0");
	else if (sig == SIGUSR1)
		str = ft_strjoin_m(str, "1");
	if (i == 8)
	{
		ft_convert_to_dec(str);
		free(str);
		str = NULL;
	}
}
