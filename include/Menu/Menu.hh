//
// Menu.hh for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:23:33 2016 Valerian Polizzi
// Last update Wed Mar 30 16:08:48 2016 Valerian Polizzi
//

#ifndef _MENU_HH_
# define _MENU_HH_

# include <map>
# include <vector>
# include <AEntity.hh>
# include <MenuItem.hh>

class Menu
{
private:
  std::vector<MenuItem*>	_games;
  std::vector<MenuItem*>	_libs;
  size_t			gm_active;
  size_t			lm_active;

public:
  Menu();
  ~Menu();
  void		addGame(const std::string &);
  void		addLib(const std::string &);
  MenuItem	*getCurrentGame();
  MenuItem	*getCurrentLib();
  size_t	getGameIndex() const;
  size_t	getLibIndex() const;
  void		nextGame();
  void		nextLib();
  void		print();
};

#endif
