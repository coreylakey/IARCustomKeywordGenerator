# IARCustomKeywordGenerator
Parses .ewp project file to .txt file for "User keywords" in IAR.

Requires 5 inputs:
  source filename: .ewp file to parse through and find all ".c" files to parse.
  destination filename: .txt file to dump temporary text into.
  filenames file filename: .txt file to dump all used ".c" filenames from project file into.
  syntax filename: .txt file to fill with function names, for later use in IAR "Custom Keyword File"
  project directory: your unique "$PROJ_DIR$" define to replace.
 
 
This project is for generating a .txt file with all of the function names in your IAR EWARM project. The purpose of gathering this info, is for use in Tools->Options->Editor->Setup Files->Use Custom Keyword File. Using this allows you to define a "User Keyword" color for all words placed in that .txt file.