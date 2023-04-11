/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:13:28 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/07 15:08:47 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
	{
		write(1, "Inserisci il pid del server e la stringa da mandare!\n", 53);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
}
