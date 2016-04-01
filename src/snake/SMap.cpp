//
// map.cpp for map in /home/miele_a/rendu/arcade/mouillette_arcade/src/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 15:48:57 2016 Miele Alexis
// Last update Fri Apr  1 10:50:20 2016 Miele Alexis
//

#include <unistd.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <algorithm>
#include <fstream>
#include "SMap.hh"

SMap::SMap(const std::string &file)
{
  //std::string		str;
  std::ifstream         fd;
  std::string           path(MAPS_PATH);
  std::string           line;
  size_t                i;

  i = 0;
  path.append(file);
  fd.open(path.c_str());
  if (fd.is_open())
    {
      while (std::getline(fd, line))
	{
	  _map.push_back(line);
	  while (_map[i].find(" ") != std::string::npos)
	    _map[i].erase(_map[i].find(" "), 1);
	  i += 1;
	}
      fd.close();
    }
  else
    std::cerr << "FAILED TO LOAD MAP" << std::endl;
  // i = 0;
  // str.insert(str.begin(), size, 'x');
  // while (++i <= size)
  //   _map.push_back(str);
}

char	SMap::getPos(const t_pos new_pos) const
{
  if (new_pos.y >= _map.size() || new_pos.y < 0)
    return (-1);
  else if (new_pos.x < 0 || new_pos.x >= _map[new_pos.y].size())
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

void    SMap::setElem(const t_pos pos, const char c)
{
  _map[pos.y][pos.x] = c;
}
