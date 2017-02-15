//
// main.cpp for Project-Master in /home/veyssi_b/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb  6 15:43:02 2017 Baptiste Veyssiere
// Last update Tue Feb 14 22:01:04 2017 Baptiste Veyssiere
//

#include "Parser.hpp"

int	aff_error_msg(std::string const &msg, const int ret)
{
  std::cout << msg << std::endl;
  return (ret);
}

int	read_config_file(std::string const &file, Parser *parser)
{
  std::ifstream	stream;
  std::string	line;

  stream.open(file.c_str());
  if (!stream.is_open())
    return (aff_error_msg(std::string("Cannot open file ") + file, 1));
  while (getline(stream, line, '\0'))
    parser->feed(line);
  return (0);
}

int	parse_config_file(int ac, char**av, Parser *parser)
{
  if (ac < 2)
    return (aff_error_msg("No configuration file provided", 1));
  if (read_config_file(av[1], parser))
    return (1);
  parser->createTree();
  return (0);
}

int	main(int ac, char **av)
{
  Parser	parser;
  std::string	input;

  if (parse_config_file(ac, av, &parser))
    return (1);
  for (int i = 2; i < ac; i++)
    parser.add_value(av[i]);
  input = "";
  while (input != "exit" && !(std::cin.eof()))
    {
      std::cout << "> ";
      std::cin >> input;
      if (input != "exit" && !(std::cin.eof()))
	parser.handle_input(input);
    }
  return (0);
}
