##
## Makefile for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade
## 
## Made by Valerian Polizzi
## Login   <polyeezy@epitech.net>
## 
## Started on  Mon Mar  7 14:22:01 2016 Valerian Polizzi
## Last update Wed Mar  9 10:27:47 2016 Valerian Polizzi
##

NAME		=		arcade

SRC		=		src/main.cpp		\
				src/AEntity.cpp		\
				src/MenuItem.cpp	\
				src/Menu.cpp		\
				src/launcher/Launcher.cpp	\
				src/GraphicManager.cpp		\
				src/ControllerManager.cpp	\

OBJ		=		$(SRC:.cpp=.o)


LDFLAGS		+=		-lcaca

CPPFLAGS	+=		-W -Werror -Wextra -I./include -I./include/launcher -std=c++11

MR_CLEAN        =               find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				g++ $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)

clean		:
				$(MR_CLEAN)
				rm -f $(OBJ)

fclean		:		clean
				rm -f $(NAME)

re		:		clean all

.PHONY		:		all clean fclean re
