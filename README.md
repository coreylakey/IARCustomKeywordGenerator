# IARCustomKeywordGenerator
Parses .ewp project file to .txt file for "User keywords" in IAR.<br>
<br>
Requires 5 inputs:<br>
  source filename: .ewp file to parse through and find all ".c" files to parse.<br>
  destination filename: .txt file to dump temporary text into.<br>
  filenames file filename: .txt file to dump all used ".c" filenames from project file into.<br>
  syntax filename: .txt file to fill with function names, for later use in IAR "Custom Keyword File"<br>
  project directory: your unique "$PROJ_DIR$" define to replace.<br>
 <br>
 <br>
This project is for generating a .txt file with all of the function names in your IAR EWARM project. The purpose of gathering this info, <br>is for use in Tools->Options->Editor->Setup Files->Use Custom Keyword File. Using this allows you to define a "User Keyword" color for <br>all words placed in that .txt file.<br>
