//
// Launcher.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:41:57 2016 Valerian Polizzi
// Last update Thu Mar 24 12:51:17 2016 Valerian Polizzi
//

#include <Launcher.hh>

Launcher::Launcher()
{

}

void		Launcher::openLibrary(const std::string &lib)
{
  _lm.open(lib);
  this->_currentGM = _lm.createGM();
  //_lm.close();
}

void		Launcher::init()
{
  this->_cm.importConf();
}

void		Launcher::run()
{

  this->feedFromRepo("lib");
  this->feedFromRepo("games");

  _currentGM->createWindow("Arcade");
  _currentGM->printMenu(_menu.getCurrentGame()->getValue(), _menu.getCurrentLib()->getValue(), _name);
   this->getKeys();
}

Launcher::~Launcher()
{
}

void		Launcher::feedFromRepo(const std::string &repo)
{
  DIR			*dir = NULL;
  struct dirent		*ent = NULL;

  if ((dir = opendir(repo.c_str())) != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	{
	  std::string	file(ent->d_name);

	  if (repo.compare("games") == 0 && file.substr(file.find_last_of(".") + 1) == "so")
	    _menu.addGame(file);
	    else if (repo.compare("lib") == 0 && file.substr(file.find_last_of(".") + 1) == "so")
	    _menu.addLib(file);
	}
      closedir(dir);
    }
  else
    std::cout << "repo " << repo << "not found" << std::endl;
}

int		Launcher::getKeys()
{

  int		c = 0;

 _currentGM->refresh();
  while (c != ControllerManager::ESCAPE)
    {
      c = _currentGM->getKey();
      switch(c)
	{
	case ControllerManager::RIGHT:
	  this->nextGame();
	  std::cout << "[RIGHT]" << std::endl;
	  break;
	case ControllerManager::UP:
	  std::cout << "[UP]" << std::endl;
	  this->nextLib();
	  break;
	case ControllerManager::LEFT:
	  std::cout << "[LEFT]" << std::endl;
	  this->nextGame();
	  break;
	case ControllerManager::DOWN:
	  std::cout << "[DOWN]" << std::endl;
	  this->nextLib();
	  break;
	case ControllerManager::ACTION:
	  std::cout << "[ACTION]" << std::endl;
	  std::cout << "[USING " << _menu.getCurrentLib()->getValue()  << " AS LIB ]"   << std::endl;
	  std::cout << "[USING " << _menu.getCurrentGame()->getValue()  << " AS GAME ]"   << std::endl;
	  _lm.close();
	  _lm.open(std::string("./lib/").append(_menu.getCurrentLib()->getValue()));
	  _currentGM = _lm.createGM();
	  std::cout << "Graphic Manager created " << std::endl;
	  _lm.close();
	  _lm.open(std::string("./games/").append(_menu.getCurrentGame()->getValue()));
	  _currentGame = _lm.createGame();
	  std::cout << "Game created " << std::endl;
	    break;
	case 8:
	  _name = _name.substr(0, _name.size() -1);
	  break;
	default:
	  {
	    _name += c;
	    _currentGM->printMenu(_menu.getCurrentGame()->getValue(), _menu.getCurrentLib()->getValue(), _name);
	  }
	}

      //std::cout << c << std::endl;

    }
  return (0);
}

void		Launcher::nextGame()
{
    _menu.nextGame();
    _currentGM->printMenu(_menu.getCurrentGame()->getValue(), _menu.getCurrentLib()->getValue(), _name);
   std::cout << "[current game : " << _menu.getCurrentGame()->getValue() << "]"  << std::endl;
}

void		Launcher::nextLib()
{
   _menu.nextLib();
   _currentGM->printMenu(_menu.getCurrentGame()->getValue(), _menu.getCurrentLib()->getValue(), _name);
  std::cout << "[current lib : " << _menu.getCurrentLib()->getValue() << "]"  << std::endl;
}

void		Launcher::print()
{
  // std::cout << _menu.getCurrentGame()->getValue() << std::endl;
  //std::cout << _menu.getCurrentLib()->getValue() << std::endl;
}
