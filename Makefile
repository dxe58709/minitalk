# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 12:16:39 by nsakanou          #+#    #+#              #
#    Updated: 2023/07/31 15:28:12 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c src/minitalk_atoi.c

HEADER = includes

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = $(SERVER) $(CLIENT)

all : $(NAME)

$(SERVER) : $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	
fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re

