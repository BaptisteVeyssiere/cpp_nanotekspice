//
// isValid.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb 13 19:46:53 2017 Baptiste Veyssiere
// Last update Mon Feb 27 23:01:26 2017 Baptiste Veyssiere
//

#include "Parser.hpp"

static int	pinType(t_component *obj, int pin)
{
  char	(*func_list[])(int) =
    {
      input_pin,
      clock_pin,
      true_pin,
      false_pin,
      output_pin,
      c4001_pin,
      c4008_pin,
      c4011_pin,
      c4013_pin,
      c4017_pin,
      c4030_pin,
      c4040_pin,
      c4069_pin,
      c4071_pin,
      c4081_pin,
      c4094_pin,
      c4514_pin,
      c4801_pin,
      c2716_pin,
    };
  std::string	str_list[] =
    {
      "input",
      "clock",
      "true",
      "false",
      "output",
      "4001",
      "4008",
      "4011",
      "4013",
      "4017",
      "4030",
      "4040",
      "4069",
      "4071",
      "4081",
      "4094",
      "4514",
      "4801",
      "2716",
    };

  for (size_t i = 0; i < 19; i++)
    if (obj->type == str_list[i])
      return (func_list[i](pin));
  throw std::exception();
  return (0);
}

bool	link_isValid(t_component *obj, t_component *obj2, int pin1, int pin2)
{
  int	type1;
  int	type2;

  type1 = pinType(obj, pin1);
  type2 = pinType(obj2, pin2);
  std::cout << type1 << " - " << type2 << std::endl;

  if ((type1 == 3 && type2 == 4) ||
      (type1 == 2 && type2 == 1) ||
      (type1 == 2 && type2 == 4))
    {
      if (obj->isLinked[pin1] == true)
	throw std::exception();
      return (true);
    }
  else if ((type1 == 4 && type2 == 3) ||
      (type1 == 1 && type2 == 2) ||
      (type1 == 4 && type2 == 2))
    {
      if (obj2->isLinked[pin2] == true)
	throw std::exception();
      return (false);
    }
  throw std::exception();
  return (false);
}
