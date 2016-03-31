//
// IGame.hpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar 15 14:18:29 2016 Valerian Polizzi
// Last update Thu Mar 31 12:48:23 2016 Valerian Polizzi
//

#ifndef _IGAME_HPP
# define _IGAME_HPP
# include <IMap.hh>
# include <IGraphicManager.hh>
# include <ControllerManager.hh>
# include <string>

class IGame
{
public:
  virtual IMap &getMap() const = 0;
  virtual void setMap(const std::string&) = 0;
  virtual void setGM(IGraphicManager*) = 0;
  virtual void move(const int) = 0;
  virtual void play() = 0;
  virtual IGraphicManager *getGM() = 0;
};


#endif
