/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:37 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/25 14:47:27 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	if (ft_strlen(argv[1]) == ft_strlen(ft_itoa(getpid())))
		ft_printf("messaggio ricevuto!");
	else
		ft_printf("errore, messaggio non inviato");
}
