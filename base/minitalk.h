/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:13:51 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/11 13:25:46 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/ft_printf.h"

void	ft_sig(int sig);
void	ft_convert_to_dec(char *s);
char	*ft_join(char *s, char c);
char	*ft_convert_to_bit(char *s, size_t pos);
void	ft_send_message(int pid, char *str);

#endif
