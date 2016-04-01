//
// LibraryManager.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar 14 13:54:30 2016 Valerian Polizzi
// Last update Fri Apr  1 10:54:30 2016 Valerian Polizzi
//

#include <LibraryManager.hh>
#include <IGraphicManager.hh>
#include <ArcadeException.hh>

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
  _dlhandle = dlopen(path.c_str(), RTLD_LAZY | RTLD_NOW);
  if (!_dlhandle)
    {
      throw arcade::Exception(dlerror());
    }
}

void		*LibraryManager::getHandle()
{
  return (_dlhandle);
}

IGraphicManager	*LibraryManager::createGM()
{
  IGraphicManager     *(*GMcreator)();

  GMcreator = reinterpret_cast<IGraphicManager*(*)()>(dlsym(_dlhandle, "createGraphicManager"));
  if (GMcreator == NULL)
    {
      std::cout << "error on creating create GM" << std::endl;
      exit(0);
    }
  IGraphicManager *rtn = GMcreator();
  return (rtn);
}

IGame		*LibraryManager::createGame()
{
  IGame     *(*gameCreator)();

  gameCreator = reinterpret_cast<IGame*(*)()>(dlsym(_dlhandle, "createIGame"));
  if (gameCreator == NULL)
    {
      std::cout << "error on creating create IGame" << std::endl;
      exit(0);
    }
  return (gameCreator());
}

void		LibraryManager::close()
{
  dlclose(_dlhandle);
   _dlhandle = NULL;
}
