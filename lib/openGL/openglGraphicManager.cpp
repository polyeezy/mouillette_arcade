//
// openglGraphicManager.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:25:41 2016 Valerian Polizzi
// Last update Thu Mar 17 14:56:24 2016 Valerian Polizzi
//

#include "openglGraphicManager.hh"

openglGraphicManager::openglGraphicManager()
{
  std::cout << "ok opengl" << std::endl;
}

openglGraphicManager::~openglGraphicManager()
{

}

void		openglGraphicManager::createWindow(const std::string &name)
{
  SDL_Surface	*window;

  if ((window = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL)))
    exit(EXIT_FAILURE);
  SDL_WM_SetCaption(name.c_str(), NULL);
  _Window = window;
}

void		openglGraphicManager::refresh()
{
  return;
}

void	openglGraphicManager::print(const Map &map)
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

void		openglGraphicManager::createSurface(const int x, const int y, const int h, const int w, const std::string &name)
{
  (void)h;
  (void)w;
  (void)name;
  (void)x;
  glPushMatrix();
  glTranslated(0, GL_SURFACE_HRATIO * (y / -10) * 2, 0);
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex2d(-GL_SURFACE_WRATIO,-GL_SURFACE_HRATIO);
  glVertex2d(-GL_SURFACE_WRATIO,GL_SURFACE_HRATIO);
  glVertex2d(GL_SURFACE_WRATIO,GL_SURFACE_HRATIO);
  glVertex2d(GL_SURFACE_WRATIO,-GL_SURFACE_HRATIO);
  glEnd();
  glPopMatrix();
  glFlush();
  SDL_GL_SwapBuffers();
}

void		openglGraphicManager::addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text)
{
  (void)surface;
  (void)x;
  (void)y;
  (void)text;
}

void		*openglGraphicManager::getWindow()
{
  return (_Window);
}

int		openglGraphicManager::getKey() const
{
  SDL_Event	events;

  while (SDL_PollEvent(&events))
    {
      switch (events.type)
	{
	case SDL_QUIT:
	  return (ControllerManager::ESCAPE);
	  break;
	default:
	  break;
	}
      switch (events.key.keysym.sym)
	{
	case SDLK_LEFT:
	  return (ControllerManager::LEFT);
	  break;
	case SDLK_RIGHT:
	  return (ControllerManager::RIGHT);
	  break;
	case SDLK_UP:
	  return (ControllerManager::UP);
	  break;
	case SDLK_DOWN:
	  return (ControllerManager::DOWN);
	  break;
	case SDLK_ESCAPE:
	  return (ControllerManager::ESCAPE);
	default:
	  return (events.key.keysym.sym);
	  break;
	}
    }
  return (0);
}

extern "C" IGraphicManager * createGraphicManager()
{
  return (new openglGraphicManager);
}
