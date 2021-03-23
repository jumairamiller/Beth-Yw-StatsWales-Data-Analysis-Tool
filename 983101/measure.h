#ifndef MEASURE_H_
#define MEASURE_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <983101>

  This file contains the decalaration of the Measure class.

  TODO: Read the block comments with TODO in measure.cpp to know which 
  functions and member variables you need to declare in this class.
 */

#include <string>
#include <map>

/*
  The Measure class contains a measure code, label, and a container for readings
  from across a number of years.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Measure {
private:
    std::string measureCode;
    std::string label;
    std::map<unsigned int, double> measureData;

public:
    Measure(std::string code, const std::string &label);
    const std::string getCodename() const noexcept;
    const std::string getLabel() const noexcept;
    void setLabel(std::string label);
    const double getValue(unsigned int key) const;
    void setValue(unsigned int key, double value);
    unsigned int size() const noexcept;
    const double getDifference() const noexcept;
    const double getDifferenceAsPercentage() const noexcept;
    const double getAverage() const noexcept;
    const std::map<unsigned int, double> getData() const;
    friend bool operator==(const Measure& lhs, const Measure& rhs);
};

#endif // MEASURE_H_