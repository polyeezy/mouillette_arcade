//
// IGraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include/Manager
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Wed Mar 16 15:04:24 2016 Valerian Polizzi
// Last update Thu Mar 17 13:54:09 2016 Valerian Polizzi
//

#ifndef _IGRAPGHICMANAGER_HH_
# define _IGRAPGHICMANAGER_HH_

#include <string>

class IGraphicManager
{
public:
  virtual void	createWindow(const std::string &) = 0;
  virtual void	refresh() = 0;
  virtual void	createSurface(const int, const int, const int, const int, const std::string &) = 0;
  virtual void	addTextToSurface(const std::string &, const int, const int, const std::string&) = 0;
  virtual int	getKey() const = 0;
  virtual void	*getWindow() = 0;
};

#endif