


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <983101>

  This file contains the code responsible for opening and closing file
  streams. The actual handling of the data from that stream is handled
  by the functions in data.cpp. See the header file for additional comments.
  
  Each function you must implement has a TODO in its comment block. You may
  have to implement additional functions. You may implement additional
  functions not specified.
 */

#include "input.h"

#include <utility>
#include <iostream>

/**
  Constructor for an InputSource.

  @param source
    A unique identifier for a source (i.e. the location).
*/
InputSource::InputSource(const std::string& source) : source(source) {}

InputSource::~InputSource() {}

/**
 This pure virtual function is only callable from a constant context.

  @return
    A non-modifable value for the source passed into the construtor.
*/
std::string InputFile::getSource() const{
    return this->source;
}

/**
  Constructor for a file-based source.

  @param path
    The complete path for a file to import.

  @example
    InputFile input("data/areas.csv");
*/
InputFile::InputFile(const std::string& filePath) : InputSource(filePath) {}

InputFile::~InputFile() {}


/** (HELPER FUNCTION WHICH I ENDED UP NOT USING)
 * Method to verify that the file path was not mis-typed
 * @return a string of the file path minus the last occurrence of delimiter / or \
*/
/*
std::string InputFile::findFPathWithoutFName() const {
    size_t posBeforeFileName = this->getSource().find_last_of("/");
    std::string pathToFile = this->getSource().substr(0, posBeforeFileName+1);
    return pathToFile;
}
*/



/*
  Open a file stream to the file path retrievable from getSource()
  and return a reference to the stream.

  @return
    A standard input stream reference

  @throws
    std::runtime_error if there is an issue opening the file, with the message:
    InputFile::open: Failed to open file <file name>

  @example
    InputFile input("data/areas.csv");
    input.open();
*/
std::istream& InputFile::open() {
    //try{
        this->file.open(this->getSource()); // mode is inferred by default setting of std::ios::in for ifstream
        if (!file.is_open()){
            throw std::runtime_error("InputFile::open: Failed to open file " + this->getSource());
        }
        else {
            std::istream& content = this->file;
            return content;
            file.close();
        }
    /* TRIED TO HANDLE THE EXCEPTION BY CHECKING WHERE SPECIFICALLY THE ISSUE WAS : THE DIRECTORY OR FILE NAME;
     * But this wasnt passing the tests :(((

    } catch (const std::runtime_error & e){
        if(this->getSource().find('/') != std::string::npos){
            std::string pathToFile = findFPathWithoutFName();
            // if the file path is wrong, replace it with correct directory
            if (pathToFile != "./datasets/"){
                std::cout << "Directory to file: " << pathToFile << " was not valid.";
                this->getSource().replace(this->getSource().find(pathToFile), pathToFile.length(), "./datasets/");
                // try opening file with corrected file path
                try{
                    this->file.open(this->getSource());
                    if (!file.is_open()){
                        throw std::runtime_error("InputFile::open: Failed to open file " + this->getSource());
                    }
                    else {
                        std::istream& content = this->file;
                        return content;
                        file.close();
                    }
                } catch (const std::runtime_error& e){
                    std::string fileName = this->getSource().erase(0, pathToFile.length());
                    std::cout << "FileName: " << fileName << " is not valid.";
                }
            }
            else {
                std::string fileName = this->getSource().erase(0, pathToFile.length());
                std::cout << "FileName: " << fileName << " is not valid.";
            }
        }
    }
     */
}


