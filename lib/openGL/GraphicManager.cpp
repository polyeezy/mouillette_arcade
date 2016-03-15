//
// GraphicManager.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:25:41 2016 Valerian Polizzi
// Last update Tue Mar 15 16:44:21 2016 Loïc Weinhard
//

#include <GraphicManager.hh>

GraphicManager::GraphicManager()
{
  std::cout << "ok" << std::endl;
}

extern "C" GraphicManager::~GraphicManager()
{

}

void		GraphicManager::createWindow(const std::string &name)
{
  SDL_Surface	*window;

  window = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);
  SDL_WM_SetCaption(name.c_str(), NULL);
  _Window = window;
}

void		GraphicManager::refresh()
{

}

void	GraphicManager::print(const Map &map)
{
  float		trans_x;
  float		trans_y;
  t_pos		pos;

  trans_y = GL_TRANS_Y;
  pos.y = 0;
  while (map.getPos(pos) != -1)
    {
      pos.x = 0;
      trans_x = GL_TRANS_X;
      while (map.getPos(pos) != -2)
	{
	  glPushMatrix();
	  glTranslated(trans_x, trans_y, 0);
	  glBegin(GL_QUADS);
	  glVertex2d(-GL_RATIO,-GL_RATIO);
	  glVertex2d(-GL_RATIO,GL_RATIO);
	  glVertex2d(GL_RATIO,GL_RATIO);
	  glVertex2d(GL_RATIO,-GL_RATIO);
	  switch (map.getPos(pos))
	    {
	    case '0':
	    case 'G':
	    case 'x':
	      glColor3ub(255,255,255);
	      break;
	    case '1':
	    case 'P':
	      glColor3ub(0,0,255);
	      break;
	    case '2':
	      glColor3ub(255,0,0);
	      break;
	    }
	  glEnd();
	  glPopMatrix();
	  pos.x += 1;
	  trans_x += GL_RATIO * 2;
	}
      pos.y += 1;
      trans_y -= GL_RATIO * 2;
    }
  glFlush();
  SDL_GL_SwapBuffers();
}

void		GraphicManager::createSurface(const int x, const int y, const int h, const int w, const std::string &name)
{

}

extern "C" void		GraphicManager::addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text)
{

}

void		*GraphicManager::getWindow()
{
  return (_Window);
}

int		GraphicManager::getKey() const
{
}

extern "C" GraphicManager * createGraphicManager()
{
  return (new GraphicManager);
}
