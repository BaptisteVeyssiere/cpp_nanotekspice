//
// IComponent.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 10:44:03 2017 Nathan Scutari
// Last update Thu Feb  9 14:47:57 2017 Nathan Scutari
//

#ifndef ICOMPONENT_HPP_
# define ICOMPONENT_HPP_

#include "cstddef"

namespace nts
{
  enum Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };

  class IComponent
  {
  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1) = 0;
    virtual void		SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_target) = 0;
    virtual void		Dump(void) const = 0;
    virtual			~IComponent(void) {}
  };
}

#endif /* !ICOMPONENT_HPP_ */
