//
// Snake.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include/snake
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar 15 14:29:37 2016 Valerian Polizzi
// Last update Tue Mar 15 14:36:52 2016 Valerian Polizzi
//

#ifndef _SNAKE_HH_
# define _SNAKE_HH_

# include <IGame.hpp>
# include <iostream>
# include <string>

class Snake : public IGame
{
public:
  Snake();
  ~Snake();
  void play();
};

#endif
