//
// component_clock.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Thu Mar  2 15:35:00 2017 Nathan Scutari
//

#ifndef COMPONENT_CLOCK_HPP_
# define COMPONENT_CLOCK_HPP_

#include <string>
#include "link.hpp"
#include "IComponent.hpp"

class	c_clock : public nts::IComponent
{
private:
  nts::Tristate			pin_state;

public:
  c_clock(const std::string &value);
  virtual ~c_clock();

  nts::Tristate Compute(size_t pin_num_this = 1);
  void		SetPin(nts::Tristate value);
  void		SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_CLOCK_HPP_ */
