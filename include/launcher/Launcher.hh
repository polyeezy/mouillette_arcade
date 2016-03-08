//
// Launcher.hh for arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:04:44 2016 Valerian Polizzi
// Last update Tue Mar  8 10:05:09 2016 Valerian Polizzi
//

#ifndef _LAUNCHER_HH_
# define _LAUNCHER_HH_

# include <AEntity.hh>
# include <Menu.hh>
# include <iostream>
# include <vector>
# include <dirent.h>

class Launcher : public AEntity
{
private:
  Menu		_menu;
public:
  Launcher();
  ~Launcher();
  void		print();
  void		feedFromRepo(const std::string &repo);
  void		getKeys();
  void		nextGame();
  void		nextLib();
};

#endif
