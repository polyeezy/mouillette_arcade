//
// Menu.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:33:28 2016 Valerian Polizzi
// Last update Tue Mar  8 14:30:19 2016 Valerian Polizzi
//

#include <Menu.hh>
# include <iostream>

Menu::Menu()
{
  this->gm_active = 0;
  this->lm_active = 0;
}

Menu::~Menu()
{
}

void		Menu::addGame(const std::string &game)
{
  _games.push_back(new MenuItem(game));
}

void		Menu::nextGame()
{
  if (gm_active + 1 >= _games.size())
    gm_active = 1;
  else
    gm_active++;
}

size_t		Menu::getGameIndex() const
{
  return (this->gm_active);
}

size_t		Menu::getLibIndex() const
{
  return (this->lm_active);
}

void		Menu::nextLib()
{
  if (lm_active + 1 >= _libs.size())
    lm_active = 1;
  else
    lm_active++;
}

void		Menu::addLib(const std::string &game)
{
  MenuItem	*item = new MenuItem(game);

  _libs.push_back(item);
}

MenuItem	*Menu::getCurrentGame()
{
  return (_games[this->getGameIndex()]);
}

MenuItem	*Menu::getCurrentLib()
{
    return (_libs[this->getLibIndex()]);
}

void		Menu::print()
{

}
