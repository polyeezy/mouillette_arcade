//
// main.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Mon Mar  7 17:47:11 2016 Loïc Weinhard
// Last update Tue Mar 15 15:37:56 2016 Loïc Weinhard
//

#include <unistd.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "PEntity.hh"
#include "PGame.hh"
#include "map.hh"

int	main()
{
  PGame		game("level_1.pacman");
  SDL_Surface	*window;
  SDL_Event	events;
  bool		flag;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_SetVideoMode(1920, 1080, 32, SDL_OPENGL);
  (void)window;
  SDL_WM_SetCaption("Pacman", NULL);
  SDL_Flip(window);
  flag = true;
  while (flag)
    {
      while (SDL_PollEvent(&events))
	{
	  switch (events.type)
	    {
	    case SDL_KEYDOWN:
	      printf("Key pressed\n");
	      break;
	    case SDL_QUIT:
	      flag = false;
	      break;
	    };
	  game.getMap().print();
	}
    }
  SDL_Quit();
  return (0);
}
