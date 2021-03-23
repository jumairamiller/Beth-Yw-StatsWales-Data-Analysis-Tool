# Beth-Yw-StatsWales-Data-Analysis-Tool
CSC317 Advanced OOP: Beth Yw StatsWales Data Analysis Tool

Cnsideration for futher "goodness marks"?
- In input.cpp and input.h, I tried to handle the exception of stream cannot be associated with the input of source (i.e. file that's been passed in) by checking whether the issue was the directory or the file name. If the file path was the issue, the exception would be caught and handles by replacing it with the correct path to directory and then attempt to open the file with the corrected directory path. If even that did not work (i.e. trying to open the file with the correct directory path or if the directory path was correct to begin with), then I returned a message saying the file name did not exist in the collection of available datasets.  
