//
// component_4071.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Wed Feb 15 15:43:22 2017 Nathan Scutari
//

#ifndef COMPONENT_4071_HPP_
# define COMPONENT_4071_HPP_

#include <vector>
#include <string>
#include "link.hpp"
#include "IComponent.hpp"

class	c_4071 : public nts::IComponent
{
private:
  std::vector<bool>				computed;
  std::vector<nts::Tristate>			pin_state;
  std::vector<t_link>				link;

public:
  c_4071(const std::string &value);
  virtual ~c_4071();

  nts::Tristate Compute(size_t pin_num_this = 1);
  nts::Tristate	Or_gate(nts::Tristate pin_input1, nts::Tristate pin_input2);
  void		SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_4071_HPP_ */
