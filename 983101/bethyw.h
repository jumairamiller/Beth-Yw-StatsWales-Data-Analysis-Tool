#ifndef BETHYW_H_
#define BETHYW_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <983101>

  This file contains declarations for the helper functions for initialising and
  running Beth Yw?

  TODO: Read the block comments with TODO in bethyw.cpp to know which 
  functions you need to declare in this file.
 */

#include <string>
#include <unordered_set>
#include <vector>

#include "lib_cxxopts.hpp"

#include "datasets.h"

const char DIR_SEP =
#ifdef _WIN32
    '\\';
#else
    '/';
#endif

namespace BethYw {

const std::string STUDENT_NUMBER = "983101";

/*
  Run Beth Yw?, parsing the command line arguments and acting upon them.
*/
int run(int argc, char *argv[]);

/*
  Create a cxxopts instance.
*/
cxxopts::Options cxxoptsSetup();

/*
  Parse the datasets argument and return a std::vector of all the datasets
  to import. InputFileSource is declared in datasets.h.
*/
std::vector<BethYw::InputFileSource> parseDatasetsArg(cxxopts::ParseResult& args);

/*
  Parse the areas argument and return a std::unordered_set of all the
  areas to import, or an empty set if all areas should be imported.
*/
std::unordered_set<std::string> parseAreasArg(cxxopts::ParseResult& args);

/*
  Parse the measures argument and return a std::unordered_set of all the
  measures to import, or an empty set if all measures should be imported.
*/
std::unordered_set<std::string> parseMeasuresArg(cxxopts::ParseResult& args);

/*
  Parse the years argument, which may be of form YYYY or YYYY-ZZZZ,
  and return a tuple of two integers representing the start and end year
  std::tuple<unsigned int, unsigned int> of all the years (inclusive)
  that need to be filtered. Return <0,0> tuple if no argument is provided,
  or if one of both of year values are 0
*/
std::tuple<unsigned int, unsigned int> parseYearsArg(cxxopts::ParseResult& args);
} // namespace BethYw

#endif // BETHYW_H_