# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 12:16:39 by nsakanou          #+#    #+#              #
#    Updated: 2024/01/24 20:21:39 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_SRC = srcs/server.c
CLIENT_SRC = srcs/client.c srcs/minitalk_atoi.c

B_SERVER_SRC = bonus/server_bonus.c
B_CLIENT_SRC = bonus/client_bonus.c bonus/minitalk_atoi_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

B_SERVER_OBJ = $(B_SERVER_SRC:.c=.o)
B_CLIENT_OBJ = $(B_CLIENT_SRC:.c=.o)

# Printf+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
PRINTF_DIR	=	printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a


CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./printf
RM = rm -f

ifdef WITH_BONUS
	SERVER_OBJ = $(B_SERVER_OBJ)
	CLIENT_OBJ = $(B_CLIENT_OBJ)
endif

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(PRINTF)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ make -C $(PRINTF_DIR) clean
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(B_SERVER_OBJ) $(B_CLIENT_OBJ)
	
fclean: clean
	@ make -C $(PRINTF_DIR) fclean
	$(RM) $(SERVER) $(CLIENT)

bonus:
	make WITH_BONUS=1

re: fclean all

.PHONY: all clean fclean re

$(PRINTF):
	make -C $(PRINTF_DIR) all
