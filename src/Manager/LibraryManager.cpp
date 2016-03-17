//
// LibraryManager.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar 14 13:54:30 2016 Valerian Polizzi
<<<<<<< HEAD
// Last update Thu Mar 17 13:57:32 2016 Valerian Polizzi
=======
// Last update Wed Mar 16 14:15:49 2016 Loïc Weinhard
>>>>>>> 3e8c6bd7400d76bb94b1c6b2fcadb99f05836159
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
<<<<<<< HEAD
  _dlhandle = dlopen(path.c_str(), RTLD_LAZY | RTLD_NOW);
=======
  _dlhandle = dlopen(path.c_str(), RTLD_LAZY);
  std::cout << path << " | ta mère la grosse pute \n" << std::endl;
>>>>>>> 3e8c6bd7400d76bb94b1c6b2fcadb99f05836159
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
