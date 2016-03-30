//
// MenuItem.hh for arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:07:16 2016 Valerian Polizzi
// Last update Wed Mar 30 16:09:18 2016 Valerian Polizzi
//

#ifndef _MENUITEM_HH_
# define _MENUITEM_HH_

# include <string>
# include <AEntity.hh>

class MenuItem
{
private:
  std::string		_name;
public:
  MenuItem(const std::string &name);
  ~MenuItem();
  void		print();
  const std::string	&getValue() const;
};

#endif
