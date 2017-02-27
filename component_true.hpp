//
// component_true.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Mon Feb 27 11:24:57 2017 Nathan Scutari
//

#ifndef COMPONENT_TRUE_HPP_
# define COMPONENT_TRUE_HPP_

#include <string>
#include "link.hpp"
#include "IComponent.hpp"

class	c_true : public nts::IComponent
{

public:
  c_true(const std::string &value);
  virtual ~c_true();

  nts::Tristate Compute(size_t pin_num_this = 1);
  void		SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_TRUE_HPP_ */
