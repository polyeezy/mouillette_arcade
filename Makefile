##
## Makefile for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade
##
## Made by Valerian Polizzi
## Login   <polyeezy@epitech.net>
##
## Started on  Mon Mar  7 14:22:01 2016 Valerian Polizzi
<<<<<<< HEAD
## Last update Wed Mar 30 12:47:35 2016 Valerian Polizzi
=======
## Last update Wed Mar 30 00:01:54 2016 Miele Alexis
>>>>>>> cc1b1c664cc592ea150ee758cb495f611dd0a044
##

CXX		=		clang++

NAME		=		arcade

SRC		=		src/main.cpp				\
				src/General/AEntity.cpp			\
				src/Menu/MenuItem.cpp			\
				src/Menu/Menu.cpp			\
				src/launcher/Launcher.cpp		\
				src/Manager/ScoreManager.cpp		\
				src/Manager/ControllerManager.cpp	\
				src/Manager/LibraryManager.cpp		\
				src/pacman/map.cpp			\

OBJ		=		$(SRC:.cpp=.o)

LCACA_NAME	=		./lib/lib_arcade_caca.so

LCACA_SRC	=		lib/libcaca/CacaGraphicManager.cpp	\

LCACA_OBJ	=		$(LCACA_SRC:.cpp=.o)

SFML_NAME	=		./lib/lib_arcade_sfml.so

SFML_SRC	=		lib/SFML/sfmlGraphicManager.cpp	\

SFML_OBJ	=		$(SFML_SRC:.cpp=.o)

OPENGL_NAME	=		./lib/lib_arcade_opengl.so

OPENGL_SRC	=		./lib/openGL/openglGraphicManager.cpp		\

OPENGL_OBJ	=		$(OPENGL_SRC:.cpp=.o)

PACMAN_NAME	=		./games/pacman.so

PACMAN_SRC	=		./src/pacman/PGame.cpp		\
				./src/pacman/map.cpp		\
				./src/pacman/PEntity.cpp	\

PACMAN_OBJ	=		$(PACMAN_SRC:.cpp=.o)

SNAKE_NAME	=		./games/snake.so

SNAKE_SRC	=		./src/snake/SMap.cpp		\
				./src/snake/SEntity.cpp	\
				./src/snake/SGame.cpp		\

SNAKE_OBJ	=		$(SNAKE_SRC:.cpp=.o)

LDFLAGS		+=		-ldl -L./lib -L./lib/libcaca -lcaca1 -L/usr/local/lib

GLIBS		+=		-l_arcade_caca -l_arcade_opengl

CXXFLAGS	+=		-fPIC -I./include -I./include/launcher -I./include/snake -I./include/pacman -std=c++11
CXXFLAGS	+=		-I./include/General -I./include/Manager -I./include/Menu -I./include/Libs -I./lib/openGL
CXXFLAGS	+=		-Wall -Wextra -Werror -g3


MR_CLEAN        =               find ./ \( -name "*~" -o -name "\#*\#" \) -delete

all		:		$(OPENGL_NAME) $(LCACA_NAME) $(SFML_NAME) $(PACMAN_NAME) $(SNAKE_NAME) $(NAME)

core		:		$(NAME)

games		:		$(PACMAN_NAME) $(SNAKE_NAME)

libs		:		$(OPENGL_NAME) $(LCACA_NAME) $(SFML_NAME)

$(LCACA_NAME)	:		$(LCACA_OBJ)
				$(CXX) -shared -o $(LCACA_NAME) $(LCACA_OBJ) -lcaca1 -L./lib/libcaca

$(OPENGL_NAME)	:		$(OPENGL_OBJ)
				$(CXX) -shared -o $(OPENGL_NAME) $(OPENGL_OBJ) -lX11 `sdl-config --cflags --libs` -lSDL -lGL -lGLU

$(SFML_NAME)	:		$(SFML_OBJ)
						$(CXX) -shared -o $(SFML_NAME) $(SFML_OBJ) -L./lib/SFML -lsfml-graphics -lsfml-window -lsfml-system

$(PACMAN_NAME)	:		$(PACMAN_OBJ)
				$(CXX) -shared -o $(PACMAN_NAME) $(PACMAN_OBJ)

$(SNAKE_NAME)	:		$(SNAKE_OBJ)
				$(CXX) -shared -o $(SNAKE_NAME) $(SNAKE_OBJ)

$(NAME)		:		$(OBJ)
				g++ $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(GLIBS)

clean		:
				$(MR_CLEAN)
				rm -f $(OBJ)
				rm -f $(LCACA_OBJ)
				rm -f $(SFML_OBJ)
				rm -f $(OPENGL_OBJ)
				rm -f $(PACMAN_OBJ)
				rm -f $(SNAKE_OBJ)

fclean		:		clean
				rm -f $(NAME)
				rm -f $(LCACA_NAME)
				rm -f $(SFML_NAME)
				rm -f $(OPENGL_NAME)
				rm -f $(PACMAN_NAME)
				rm -f $(SNAKE_NAME)

re		:		clean all

.PHONY		:		all clean fclean re core libs games
