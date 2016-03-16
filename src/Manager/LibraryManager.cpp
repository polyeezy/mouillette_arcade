//
// LibraryManager.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar 14 13:54:30 2016 Valerian Polizzi
// Last update Wed Mar 16 14:15:49 2016 Loïc Weinhard
//

#include <LibraryManager.hh>

LibraryManager::LibraryManager() : _dlhandle(NULL)
{
}

LibraryManager::~LibraryManager()
{
  if (_dlhandle)
    this->close();
}

void		LibraryManager::open(const std::string &path)
{
  _dlhandle = dlopen(path.c_str(), RTLD_LAZY);
  std::cout << path << " | ta mère la grosse pute \n" << std::endl;
  if (!_dlhandle)
    {
      std::cout << "wrong lib" << std::endl;
      exit(0);
    }
}

void		*LibraryManager::getHandle()
{
  return (_dlhandle);
}

GraphicManager	*LibraryManager::createGM()
{
  GraphicManager     *(*GMcreator)();
  GMcreator = reinterpret_cast<GraphicManager*(*)()>(dlsym(_dlhandle, "createGraphicManager"));
  if (GMcreator == NULL)
    {
      std::cout << "error on creating create GM" << std::endl;
      exit(0);
    }
  GraphicManager *rtn = GMcreator();
  return (rtn);
}

void		LibraryManager::close()
{
  dlclose(_dlhandle);
  _dlhandle = NULL;
}
