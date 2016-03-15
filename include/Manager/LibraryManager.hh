//
// LibraryManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar 14 13:52:29 2016 Valerian Polizzi
// Last update Mon Mar 14 15:53:07 2016 Valerian Polizzi
//

#ifndef _LIBRARYMANAGER_HH_
# define _LIBRARYMANAGER_HH_

# include <iostream>
# include <string>
# include <dlfcn.h>
# include <ControllerManager.hh>
# include <GraphicManager.hh>

class LibraryManager
{
private:
  void	*_dlhandle;
public:
  LibraryManager();
  ~LibraryManager();
  GraphicManager *createGM();

  void		*getHandle();
  void		open(const std::string &);
  void		close();
};

#endif
