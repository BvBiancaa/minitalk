/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:10:51 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/25 14:36:03 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H

# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/ft_printf.h"

void	ft_sig(int sig);
void	ft_convert_to_dec(char *s);
void	ft_send_message(int pid, char *str);

#endif
