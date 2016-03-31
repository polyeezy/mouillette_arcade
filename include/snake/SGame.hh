//
// Snake.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include/snake
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar 15 14:29:37 2016 Valerian Polizzi
// Last update Wed Mar 30 15:27:36 2016 Miele Alexis
//

#ifndef _SGAME_HH_
# define _SGAME_HH_

# include <IGame.hpp>
# include <iostream>
# include <string>
# include <IMap.hh>
# include "ControllerManager.hh"
# include "SMap.hh"
# include "SEntity.hh"

# define SENTITY_SPEED  0.5
# define SENTITY_WIDTH  20
# define SENTITY_HEIGHT 20

class SGame : public IGame
{
private:
  SMap		*_map;
  SEntity	*_snake;
  IGraphicManager *_gm;
public:
  SGame();
  SGame(const std::string &);
  ~SGame();
  void		move(const ControllerManager::e_control);
  SMap&		getMap() const;
  void		play();
  void          setMap(const std::string&);
  void          setGM(IGraphicManager *);
  IGraphicManager *getGM();
};

#endif
