//
// main.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:54:52 2016 Valerian Polizzi
<<<<<<< HEAD
// Last update Sun Mar 20 15:31:37 2016 Alexis Miele
=======
// Last update Mon Mar 21 10:39:34 2016 Loïc Weinhard
>>>>>>> b1b5b6752bab8b9dedb2a885c98c2fa38d4504e1
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
