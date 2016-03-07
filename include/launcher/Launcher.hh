//
// Launcher.hh for arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:04:44 2016 Valerian Polizzi
// Last update Mon Mar  7 18:04:10 2016 Valerian Polizzi
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
};

#endif
