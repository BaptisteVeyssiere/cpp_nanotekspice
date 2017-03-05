//
// component_4094.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Sun Mar  5 10:29:44 2017 Nathan Scutari
//

#ifndef COMPONENT_4094_HPP_
# define COMPONENT_4094_HPP_

#include <vector>
#include <string>
#include "link.hpp"
#include "AComponent.hpp"

class	c_4094 : public AComponent
{
private:
  nts::Tristate					clock;
  int						pin_Q[8];
  char						ttable[6][8];
  std::vector<nts::Tristate>			pin_state;
  std::vector<struct s_link>			link;

public:
  c_4094(const std::string &value);
  virtual ~c_4094();

  nts::Tristate	Shift_Compute(size_t pin_num_this);
  char		Clock_Cycle(nts::Tristate clock);
  int		Ttable_Check(char, nts::Tristate);
  nts::Tristate Compute(size_t pin_num_this = 1);
  void		Set_Shift(int i);
  void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_4094_HPP_ */
