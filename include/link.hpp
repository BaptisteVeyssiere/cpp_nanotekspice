//
// link.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 14:06:15 2017 Nathan Scutari
// Last update Fri Feb 10 16:18:02 2017 Nathan Scutari
//

#ifndef LINK_HPP_
# define LINK_HPP_

#include "IComponent.hpp"

typedef struct s_link
{
  size_t			pin_target;
  nts::IComponent		*link;
}		t_link;

#endif /* ! LINK_HPP_ */
