##
## Makefile for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade
## 
## Made by Valerian Polizzi
## Login   <polyeezy@epitech.net>
## 
## Started on  Mon Mar  7 14:22:01 2016 Valerian Polizzi
## Last update Mon Mar  7 18:15:39 2016 Valerian Polizzi
##

NAME		=		arcade

SRC		=		src/main.cpp		\
				src/AEntity.cpp		\
				src/MenuItem.cpp	\
				src/Menu.cpp		\
				src/launcher/Launcher.cpp	\

OBJ		=		$(SRC:.cpp=.o)

CPPFLAGS	+=		-W -Werror -Wextra -I./include -I./include/launcher -std=c++11

MR_CLEAN        =               find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				g++ $(OBJ) -o $(NAME) $(CPPFLAGS)

clean		:
				$(MR_CLEAN)
				rm -f $(OBJ)

fclean		:
				rm -f $(NAME)

re		:		clean all

.PHONY		:		all clean fclean re
