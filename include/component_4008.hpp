//
// component_4008.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Thu Mar  2 15:39:49 2017 Nathan Scutari
//

#ifndef COMPONENT_4008_HPP_
# define COMPONENT_4008_HPP_

#include <vector>
#include <string>
#include "link.hpp"
#include "AComponent.hpp"

class	c_4008 : public AComponent
{
private:
  std::vector<nts::Tristate>			pin_state;
  std::vector<t_link>				link;
  std::vector<nts::Tristate>			carry_out;
  size_t					pin_order[4][2];

public:
  c_4008(const std::string &value);
  virtual ~c_4008();

  nts::Tristate	Compute_si(size_t pin_num_this);
  nts::Tristate Compute(size_t pin_num_this = 1);
  void		SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target);
  void		Dump(void) const;
  nts::Tristate	Int_to_tristate(int i);
  int	Tristate_to_int(nts::Tristate t);
};

#endif /* !COMPONENT_4008_HPP_ */
