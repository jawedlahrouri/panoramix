##
## EPITECH PROJECT, 2026
## my_ftp
## File description:
## Makefile for the FTP server
##

CC  =   gcc

VILLAGE_PATH =   src/village

SRC	=   src/main.c \
	$(VILLAGE_PATH)/village.c \
	$(VILLAGE_PATH)/villager.c \
	$(VILLAGE_PATH)/druid.c

OBJ         =   $(SRC:.c=.o)

NAME        =   panoramix

CFLAGS      =   -Wall -Wextra -Werror -I./include -pthread

all:    $(NAME)

$(NAME):    $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
