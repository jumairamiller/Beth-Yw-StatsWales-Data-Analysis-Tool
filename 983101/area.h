#ifndef AREA_H_
#define AREA_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <983101>

  This file contains the Area class declaration. Area objects contain all the
  Measure objects for a given local area, along with names for that area and a
  unique authority code.

  TODO: Read the block comments with TODO in area.cpp to know which 
  functions and member variables you need to declare in this class.
 */

#include <string>
#include <unordered_map>

#include "measure.h"

/*
  An Area object consists of a unique authority code, a container for names
  for the area in any number of different languages, and a container for the
  Measures objects.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Area {
private:
    std::string localAuthorityCode;
    std::unordered_map<std::string, std::string> names;
    std::unordered_map<std::string, Measure> measures;

public:
    Area(const std::string& localAuthorityCode);
    const std::string getLocalAuthorityCode() const;
    const std::string getName(std::string languageCode) const;
    std::unordered_map<std::string, std::string> combineNamesWith(Area otherArea);
    void setName(std::string languageCode, std::string name);
    const Measure getMeasure(std::string key) const;
    std::unordered_map<std::string, Measure> combineMeasuresWith(Area otherArea);
    void setMeasure(std::string measureCode, Measure measure);
    unsigned int size() const noexcept;
    //friend std::ostream& operator<<(std::ostream& os, const Area& area);
    friend bool operator==(const Area& lhs, const Area& rhs);
};

#endif // AREA_H_