##
## Makefile for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade
##
## Made by Valerian Polizzi
## Login   <polyeezy@epitech.net>
##
## Started on  Mon Mar  7 14:22:01 2016 Valerian Polizzi
## Last update Thu Mar 17 14:55:32 2016 Valerian Polizzi
##

CXX		=		clang++

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
				src/pacman/map.cpp			\

OBJ		=		$(SRC:.cpp=.o)

LCACA_NAME	=		./lib/lib_arcade_caca.so

LCACA_SRC	=		lib/libcaca/CacaGraphicManager.cpp	\

LCACA_OBJ	=		$(LCACA_SRC:.cpp=.o)

OPENGL_NAME	=		./lib/lib_arcade_opengl.so

OPENGL_SRC	=		./lib/openGL/openglGraphicManager.cpp		\

OPENGL_OBJ	=		$(OPENGL_SRC:.cpp=.o)

LDFLAGS		+=		-ldl -L./lib -L./lib/libcaca -lcaca1

GLIBS		+=		-l_arcade_caca -l_arcade_opengl

CXXFLAGS	+=		-fPIC -I./include -I./include/launcher -I./include/snake -I./include/pacman -std=c++11
CXXFLAGS	+=		-I./include/General -I./include/Manager -I./include/Menu -I./include/Libs -I./lib/openGL
CXXFLAGS	+=		-Wall -Wextra -Werror


MR_CLEAN        =               find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:		$(OPENGL_NAME) $(LCACA_NAME) $(NAME)

$(LCACA_NAME)	:		$(LCACA_OBJ)
				$(CXX) -shared -o $(LCACA_NAME) $(LCACA_OBJ) -lcaca1 -L./lib/libcaca

$(OPENGL_NAME)	:		$(OPENGL_OBJ)
				$(CXX) -shared -o $(OPENGL_NAME) $(OPENGL_OBJ) -lX11 `sdl-config --cflags --libs` -lSDL -lGL -lGLU

$(NAME)		:		$(OBJ)
				g++ $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(GLIBS)

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
