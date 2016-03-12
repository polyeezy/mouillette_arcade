//
// main.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Mon Mar  7 17:47:11 2016 Loïc Weinhard
// Last update Sat Mar 12 15:57:23 2016 Loïc Weinhard
//

#include <unistd.h>
#include "PEntity.hh"
#include "PGame.hh"
#include "map.hh"

int	main()
{
  PGame	game("level_1.pacman");

  while (42)
    {
      game.move(UP);
      game.getMap().print();
      sleep(1);
    }
  return (0);
}
