//
// main.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:54:52 2016 Valerian Polizzi
// Last update Wed Mar 30 14:51:16 2016 Miele Alexis
//


#include <caca.h>
#include <Launcher.hh>
#include "IMap.hh"
#include "PGame.hh"

int		main(int ac, char **av)
{
  //  Launcher	L;


  (void)ac;
  (void)av;
  //  L.openLibrary(av[1]);
  //L.init();
  //L.run();

  LibraryManager			lmgame;

  lmgame.open("./games/pacman.so");
  IGame	*Pacman = lmgame.createGame();

  LibraryManager			lmgraphic;
  lmgraphic.open("./lib/lib_arcade_opengl.so");
  IGraphicManager	*graphic  = lmgraphic.createGM();


  Pacman->setGM(graphic);
  Pacman->getGM()->createWindow("Pacman");
  Pacman->setMap("level_1.pacman");
    Pacman->play();
  //Pacman->getGM()->print(Pacman->getMap());
   char c = 0;

  while (c != ControllerManager::ESCAPE)
    {
      c = Pacman->getGM()->getKey();
    }

  return (0);
}
