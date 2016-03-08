//
// Launcher.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:41:57 2016 Valerian Polizzi
// Last update Tue Mar  8 15:25:43 2016 Valerian Polizzi
//

#include <Launcher.hh>

Launcher::Launcher()
{
  _menu.addGame("Select a game");
  _menu.addLib("Select a lib");
  this->feedFromRepo("games");
  this->feedFromRepo("lib");
  _gm.createWindow("Arcade");


  _gm.createSurface(20, 200, 20, 20, "Help");
  _gm.addTextToSurface("Help", 2, 28, "2: Prev lib  3: Next lib     4: Prev Game ");
  _gm.addTextToSurface("Help", 2, 30, "5: Next Game 8: Restart Game 9: go back    Esc: exit");

  _gm.createSurface(20, 200, 20, 20, "Games");
  _gm.addTextToSurface("Games", 33, 5, _menu.getCurrentGame()->getValue());

  _gm.createSurface(20, 200, 40, 40, "Libs");
  _gm.addTextToSurface("Libs", 33, 10, _menu.getCurrentLib()->getValue());

  _gm.createSurface(20, 200, 40, 40, "Name");
  _gm.addTextToSurface("Name", 33, 15, "Type your name:");

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
  char		c = 0;

  _gm.refresh();
  while (c != 27)
    {
      c = _gm.getKey();
      switch(c)
	{
	case '5':
	  this->nextGame();
	  break;
	case '3':
	  this->nextLib();
	  break;
	default:
	  {
	    _name += c;
	    _gm.addTextToSurface("Name", 33, 15, _name);
	  }
	}
      _gm.refresh();
    }
}

void		Launcher::nextGame()
{
  _menu.nextGame();
  _gm.addTextToSurface("Games", 33, 5, _menu.getCurrentGame()->getValue());
}

void		Launcher::nextLib()
{
  _menu.nextLib();
  _gm.addTextToSurface("Libs", 33, 10, _menu.getCurrentLib()->getValue());
}

void		Launcher::print()
{
  // std::cout << _menu.getCurrentGame()->getValue() << std::endl;
  //std::cout << _menu.getCurrentLib()->getValue() << std::endl;
}
