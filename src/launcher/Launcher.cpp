//
// Launcher.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:41:57 2016 Valerian Polizzi
// Last update Tue Mar  8 10:06:38 2016 Valerian Polizzi
//

#include <Launcher.hh>

Launcher::Launcher()
{
  _menu.addGame("Select a game");
  _menu.addLib("Select a lib");
  this->feedFromRepo("games");
  this->feedFromRepo("lib");
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

void		Launcher::getKeys()
{

}

void		Launcher::nextGame()
{
  _menu.nextGame();
}

void		Launcher::nextLib()
{
  _menu.nextLib();
}

void		Launcher::print()
{
  std::cout << _menu.getCurrentGame()->getValue() << std::endl;
  std::cout << _menu.getCurrentLib()->getValue() << std::endl;
}
