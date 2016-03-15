##
## Makefile for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade
##
## Made by Valerian Polizzi
## Login   <polyeezy@epitech.net>
##
## Started on  Mon Mar  7 14:22:01 2016 Valerian Polizzi
## Last update Tue Mar 15 18:00:21 2016 Valerian Polizzi
##

CXX		=		clang

NAME		=		arcade

SRC		=		src/main.cpp				\
				src/General/AEntity.cpp			\
				src/Menu/MenuItem.cpp			\
				src/Menu/Menu.cpp			\
				src/launcher/Launcher.cpp		\
				src/Manager/ScoreManager.cpp		\
				src/Manager/GameManager.cpp		\
				src/Manager/ControllerManager.cpp	\
				src/Manager/LibraryManager.cpp		\
				src/snake/Snake.cpp			\

OBJ		=		$(SRC:.cpp=.o)

LCACA_NAME	=		./lib/lib_arcade_caca.so

LCACA_SRC	=		lib/libcaca/GraphicManager.cpp		\

LCACA_OBJ	=		$(LCACA_SRC:.cpp=.o)

OPENGL_NAME	=		./lib/lib_arcade_opengl.so

OPENGL_SRC	=		lib/openGL/GraphicManager.cpp		\

OPENGL_OBJ	=		$(OPENGL_SRC:.cpp=.o)

LDFLAGS		+=		-ldl -L./lib
LDFLAGS		+=		-lX11  -lSDL -lGLU -lGL `sdl-config --cflags --libs`  -l_arcade_opengl

CXXFLAGS	+=		-fPIC -I./include -I./include/launcher -I./include/snake -I./include/pacman -std=c++11
CXXFLAGS	+=		-I./include/General -I./include/Manager -I./include/Menu -I./include/Libs

MR_CLEAN        =               find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:		$(OPENGL_NAME) $(NAME)

$(LCACA_NAME)	:		$(LCACA_OBJ)
				$(CXX) -shared -o $(LCACA_NAME) $(LCACA_OBJ)

$(OPENGL_NAME)	:		$(OPENGL_OBJ)
				$(CXX) -shared -o $(OPENGL_NAME) $(OPENGL_OBJ)

$(NAME)		:		$(OBJ)
				g++ $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)

clean		:
				$(MR_CLEAN)
				rm -f $(OBJ)
				rm -f $(LCACA_OBJ)
				rm -f $(OPENGL_OBJ)

fclean		:		clean
				rm -f $(NAME)
				rm -f $(LCACA_NAME)
				rm -f $(OPENGL_NAME)

re		:		clean all

.PHONY		:		all clean fclean re
