//
// LibraryManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar 14 13:52:29 2016 Valerian Polizzi
// Last update Fri Apr  1 15:14:58 2016 Valerian Polizzi
//

#ifndef _LIBRARYMANAGER_HH_
# define _LIBRARYMANAGER_HH_

# include <iostream>
# include <string>
# include <dlfcn.h>
# include <ControllerManager.hh>
# include <IGraphicManager.hh>
# include <IGame.hpp>
# include <ArcadeException.hh>

class LibraryManager
{
private:
  void	*_dlhandle;
public:
  LibraryManager();
  ~LibraryManager();
  IGraphicManager	*createGM();
  IGame			*createGame();
  void		*getHandle();
  void		open(const std::string &);
  void		close();
};

#endif
