//
// Launcher.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:41:57 2016 Valerian Polizzi
// Last update Tue Mar 15 14:56:44 2016 Valerian Polizzi
//

#include <Launcher.hh>

Launcher::Launcher()
{

}

void		Launcher::openLibrary(const std::string &lib)
{
  _lm.open(lib);
  this->_gm = _lm.createGM();
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

  _gm->createWindow("Arcade");

  _gm->createSurface(20, 200, 20, 20, "Games");
  _gm->addTextToSurface("Games", 30, 5, _menu.getCurrentGame()->getValue());

  _gm->createSurface(20, 200, 40, 40, "Libs");
  _gm->addTextToSurface("Libs", 30, 10, _menu.getCurrentLib()->getValue());

  _gm->createSurface(20, 200, 40, 40, "Name");
  _gm->addTextToSurface("Name", 30, 15, "Type your name:");

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

  _gm->refresh();
  while (c != ControllerManager::ESCAPE)
    {
      c = _cm.getKey(_gm->getWindow());
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
	  _lm.close();
	  // _lm.open(std::string("./lib/").append(_menu.getCurrentLib()->getValue()));
	  _gamem.play(_menu.getCurrentGame()->getValue());
	    break;
	case 8:
	  _name = _name.substr(0, _name.size() -1);
	  _gm->addTextToSurface("Name", 33, 15, _name);
	  break;
	default:
	  {
	    _name += c;
	  }
	  _gm->addTextToSurface("Name", 33, 15, _name);
	}
      std::cout << c << std::endl;
      _gm->refresh();
    }

}

void		Launcher::nextGame()
{
    _menu.nextGame();
   _gm->addTextToSurface("Games", 33, 5, _menu.getCurrentGame()->getValue());
}

void		Launcher::nextLib()
{
   _menu.nextLib();
  _gm->addTextToSurface("Libs", 33, 10, _menu.getCurrentLib()->getValue());
}

void		Launcher::print()
{
  // std::cout << _menu.getCurrentGame()->getValue() << std::endl;
  //std::cout << _menu.getCurrentLib()->getValue() << std::endl;
}
