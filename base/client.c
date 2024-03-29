/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:13:28 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/21 11:55:02 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
	{
		write(1, "Insert a valid pid and the string to send!\n", 53);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
}
