##
## Makefile for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
## 
## Made by Loïc Weinhard
## Login   <weinha_l@epitech.net>
## 
## Started on  Mon Mar  7 17:52:15 2016 Loïc Weinhard
## Last update Tue Mar 15 16:00:39 2016 Valerian Polizzi
##

SRC		=	main.cpp	\
			map.cpp		\
			PEntity.cpp	\
			../AEntity.cpp	\
			PGame.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME		=	pacman_nographics

CPPFLAGS	+=	-Wall -Werror -Wextra -std=c++11
CPPFLAGS	+=	-I../../include/
CPPFLAGS	+=	-I../../include/pacman
LDFLAGS		+=	-lX11 -lGL -lGLU -lSDL `sdl-config --cflags --libs`

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			g++ $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		:	all re clean fclean
