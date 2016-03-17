//
// CacaGraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/lib/libcaca
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Wed Mar 16 15:13:24 2016 Valerian Polizzi
// Last update Thu Mar 17 13:59:48 2016 Valerian Polizzi
//

#ifndef _CACAGRAPHICMANAGER_HH_
# define _CACAGRAPHICMANAGER_HH_

# include <IGraphicManager.hh>
# include <caca.h>
# include <map>
# include <map.hh>
# include <ControllerManager.hh>

class CacaGraphicManager : public IGraphicManager
{
private:
  void          *_Window;
  void          *_Content;
  std::map<const std::string, void *>   _surfaces;
  void          *_handle;
public:
  CacaGraphicManager();
  ~CacaGraphicManager();
   void          setHandle(void *);
   void          createWindow(const std::string &name);
   void          refresh();
  void          print(const Map &);
  void          openLib(const std::string&);
  void          createSurface(const int x, const int y, const int h, const int w, const std::string &name);
    void          addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text);
    void          moveCursorUp();
    int getKey() const;
    void          *getWindow();
   IGraphicManager *createGraphicManager();
};

#endif
