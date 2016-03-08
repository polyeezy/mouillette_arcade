##
## Makefile for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
## 
## Made by Loïc Weinhard
## Login   <weinha_l@epitech.net>
## 
## Started on  Mon Mar  7 17:52:15 2016 Loïc Weinhard
## Last update Mon Mar  7 17:55:35 2016 Loïc Weinhard
##

SRC	=	main.cpp

OBJ	=	$(SRC:.c=.o)

NAME	=	pacman_nographics

CFLAGS	+=	-Wall -Werror -Wextra

$(NAME)	:	$(OBJ)

all	:	$(NAME)
		g++ $(OBJ) -o $(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all re clean fclean
