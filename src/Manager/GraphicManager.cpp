//
// GraphicManager.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:25:41 2016 Valerian Polizzi
// Last update Tue Mar 15 13:20:01 2016 Valerian Polizzi
//

#include <GraphicManager.hh>

GraphicManager::GraphicManager()
{
}

GraphicManager::~GraphicManager()
{
}

void		GraphicManager::setHandle(void *h)
{
  _handle = h;
}

void		GraphicManager::moveCursorUp()
{
}

void		GraphicManager::createWindow(const std::string &name)
{
  dlsym(_handle, "createWindow");
}
