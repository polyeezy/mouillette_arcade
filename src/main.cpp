//
// main.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:54:52 2016 Valerian Polizzi
// Last update Tue Mar 15 14:40:52 2016 Valerian Polizzi
//

#include <caca.h>
#include <Launcher.hh>
#include <GameManager.hh>

int		main(int ac, char **av)
{
    Launcher	L;
   L.openLibrary(av[1]);
   L.init();
   L.run();
}
