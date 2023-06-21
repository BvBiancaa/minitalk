/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:37 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/21 12:25:41 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*it;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
	{
		write(1, "Inserisci il pid del server e la stringa da mandare!\n", 53);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
	it = ft_itoa(getpid());
	if (ft_strlen(argv[1]) == ft_strlen(it))
		ft_printf("messaggio ricevuto!");
	else
		ft_printf("errore, messaggio non inviato");
	free(it);
}
