//
// component_input.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Mon Feb 27 11:26:25 2017 Nathan Scutari
//

#ifndef COMPONENT_INPUT_HPP_
# define COMPONENT_INPUT_HPP_

#include <string>
#include "link.hpp"
#include "IComponent.hpp"

class	c_input : public nts::IComponent
{
private:
  nts::Tristate			pin_state;

public:
  c_input(const std::string &value);
  virtual ~c_input();

  nts::Tristate Compute(size_t pin_num_this = 1);
  void		SetPin(nts::Tristate value);
  void		SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_INPUT_HPP_ */
