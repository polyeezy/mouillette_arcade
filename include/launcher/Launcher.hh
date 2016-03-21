//
// Launcher.hh for arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:04:44 2016 Valerian Polizzi
// Last update Mon Mar 21 17:28:55 2016 Valerian Polizzi
//

#ifndef _LAUNCHER_HH_
# define _LAUNCHER_HH_

//# include <GameManager.hh>
# include <IGraphicManager.hh>
# include <ControllerManager.hh>
# include <LibraryManager.hh>
# include <AEntity.hh>
# include <Menu.hh>
# include <iostream>
# include <vector>
# include <dirent.h>

class Launcher : public AEntity
{
private:
  std::string		_name;
  Menu			_menu;
  ControllerManager	_cm;
  LibraryManager	_lm;
  IGame			*_currentGame;
  IGraphicManager	*_currentGM;
  //  GameManager		_gamem;
public:
  Launcher();
  ~Launcher();
  void		init();
  void		print();
  void		feedFromRepo(const std::string &repo);
  int		getKeys();
  void		nextGame();
  void		nextLib();
  void		createWindow(const std::string &,const int, const int);
  void		openLibrary(const std::string &);
  void		run();
};

#endif
