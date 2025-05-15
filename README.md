# fcmp: File Comparison

## Usage
To compare two files type ./fcmp FILE1 FILE2 where FILE1 and FILE2 are the two text files you want to compare. If they differ, it will show you the first line number they are different and what the text was at each of those lines. If they are the same it will report this as well. 

## Build Instructions
To build type gcc -o fcmp fcmp.c. It will probably also build just fine on other compilers as well. However, this is the only compiler it was tested on.
