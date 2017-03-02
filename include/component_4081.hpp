//
// component_4081.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Thu Mar  2 15:39:57 2017 Nathan Scutari
//

#ifndef COMPONENT_4081_HPP_
# define COMPONENT_4081_HPP_

#include <vector>
#include <string>
#include "link.hpp"
#include "AComponent.hpp"

class	c_4081 : public AComponent
{
private:
  std::vector<nts::Tristate>			pin_state;
  std::vector<struct s_link>			link;

public:
  c_4081(const std::string &value);
  virtual ~c_4081();

  nts::Tristate Compute(size_t pin_num_this = 1);
  nts::Tristate	And_gate(nts::Tristate pin_input1, nts::Tristate pin_input2);
  void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_4081_HPP_ */
