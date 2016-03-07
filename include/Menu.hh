//
// Menu.hh for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:23:33 2016 Valerian Polizzi
// Last update Mon Mar  7 18:04:03 2016 Valerian Polizzi
//

#ifndef _MENU_HH_
# define _MENU_HH_

# include <map>
# include <vector>
# include <AEntity.hh>
# include <MenuItem.hh>

class Menu : public AEntity
{
private:
  std::vector<MenuItem*>	_games;
  std::vector<MenuItem*>	_libs;
public:
  Menu();
  ~Menu();
  void		addGame(const std::string &);
  void		addLib(const std::string &);
  void		print();
};

#endif
