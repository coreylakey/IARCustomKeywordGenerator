# IARCustomKeywordGenerator
<b>Parses .ewp project file to .txt file for "User keywords" in IAR.</b><br>
<br>
Requires 5 inputs:<br>
  <b>source filename</b>: .ewp file to parse through and find all ".c" files to parse.<br>
  <b>syntax filename</b>: .txt file to fill with function names, for later use in IAR "Custom Keyword File"<br>
  <b>project directory</b>: your unique "$PROJ_DIR$" define to replace.<br>
 <br>
 <br>
This project is for generating a .txt file with all of the function names 
in your IAR EWARM project. The purpose of gathering this info, is for use 
in <b>Tools->Options->Editor->Setup Files->Use Custom Keyword File</b>. Using this
allows you to define a "User Keyword" color for all words placed in that .txt file.
