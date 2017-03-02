//
// pin_check.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Tue Feb 14 11:13:48 2017 Baptiste Veyssiere
// Last update Thu Mar  2 20:12:53 2017 Baptiste Veyssiere
//

// 1: Input, 2: Pin Input, 3: Output, 4: Pin Output

#include "Parser.hpp"

char	input_pin(int pin)
{
  if (pin != 1)
    throw parsing_error(pin + " is not available for input component");
  return (1);
}

char	clock_pin(int pin)
{
  if (pin != 1)
    throw parsing_error(pin + " is not available for clock component");
  return (1);
}

char	true_pin(int pin)
{
  if (pin != 1)
    throw parsing_error(pin + " is not available for true component");
  return (1);
}

char	false_pin(int pin)
{
  if (pin != 1)
    throw parsing_error(pin + " is not available for false component");
  return (1);
}

char	output_pin(int pin)
{
  if (pin != 1)
    throw parsing_error(pin + " is not available for output component");
  return (3);
}

char	c4001_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw parsing_error(pin + " is not available for 4001 component");
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4008_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw parsing_error(pin + " is not available for 4008 component");
  if (pin == 10 || pin == 11 || pin == 12 || pin == 13 || pin == 14)
    return (4);
  return (2);
}

char	c4011_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw parsing_error(pin + " is not available for 4011 component");
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4013_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw parsing_error(pin + " is not available for 4013 component");
  if (pin == 1 || pin == 2 || pin == 12 || pin == 13)
    return (4);
  return (2);
}

char	c4017_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw parsing_error(pin + " is not available for 4017 component");
  if (pin > 0 && pin < 13)
    return (4);
  return (2);
}

char	c4030_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw parsing_error(pin + " is not available for 4030 component");
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4040_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw parsing_error(pin + " is not available for 4040 component");
  if (pin == 1 || pin == 3 || pin == 14 || pin == 15)
    return (4);
  return (2);
}

char	c4069_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw parsing_error(pin + " is not available for 4069 component");
  if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)
    return (4);
  return (2);
}

char	c4071_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw parsing_error(pin + " is not available for 4071 component");
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4081_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw parsing_error(pin + " is not available for 4081 component");
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4094_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw parsing_error(pin + " is not available for 4094 component");
  if (pin > 3 && pin < 15)
    return (4);
  return (2);
}

char	c4514_pin(int pin)
{
  if (pin < 1 || pin > 23 || pin == 12)
    throw parsing_error(pin + " is not available for 4514 component");
  if (pin > 3 && pin < 21)
    return (4);
  return (2);
}

char	c4801_pin(int pin)
{
  if (pin < 1 || pin > 24 || pin == 12)
    throw parsing_error(pin + " is not available for 4801 component");
  if ((pin > 8 && pin < 18) || pin == 20)
    return (4);
  return (2);
}

char	c2716_pin(int pin)
{
  if (pin < 1 || pin > 24 || pin == 12)
    throw parsing_error(pin + " is not available for 2716 component");
  if ((pin > 8 && pin < 18) || pin == 20)
    return (4);
  return (2);
}
