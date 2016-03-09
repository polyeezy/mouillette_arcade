//
// MenuItem.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:12:39 2016 Valerian Polizzi
// Last update Wed Mar  9 11:30:55 2016 Valerian Polizzi
//

#include <MenuItem.hh>

MenuItem::MenuItem(const std::string &name) :  _name(name)
{
}

MenuItem::~MenuItem()
{
}

const std::string	&MenuItem::getValue() const
{
  return (_name);
}

void		MenuItem::print()
{
}
