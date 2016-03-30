//
// map.cpp for map in /home/miele_a/rendu/arcade/mouillette_arcade/src/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 15:48:57 2016 Miele Alexis
// Last update Tue Mar 29 18:39:44 2016 Miele Alexis
//

#include <unistd.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <algorithm>
#include <fstream>
#include "SMap.hh"

SMap::SMap(const size_t &size)
{
  size_t		i;
  std::string		str;

  i = 0;
  str.insert(str.begin(), size, 'x');
  while (++i <= size)
    _map.push_back(str);
}

char	SMap::getPos(const t_pos new_pos) const
{
  if (new_pos.y >= _map.size())
    return (-1);
  else if (new_pos.x >= _map[new_pos.y].size())
    return (-2);
  return (_map[new_pos.y][new_pos.x]);
}

void	SMap::deleteObj(const t_pos pos)
{
  _map[pos.y][pos.x] = 'x';
}

t_pos	SMap::getSpawn()
{
  t_pos	pos;

  pos.x = rand() % _map.size();
  pos.y = rand() % _map.size();
  return (pos);
}

size_t	SMap::getSize() const
{
    return (_map.size());
}

void		SMap::print()
{
}

void	SMap::setGum(const SEntity *snake)
{
  t_pos	pos;
  t_pos snakePos = snake->getPos();
  std::vector<t_snakebody*> body;

  pos.x = rand() % _map.size();
  pos.y = rand() % _map.size();
  if (pos.x == snakePos.x && pos.y == snakePos.y)
    this->setGum(snake);
  for (size_t i = 0; i < body.size(); i++)
    {
      if (body[i]->pos.x == pos.x && body[i]->pos.y == pos.y)
	this->setGum(snake);
    }
  _map[pos.y][pos.x] = '0';
}
