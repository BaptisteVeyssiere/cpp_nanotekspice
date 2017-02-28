//
// component_output.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Mon Feb 27 11:25:05 2017 Nathan Scutari
//

#ifndef COMPONENT_OUTPUT_HPP_
# define COMPONENT_OUTPUT_HPP_

#include <string>
#include "link.hpp"
#include "IComponent.hpp"

class	c_output : public nts::IComponent
{
private:
  t_link			link;

public:
  c_output(const std::string &value);
  virtual ~c_output();

  nts::Tristate Compute(size_t pin_num_this = 1);
  void		SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_OUTPUT_HPP_ */
