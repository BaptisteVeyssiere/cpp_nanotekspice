//
// pin_check.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Tue Feb 14 11:13:48 2017 Baptiste Veyssiere
// Last update Wed Mar  1 16:03:19 2017 Nathan Scutari
//

// 1: Input, 2: Pin Input, 3: Output, 4: Pin Output

#include "Parser.hpp"

char	input_pin(int pin)
{
  if (pin != 1)
    throw std::exception();
  return (1);
}

char	clock_pin(int pin)
{
  if (pin != 1)
    throw std::exception();
  return (1);
}

char	true_pin(int pin)
{
  if (pin != 1)
    throw std::exception();
  return (1);
}

char	false_pin(int pin)
{
  if (pin != 1)
    throw std::exception();
  return (1);
}

char	output_pin(int pin)
{
  if (pin != 1)
    throw std::exception();
  return (3);
}

char	c4001_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw std::exception();
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4008_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw std::exception();
  if (pin == 10 || pin == 11 || pin == 12 || pin == 13 || pin == 14)
    return (4);
  return (2);
}

char	c4011_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw std::exception();
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4013_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw std::exception();
  if (pin == 1 || pin == 2 || pin == 12 || pin == 13)
    return (4);
  return (2);
}

char	c4017_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw std::exception();
  if (pin > 0 && pin < 13)
    return (4);
  return (2);
}

char	c4030_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw std::exception();
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4040_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw std::exception();
  if (pin == 1 || pin == 3 || pin == 14 || pin == 15)
    return (4);
  return (2);
}

char	c4069_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw std::exception();
  if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)
    return (4);
  return (2);
}

char	c4071_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw std::exception();
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4081_pin(int pin)
{
  if (pin < 1 || pin > 13 || pin == 7)
    throw std::exception();
  if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
    return (4);
  return (2);
}

char	c4094_pin(int pin)
{
  if (pin < 1 || pin > 15 || pin == 8)
    throw std::exception();
  if (pin > 3 && pin < 15)
    return (4);
  return (2);
}

char	c4514_pin(int pin)
{
  if (pin < 1 || pin > 23 || pin == 12)
    throw std::exception();
  if (pin > 3 && pin < 21)
    return (4);
  return (2);
}

char	c4801_pin(int pin)
{
  if (pin < 1 || pin > 24 || pin == 12)
    throw std::exception();
  if ((pin > 8 && pin < 18) || pin == 20)
    return (4);
  return (2);
}

char	c2716_pin(int pin)
{
  if (pin < 1 || pin > 24 || pin == 12)
    throw std::exception();
  if ((pin > 8 && pin < 18) || pin == 20)
    return (4);
  return (2);
}
