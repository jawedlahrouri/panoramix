##
## EPITECH PROJECT, 2026
## my_ftp
## File description:
## Makefile for the FTP server
##

CC  =   gcc

SRC	=   src/main.c \

OBJ         =   $(SRC:.c=.o)

NAME        =   panoramix

CFLAGS      =   -Wall -Wextra -Werror -I./include

all:    $(NAME)

$(NAME):    $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
