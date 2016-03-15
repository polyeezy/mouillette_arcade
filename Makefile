##
## Makefile for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade
##
## Made by Valerian Polizzi
## Login   <polyeezy@epitech.net>
##
## Started on  Mon Mar  7 14:22:01 2016 Valerian Polizzi
## Last update Tue Mar 15 14:34:41 2016 Valerian Polizzi
##

CXX		=		g++

NAME		=		arcade

SRC		=		src/main.cpp		\
				src/AEntity.cpp		\
				src/MenuItem.cpp	\
				src/Menu.cpp		\
				src/launcher/Launcher.cpp	\
				src/ScoreManager.cpp		\
				src/LibraryManager.cpp		\
				src/ControllerManager.cpp	\
				src/GameManager.cpp		\
				src/snake/Snake.cpp		\


OBJ		=		$(SRC:.cpp=.o)

LCACA_NAME	=		./lib/lib_arcade_caca.so

LCACA_SRC	=		lib/libcaca/GraphicManager.cpp		\

LCACA_OBJ	=		$(LCACA_SRC:.cpp=.o)

LDFLAGS		+=		-ldl -lcaca -L./lib -l_arcade_caca

CXXFLAGS	=		-fPIC -I./include -I./include/launcher -I./include/snake -std=c++11

MR_CLEAN        =               find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:		$(LCACA_NAME) $(NAME)

$(LCACA_NAME)	:		$(LCACA_OBJ)
				$(CXX) -shared -o $(LCACA_NAME) $(LCACA_OBJ)

$(NAME)		:		$(OBJ)
				g++ $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)

clean		:
				$(MR_CLEAN)
				rm -f $(OBJ) $(LCACA_NAME)

fclean		:		clean
				rm -f $(NAME)

re		:		clean all

.PHONY		:		all clean fclean re
