//
// Launcher.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:41:57 2016 Valerian Polizzi
// Last update Mon Mar 21 17:34:37 2016 Valerian Polizzi
//

#include <Launcher.hh>

Launcher::Launcher()
{

}

void		Launcher::openLibrary(const std::string &lib)
{
  _lm.open(lib);
  this->_currentGM = _lm.createGM();
}

void		Launcher::init()
{
  this->_cm.importConf();
}

void		Launcher::run()
{

  _menu.addGame("Snake");
  _menu.addGame("Pacman");

  this->feedFromRepo("lib");

  _currentGM->createWindow("Arcade");

  _currentGM->createSurface(0, 0, 20, 200, "Games");
  _currentGM->addTextToSurface("Games", 30, 5, _menu.getCurrentGame()->getValue());

  _currentGM->createSurface(20, 20, 20, 200, "Libs");
  _currentGM->addTextToSurface("Libs", 30, 10, _menu.getCurrentLib()->getValue());

  _currentGM->createSurface(40, 40, 20, 200, "Name");
  _currentGM->addTextToSurface("Name", 30, 15, "Type your name:");

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

	  if (file.substr(file.find_last_of(".") + 1) == "arcade")
	    _menu.addGame(file);
	  else if (file.substr(file.find_last_of(".") + 1) == "so")
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
	  break;
	case ControllerManager::UP:
	  this->nextLib();
	  break;
	case ControllerManager::LEFT:
	  this->nextGame();
	  break;
	case ControllerManager::DOWN:
	  this->nextLib();
	  break;
	case ControllerManager::ACTION:
	  _lm.open(std::string("./lib/").append(_menu.getCurrentLib()->getValue()));
	  _currentGM = _lm.createGM();
	  _lm.close();
	  // _gamem.play(_menu.getCurrentGame()->getValue());
	    break;
	case 8:
	  _name = _name.substr(0, _name.size() -1);
	  _currentGM->addTextToSurface("Name", 33, 15, _name);
	  break;
	default:
	  {
	    _name += c;
	  }
	  _currentGM->addTextToSurface("Name", 33, 15, _name);
	}
      //std::cout << c << std::endl;
      _currentGM->refresh();
    }
  return (0);
}

void		Launcher::nextGame()
{
    _menu.nextGame();
   _currentGM->addTextToSurface("Games", 33, 5, _menu.getCurrentGame()->getValue());
}

void		Launcher::nextLib()
{
   _menu.nextLib();
  _currentGM->addTextToSurface("Libs", 33, 10, _menu.getCurrentLib()->getValue());
}

void		Launcher::print()
{
  // std::cout << _menu.getCurrentGame()->getValue() << std::endl;
  //std::cout << _menu.getCurrentLib()->getValue() << std::endl;
}
