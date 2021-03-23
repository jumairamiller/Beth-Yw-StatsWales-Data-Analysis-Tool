#ifndef AREAS_H
#define AREAS_H

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <983101>

  This file contains the Areas class, which is responsible for parsing data
  from a standard input stream and converting it into a series of objects:

  Measure       — Represents a single measure for an area, e.g.
   |              population. Contains a human-readable label and a map of
   |              the measure across a number of years.
   |
   +-> Area       Represents an area. Contains a unique local authority code
        |         used in national statistics, a map of the names of the area 
        |         (i.e. in English and Welsh), and a map of various Measure 
        |         objects.
        |
        +-> Areas A class that contains all Area objects.

  TODO: Read the block comments with TODO in areas.cpp to know which 
  functions and member variables you need to declare in this class.
 */

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>

#include "datasets.h"
#include "area.h"

/*
  An alias for filters based on strings such as categorisations e.g. area,
  and measures.
*/
using StringFilterSet = std::unordered_set<std::string>;

/*
  An alias for a year filter.
*/
using YearFilterTuple = std::tuple<unsigned int, unsigned int>;

/*
  An alias for the data within an Areas object stores Area objects.

  TODO: you should remove the declaration of the Null class below, and set
  AreasContainer is a Standard Library Multimap because the key, localAuthorityCode,
  may have multiple translations of the human-readable name. The data will be ordered by year
*/
class Null { };

using AreasContainer = std::map<std::string, Area>;

/*
  Areas is a class that stores all the data categorised by area. The 
  underlying Standard Library container is customisable using the alias above.

  To understand the functions declared below, read the comments in areas.cpp
  and the coursework worksheet. Briefly: populate() is called by bethyw.cpp to
  populate data inside an Areas instance. This function will hand off the
  specific parsing of code to other functions, based on the value of 
  BethYw::SourceDataType.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Areas {
private:
    AreasContainer areasContainer;

public:
    Areas();
    void setArea(std::string localAuthorityCode, Area area);
    const Area getArea(std::string localAuthorityCode) const;
    unsigned int size() const noexcept;
    void populateFromAuthorityCodeCSV(
            std::istream& is,
            const BethYw::SourceColumnMapping& cols,
            const StringFilterSet * const areas = nullptr) noexcept(false);

    //Standard populate function
    void populate(
            std::istream& is,
            const BethYw::SourceDataType& type,
            const BethYw::SourceColumnMapping& cols) noexcept(false); // function may throw exceptions if needed

    // Overload the standard populate function to consider filters
    void populate(
            std::istream& is,
            const BethYw::SourceDataType& type,
            const BethYw::SourceColumnMapping& cols,
            const StringFilterSet * const areasFilter = nullptr,
            const StringFilterSet * const measuresFilter = nullptr,
            const YearFilterTuple * const yearsFilter = nullptr) noexcept(false);// function may throw exceptions if needed

    std::string toJSON() const;
};

#endif // AREAS_H