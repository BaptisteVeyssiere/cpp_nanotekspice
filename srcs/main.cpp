//
// main.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:43:02 2017 Baptiste Veyssiere
// Last update Thu Mar  2 15:23:29 2017 Baptiste Veyssiere
//

#include "command_handler.hpp"

int	main(int ac, char **av)
{
  Parser		parser;
  std::string		input;
  Command_handler	handler;

  // try
  //   {
      if (parse_config_file(ac, av, &parser))
	return (1);
      handler.init(parser.getSystem());
      for (int i = 2; i < ac; i++)
	handler.add_value(av[i]);
      input = "";
      handler.simulate();
      handler.display();
      while (input != "exit" && !(std::cin.eof()))
	{
	  std::cout << "> ";
	  std::cin >> input;
	  if (input != "exit" && !(std::cin.eof()))
	    handler.handle_input(input);
	}
  //   }
  // catch (const std::exception& e)
  //   {
  //     parser.freeSystem();
  //     throw e;
  //   }
  parser.freeSystem();
  return (0);
}
