//
// main.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:54:52 2016 Valerian Polizzi
// Last update Mon Mar 21 18:13:45 2016 Loïc Weinhard
//


#include <caca.h>
#include <Launcher.hh>
#include "map.hh"
#include "PGame.hh"

int		main(int ac, char **av)
{
  Launcher	L;


  (void)ac;
  (void)av;
  L.openLibrary(av[1]);
  L.init();
  L.run();
  return (0);
}
