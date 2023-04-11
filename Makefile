# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuni <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 23:14:00 by bmuni             #+#    #+#              #
#    Updated: 2022/11/25 14:45:45 by bmuni            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: server client

bonus: server_bonus client_bonus

server:
	make -C libftprintf
	gcc -Wall -Wextra -Werror base/server.c base/utils.c libftprintf/libftprintf.a -o server

client:
	make -C libftprintf
	gcc -Wall -Wextra -Werror base/client.c base/utils.c libftprintf/libftprintf.a -o client

server_bonus:
	make -C libftprintf
	gcc -Wall -Wextra -Werror bonus/utils_bonus.c bonus/server_bonus.c libftprintf/libftprintf.a -o server

client_bonus:
	make -C libftprintf
	gcc -Wall -Wextra -Werror bonus/utils_bonus.c bonus/client_bonus.c libftprintf/libftprintf.a -o client

clean:
	make -C libftprintf clean

fclean: clean
	rm -f server client
	make -C libftprintf fclean

re: fclean all

.PHONY: all bonus clean fclean re
