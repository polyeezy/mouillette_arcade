//
// main.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:54:52 2016 Valerian Polizzi
// Last update Mon Mar 21 16:33:31 2016 Miele Alexis
//


#include <caca.h>
#include <Launcher.hh>
#include <GameManager.hh>
#include "map.hh"
#include "PGame.hh"

void	Play()
{
  PGame	game("level_1.pacman");

  while (game.getMap().hasGums())
    {
      
    }
}

int		main(int ac, char **av)
{
  Launcher	L;


  (void)ac;
  (void)av;
  L.openLibrary(av[1]);
  L.init();
  L.run();
  Play();
  return (0);
}
