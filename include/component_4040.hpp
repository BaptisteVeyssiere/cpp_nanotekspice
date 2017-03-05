//
// component_4040.hpp for nanotekspice in /home/scutar_n/rendu/CPP/cpp_nanotekspice
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Feb  9 11:01:40 2017 Nathan Scutari
// Last update Sun Mar  5 11:10:34 2017 Nathan Scutari
//

#ifndef COMPONENT_4040_HPP_
# define COMPONENT_4040_HPP_

#include <vector>
#include <string>
#include "link.hpp"
#include "AComponent.hpp"

class	c_4040 : public AComponent
{
private:
  nts::Tristate					clock;
  int						pin_Q[12];
  std::vector<nts::Tristate>			pin_state;
  std::vector<struct s_link>			link;

public:
  c_4040(const std::string &value);
  virtual ~c_4040();

  nts::Tristate	Add_Counter(size_t pin_num_this);
  nts::Tristate	Reset_Counter(void);
  nts::Tristate Compute(size_t pin_num_this = 1);
  char		Clock_Cycle(nts::Tristate clock);
  void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
  void		Dump(void) const;
};

#endif /* !COMPONENT_4040_HPP_ */
