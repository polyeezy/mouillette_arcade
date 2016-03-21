//
// LibraryManager.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar 14 13:54:30 2016 Valerian Polizzi
// Last update Mon Mar 21 15:28:31 2016 Alexis Miele
//

#include <LibraryManager.hh>
#include <IGraphicManager.hh>

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
      std::cout << dlerror() << std::endl;
      exit(0);
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

void		LibraryManager::close()
{
  dlclose(_dlhandle);
  _dlhandle = NULL;
}
