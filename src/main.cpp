//
// main.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 15:54:52 2016 Valerian Polizzi
// Last update Tue Mar  8 10:06:53 2016 Valerian Polizzi
//

#include <Launcher.hh>

int		main()
{
  Launcher	L;

  L.print();
  L.nextGame();
  std::cout << std::endl << std::endl;
  L.print();

  L.nextGame();
  std::cout << std::endl << std::endl;
  L.print();
  return (0);
}
