//
// SEntity.hh for SEntity in /home/miele_a/rendu/arcade/mouillette_arcade/include/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 16:13:32 2016 Miele Alexis
// Last update Wed Mar 30 16:55:26 2016 Miele Alexis
//

#ifndef SENTITY_HH_
# define SENTITY_HH_

# include <Protocol.hpp>
# include "ControllerManager.hh"
# include "SMap.hh"
# include "AEntity.hh"
# include "Position.hh"

class SMap;

typedef struct	s_snakebody
{
  t_pos		pos;
}		t_snakebody;

class	SEntity : public AEntity
{
private:
  std::vector<t_snakebody *>	_body;
  int	_dir;

public:
  SEntity(const float, const float, const float, const float, const float);
  SEntity(const float, const float, const t_pos, const float);
  virtual ~SEntity();
  void			move(const SMap *, const int);
  void			checkVerticalMove(const SMap *, const int);
  void			checkHorizontalMove(const SMap *, const int);
  void			newBody();
  const std::vector<t_snakebody *>	&getBody() const;
  virtual void		print();
};

#endif
