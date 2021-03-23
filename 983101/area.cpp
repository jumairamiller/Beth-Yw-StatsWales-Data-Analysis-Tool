


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <983101>

  This file contains the implementation for the Area class. Area is a relatively
  simple class that contains a local authority code, a container of names in
  different languages (perhaps stored in an associative container?) and a series
  of Measure objects (also in some form of container).

  This file contains numerous functions you must implement. Each function you
  must implement has a TODO block comment. 
*/

#include <stdexcept>
#include <iostream>

#include "area.h"

/*
 TODO: Somehow initialise the names and measures??

  Construct an Area with a given local authority code.

  @param localAuthorityCode
    The local authority code of the Area

  @example
    Area("W06000023");
*/
Area::Area(const std::string& localAuthorityCode) : localAuthorityCode(localAuthorityCode){}

/**
  Retrieve the local authority code for this Area. This function should be
  callable from a constant context and not modify the state of the instance.
  
  @return
    The Area's local authority code

  @example
    Area area("W06000023");
    ...
    auto authCode = area.getLocalAuthorityCode();
*/
const std::string Area::getLocalAuthorityCode() const{
    return this->localAuthorityCode;
}

/**
  Get a name for the Area in a specific language.  This function should be 
  callable from a constant context and not modify the state of the instance.

  @param lang
    A three-letter language code in ISO 639-3 format, e.g. cym or eng

  @return
    The name for the area in the given language

  @throws
    std::out_of_range if lang does not correspond to a language of a name stored
    inside the Area instance

  @example
    Area area("W06000023");
    std::string langCode  = "eng";
    std::string langValue = "Powys";
    area.setName(langCode, langValue);
    ...
    auto name = area.getName(langCode);
*/
const std::string Area::getName(std::string languageCode) const{
    // account for case insensitive use inputs
    std::transform(languageCode.begin(), languageCode.end(), languageCode.begin(), ::tolower);
    // https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap
    // throw exception if languageCode was not as a key within the names map
    if (names.find(languageCode) == names.end()){
        if(languageCode.length() != 3){
            throw std::out_of_range("The provided language code is not a valid ISO 639-3 identifier: " + languageCode);
        }
        else{
            throw std::out_of_range("The dataset does not contain a translation of the area name in the requested "
                                    "language: " + languageCode);
        }
    }
    // if area name has a translation for the languageCode, retrieve it from names map
    else {
        return this->names.at(languageCode);
    }
}

std::unordered_map<std::string, std::string> Area::combineNamesWith(Area otherArea) {
    std::unordered_map<std::string, std::string> combinedNames = otherArea.names;
    for (auto &name : this->names) {
        combinedNames.insert(name);
    }
    return combinedNames;
}


/**
  Set a name for the Area in a specific language.

  @param lang
    A three-letter (alphabetical) language code in ISO 639-3 format,
    e.g. cym or eng, which should be converted to lowercase

  @param name
    The name of the Area in `lang`

  @throws
    std::invalid_argument if lang is not a three letter alphabetic code

  @example
    Area area("W06000023");
    std::string langCodeEnglish  = "eng";
    std::string langValueEnglish = "Powys";
    area.setName(langCodeEnglish, langValueEnglish);

    std::string langCodeWelsh  = "cym";
    std::string langValueWelsh = "Powys";
    area.setName(langCodeWelsh, langValueWelsh);
*/
void Area::setName(std::string languageCode, std::string name){
    if (languageCode.length() != 3){
        throw std::invalid_argument("The provided language code is not a valid ISO 639-3 identifier:" + languageCode);
    }
    std::transform(languageCode.begin(), languageCode.end(), languageCode.begin(), ::tolower);
    if (names.count(languageCode) == 1){
        std::cout << "A translation for the area name is the provided language code already exists: " << languageCode;
    }
    name[0] = std::toupper(name[0]);
    this->names.insert({languageCode,name});
}

