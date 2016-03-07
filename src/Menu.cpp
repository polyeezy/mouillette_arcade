//
// Menu.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:33:28 2016 Valerian Polizzi
// Last update Mon Mar  7 18:00:29 2016 Valerian Polizzi
//

#include <Menu.hh>
# include <iostream>

Menu::Menu()
{
}

Menu::~Menu()
{
}

void		Menu::addGame(const std::string &game)
{
  _games.push_back(new MenuItem(game));
}

void		Menu::addLib(const std::string &game)
{
  std::cout << _libs.size() << std::endl;
  MenuItem	*item = new MenuItem(game);

  _libs.push_back(item);
}

void		Menu::print()
{

}
