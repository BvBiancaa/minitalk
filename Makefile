# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bianca <bianca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 23:14:00 by bmuni             #+#    #+#              #
#    Updated: 2023/06/21 12:31:01 by bianca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: server client

bonus: server_bonus client_bonus

server:
	make -C libftprintf
	gcc -g -Wall -Wextra -Werror base/server.c base/utils.c libftprintf/libftprintf.a -o server

client:
	make -C libftprintf
	gcc -g -Wall -Wextra -Werror base/client.c base/utils.c libftprintf/libftprintf.a -o client

server_bonus:
	make -C libftprintf
	gcc -g -Wall -Wextra -Werror bonus/utils_bonus.c bonus/server_bonus.c libftprintf/libftprintf.a -o server

client_bonus:
	make -C libftprintf
	gcc -g -Wall -Wextra -Werror bonus/utils_bonus.c bonus/client_bonus.c libftprintf/libftprintf.a -o client

clean:
	make -C libftprintf clean

fclean: clean
	rm -f server client
	make -C libftprintf fclean

re: fclean all

.PHONY: all bonus clean fclean re
