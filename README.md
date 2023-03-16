# Beth-Yw-StatsWales-Data-Analysis-Tool

## Background
A simple data Parser tool in C++ that can read CSV and JSON files, some of which have been downloaded from the  [Statswales](https://statswales.gov.wales/Catalogue) website. StatsWales is website holding publicly‑available data compiled by the Welsh Government. The datasets included all group series of measures over years, organised by area.

The idea behind this assignment was to code according to a specification laid out in documentation and Behaviour Driven Development style (BDD) test suites. Test Suites were implemented using the [Catch2 Testing Framework](https://github.com/catchorg/Catch2).

### The program arguments:

`‑‑dir arg` The directory arg contains the datasets that will be used (default: datasets/). This argument is optional (i.e., if the program is run without the argument supplied, the value datasets
is used).

`‑d arg or ‑‑datasets` arg The dataset(s) to import and analyse as a comma‑separated
list of codes. This argument is optional. If it not set, or it is
set and contains the value all, then all datasets should be
imported. Possible values can be found in datasets.h as the
member variable CODE in the InputFileSource struct inside
the InputFiles namespace.

`‑a arg or ‑‑areas arg` The areas(s) to import and analyse as a comma‑separated list.
Initially, arg should be implemented such that filtering is done
using local authority codes, as found within the dataset files.
This argument is optional. If it not set, or it is set and contains
the value all, then all areas should be imported.

`‑m arg or ‑‑measures ar`g The measure(s) from the dataset(s) to import and analyse as
a comma‑separated list. Initially, arg should be implemented
such that filtering is done using the codenames for measures,
as found within the dataset files. This argument is optional. If it
not set, or it is set and contains the value all, then all measures
from all imported datasets should be imported.

`‑y arg or ‑‑years arg` The years(s) from the dataset(s) to import. arg can either be
of the form YYYY (e.g. 2012 to import data for the year 2012) or
YYYY‑ZZZZ (e.g. 2012‑2015 to import the 4 years from 2012
to 2015). This argument is optional. If it not set, or it is set and
contains the value 0 or 0‑0, then all years should be imported.

`‑j or ‑‑json` Output the data as JSON instead of tables

