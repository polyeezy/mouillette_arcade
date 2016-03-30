//
// map.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
//
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
//
// Started on  Tue Mar  8 12:18:21 2016 Loïc Weinhard
// Last update Wed Mar 30 16:23:12 2016 Valerian Polizzi
//

#include <unistd.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <algorithm>
#include <fstream>
#include "PMap.hh"

PMap::PMap(const std::string &file)
{
  std::ifstream		fd;
  std::string		path(MAPS_PATH);
  std::string		line;
  size_t		i;

  i = 0;
  std::cout << file << std::endl;
  path.append(file);
  fd.open(path.c_str());
  if (!fd.is_open())
    {
      std::cout << path << std::endl;
      return;
    }
  while (std::getline(fd, line))
    {
      _map.push_back(line);
      while (_map[i].find(" ") != std::string::npos)
	_map[i].erase(_map[i].find(" "), 1);
      i += 1;
    }
  fd.close();
  i = 0;
  _gums = 0;
  while (i < _map.size())
    {
      _gums += std::count(_map[i].begin(), _map[i].end(), '0');
      if (_map[i].find("P") != std::string::npos)
	{
	  _door.y = (float)i;
	  _door.x = (float)_map[i].find("P");
	}
      i += 1;
    }
  _last_gspawn.x = 0;
  _last_gspawn.y = 0;
}

char	PMap::getPos(const t_pos new_pos) const
{
  if (new_pos.y >= _map.size())
    return (-1);
  else if (new_pos.x >= _map[new_pos.y].size())
    return (-2);
  return (_map[new_pos.y][new_pos.x]);
}

void	PMap::deleteObj(const t_pos pos)
{
  if (_map[pos.y][pos.x] == '0')
    _gums -= 1;
  _map[pos.y][pos.x] = 'x';
}

void	PMap::openCage()
{
  _map[_door.y][_door.x] = 'x';
}

void	PMap::closeCage()
{
  _map[_door.y][_door.x] = 'P';
}

bool	PMap::hasGums()
{
  if (_gums <= 0)
    return (false);
  return (true);
}

t_pos	PMap::getPacmanSpawn()
{
  t_pos	pos;

  pos.x = _door.x;
  pos.y = _door.y + 1;
  return (pos);
}

t_pos	PMap::getNextGhostSpawn()
{
  if (_map[_last_gspawn.y].find("G", _last_gspawn.x + 1) != std::string::npos)
    {
      _last_gspawn.x = _map[_last_gspawn.y].find("G", _last_gspawn.x + 1);
      return (_last_gspawn);
    }
  _last_gspawn.y += 1;
  while (_map[_last_gspawn.y].find("G") == std::string::npos)
    {
      _last_gspawn.y += 1;
      if (_last_gspawn.y >= _map.size())
	_last_gspawn.y = 0;
    }
  _last_gspawn.x = _map[_last_gspawn.y].find("G");
  return (_last_gspawn);
}

size_t	PMap::getSize() const
{
    return (_map.size());
}

void		PMap::print()
{
}
