//
// main.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:54:52 2016 Valerian Polizzi
// Last update Wed Mar 16 14:11:15 2016 Loïc Weinhard
//

#include "map.hh"
#include <caca.h>
#include <Launcher.hh>
#include <GameManager.hh>

int		main(int ac, char **av)
{
  Launcher	L;
  Map		m("level_1.pacman");

  (void)ac;
  (void)av;
  L.openLibrary(av[1]);
  L.init();
  L.run();
}
