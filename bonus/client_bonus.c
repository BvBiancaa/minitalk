/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:37 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/25 15:22:46 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int argc, char **argv)
{
	int	pid;
	char	*s;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
	{
		write(1, "Inserisci il pid del server e la stringa da mandare!\n", 53);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
	//s = malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
	s = ft_itoa(getpid());
	if (ft_strlen(argv[1]) == ft_strlen(s))
	{
		free(s);
		ft_printf("messaggio ricevuto!");
	}
	else
	{
		ft_printf("errore, messaggio non inviato");
		free(s);
	}
}
