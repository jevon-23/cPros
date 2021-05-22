# cPros
Small programs written in C, most of them are used to write imports and main methods into files. 

# starter
  ./main {filename} 
  
  ./main {fileName} {pt/rn}
  
  ./main redux
        
  Takes in a filename, creates that file, and writes to it the necessary things needed to run that file (i.e c program needs a main func w/ some imports, java programs need public class, etc., Check starter/Utils/commands.c).

Works with .c, .py, .java, .sh, also can write in the basic imports for pyTorch (pt) and React-Native (rn).
Also makes the directory necessary to work with redux for react. 
  Will update with more specifics n

Personally, I believe the best use of these functions is to use them as aliases. See https://www.tecmint.com/create-alias-in-linux/ for more.

* User's help
I implemented .sh files for starter, and its job is objective is simply to run its respective c program and open up an ide.
Currently, these are are all dependent on my system, so if you would like to use the .sh file (i.e for an alias in a .zshrc file), you will need to make sure to:
  1. If you are not using zsh for your bash, to run the .sh files you need to go into them change the bash to what yours is for the respective file.

* Also, if you want to run start.c on a shell (.sh) file
    1. Update line 71 in {$PATH}/starter/Utils/commands.c to your path: {$PATH}/starter/Utils/sh_helper/helps.sh
    2. Update line 3 in {$PATH}/starter/Utils/sh_helper/helps.sh to your bash. 


# links
  A small program that opens preset webpages that have been stored by the ueser.
  
  ./main init
  
  ./main add {class} {subClass} {link}
  
  ./main open {class} {subClass}
  
  ./main print
  
  initilizes directory, basically creates a place locally to store all the classes that you enter.
  
  ./main init 
  
  stores a class locally. CLASS = className (Calculus1), SUBCLASS = subClass (Discussion), LINK = linkTo website (zoom.com)
  
  ./main add {class} {subClass} {link}
  
  (i.e. add Calculus1 Discussion zoom.com)
  
  Opens the users' default web browser, based on CLASS = className (Calculus1), SUBCLASS (Discussion)
  
  ./main open {class} {subClass}
  
  (i.e. open Calculus1 Discussion)
  
  Prints all of the classes that have been saved
  ./main print
  
  * Users help
    To open the webpage, I am using a system("open ...), this may not be applicable for I believe windows users. If not, look in to ShellExecute()
  
  * Future changes
    1. Implement a delete system. Not sure what it will look like, but I am thinking about turning it into an empty node, and then in add I will first look to see if we run into an empty node when we are searching grabbing all of the classes in readFile(). 
  
  
  
  
  
  
