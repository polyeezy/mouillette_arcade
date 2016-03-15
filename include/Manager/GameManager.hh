//
// GameManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar 15 13:54:33 2016 Valerian Polizzi
// Last update Tue Mar 15 14:40:14 2016 Valerian Polizzi
//

#ifndef _GAMEMANAGER_HH_
# define _GAMEMANAGER_HH_

# include <Snake.hh>
# include <string>
# include <iostream>
# include <IGame.hpp>
# include <map>

class GameManager
{
private:
  std::map<const std::string, IGame*>	_games;
public:
  GameManager();
  ~GameManager();
  void	play(const std::string &);
};

#endif
