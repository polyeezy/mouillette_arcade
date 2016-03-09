//
// map.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 12:18:21 2016 Loïc Weinhard
// Last update Wed Mar  9 14:50:37 2016 Loïc Weinhard
//

#include <algorithm>
#include <fstream>
#include "map.hh"

Map::Map(const std::string &file)
{
  std::ifstream		fd;
  std::string		path(MAPS_PATH);
  std::string		line;
  size_t		i;

  i = 0;
  path.append(file);
  fd.open(path.c_str());
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
	  _door.y = i;
	  _door.x = _map[i].find("P");
	}
      i += 1;
    }
  _last_gspawn.x = 0;
  _last_gspawn.y = 0;
}

char	Map::getPos(const arcade::Position pos) const
{
  return (_map[pos.y][pos.x]);
}

void	Map::deleteObj(const arcade::Position pos)
{
  if (_map[pos.y][pos.x] == '0')
    _gums -= 1;
  _map[pos.y][pos.x] = 'x';
}

void	Map::openCage()
{
  _map[_door.y][_door.x] = 'x';
}

void	Map::closeCage()
{
  _map[_door.y][_door.x] = 'P';
}

bool	Map::hasGums()
{
  if (_gums <= 0)
    return (false);
  return (true);
}

arcade::Position	Map::getPacmanSpawn()
{
  arcade::Position	pos;

  pos.x = _door.x;
  pos.y = _door.y + 1;
  return (pos);
}

arcade::Position	Map::getNextGhostSpawn()
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
