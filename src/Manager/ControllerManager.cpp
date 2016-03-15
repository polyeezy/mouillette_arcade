//
// ControllerManager.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Wed Mar  9 10:05:59 2016 Valerian Polizzi
// Last update Tue Mar 15 17:48:34 2016 Valerian Polizzi
//

#include <ControllerManager.hh>
#include <caca.h>

ControllerManager::ControllerManager()
{
}

ControllerManager::~ControllerManager()
{
}

void		ControllerManager::importConf()
{
  std::ifstream is(CM_CONF_PATH);
  std::string	line;
  int		key;
  int		value;

  std::cout << CM_CONF_PATH << std::endl;
  while (std::getline(is, line))
    {
      std::stringstream ss(line);
      ss >> key >> value;
      std::cout << key << " " << value << std::endl;
      this->mapKey(key, value);
    }
}

void		ControllerManager::exportConf()
{
  std::ofstream	file(_path.c_str());

  for (std::map<int, int>::iterator it = _key_map.begin(); it != _key_map.end(); it++)
    {
       file << it->first << " " << it->second << '\n';
    }
}

void		ControllerManager::setConfPath(const std::string &path)
{
  _path = path;
}

void		ControllerManager::mapKey(const int key, const int value)
{
  _key_map[value] = key;
}
