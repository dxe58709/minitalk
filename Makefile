# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 12:16:39 by nsakanou          #+#    #+#              #
#    Updated: 2023/08/20 16:45:04 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c minitalk_atoi.c

B_SERVER_SRC = server_bonus.c
B_CLIENT_SRC = client_bonus.c minitalk_atoi_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

B_SERVER_OBJ = $(B_SERVER_SRC:.c=.o)
B_CLIENT_OBJ = $(B_CLIENT_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

ifdef WITH_BONUS
	SERVER_OBJ += $(B_SERVER_OBJ)
	CLIENT_OBJ += $(B_CLIENT_OBJ)
endif

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(B_SERVER_OBJ) $(B_CLIENT_OBJ)
	
fclean: clean
	$(RM) $(SERVER) $(CLIENT)

bonus:
	make WITH_BONUS=1

re: fclean all

.PHONY: all clean fclean re