/*
  Retrieve a Measure object, given its codename. This function should be case
  insensitive when searching for a measure.

  @param key
    The codename for the measure you want to retrieve

  @return
    A Measure object

  @throws
    std::out_of_range if there is no measure with the given code, throwing
    the message:
    No measure found matching <codename>

  @example
    Area area("W06000023");
    Measure measure("Pop", "Population");
    area.setMeasure("Pop", measure);
    ...
    auto measure2 = area.getMeasure("pop");
*/
const Measure Area::getMeasure(std::string key) const {
    // account for case insensitive user inputs
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    // provided key cannot be found in the measures map for the given Areas object
    if (measures.find(key) == measures.end()){
        throw std::out_of_range("Area does not contain value for the provided measure code name: " + key);
    }
    //return value if key exists
    return this->measures.at(key);
}

/**
 * Method to return a combined map of measures from existing area and another area object
 * @return combined map of measures of two area objects
 */
std::unordered_map<std::string, Measure> Area::combineMeasuresWith(Area otherArea){
    std::unordered_map<std::string, Measure> combinedMeasures = otherArea.measures;
    for (auto &measure : this->measures) {
        combinedMeasures.insert(measure);
    }
    return combinedMeasures;
}


/**
  Add a particular Measure to this Area object. Note that the Measure's
  codename should be converted to lowercase.

  If a Measure already exists with the same codename in this Area, overwrite any
  values contained within the existing Measure with those in the new Measure
  passed into this function. The resulting Measure stored inside the Area
  instance should be a combination of the two Measures instances.

  @param codename
    The codename for the Measure

  @param measure
    The Measure object

  @return
    void

  @example
    Area area("W06000023");

    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    double value = 12345678.9;
    measure.setValue(1999, value);

    area.setMeasure(codename, measure);
*/
void Area::setMeasure(std::string measureCode, Measure measure){
    std::transform(measureCode.begin(), measureCode.end(), measureCode.begin(), ::tolower);

    if(this->measures.count(measureCode) != 1){
        this->measures.insert({measureCode,measure});
    } else{
        measures.at(measureCode) = measure;
    }

}


/**
  Retrieve the number of Measures we have for this Area. This function should be 
  callable from a constant context, not modify the state of the instance, and
  must promise not throw an exception.

  @return
    The size of the Area (i.e., the number of Measures)

  @example
    Area area("W06000023");
    std::string langCode  = "eng";
    std::string langValue = "Powys";
    area.setName(langCode, langValue);

    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    area.setMeasure(code, measure);
    auto size = area.size();
*/
unsigned int Area::size() const noexcept{
    return this->measures.size();
}


/*
  TODO: operator<<(os, area)

  Overload the stream output operator as a free/global function.

  Output the name of the Area in English and Welsh, followed by the local
  authority code. Then output all the measures for the area (see the coursework
  worksheet for specific formatting).

  If the Area only has only one name, output this. If the area has no names,
  output the name "Unnamed".

  Measures should be ordered by their Measure codename. If there are no measures
  output the line "<no measures>" after you have output the area names.

  See the coursework specification for more examples.

  @param os
    The output stream to write to

  @param area
    Area to write to the output stream

  @return
    Reference to the output stream

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    std::cout << area << std::endl;
*/
//std::ostream& operator<<(std::ostream& os, const Area& area){
//    os <<
//}

/*
  TODO: operator==(lhs, rhs)

  Overload the == operator for two Area objects as a global/free function. Two
  Area objects are only equal when their local authority code, all names, and
  all data are equal.

  @param lhs
    An Area object

  @param rhs
    A second Area object

  @return
    true if both Area instanes have the same local authority code, names
    and data; false otherwise.

  @example
    Area area1("MYCODE1");
    Area area2("MYCODE1");

    bool eq = area1 == area2;
*/
bool operator==(const Area& lhs, const Area& rhs) {
    bool sameAuthCode = lhs.localAuthorityCode == rhs.localAuthorityCode;
    bool sameNames = lhs.names == rhs.names;
    bool sameMeasures = lhs.measures == rhs.measures;
    return sameAuthCode && sameNames && sameMeasures;
}

