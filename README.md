# cPros
Small programs written in C, most of them are used to write imports and main methods into files. 

# User's help
I implemented .sh files for almost all of the files, and its job is simply to run its respective c program and open up an ide.
Currently, these are are all dependent on my system, so if you would like to use the .sh file (i.e for an alias in a .zshrc file), you will need to make sure to:
  1. If you are not using zsh for your bash, to run the .sh files you need to go into them change the bash to what yours is for the respective file.

Also, if you want to run start.c on a zsh file
  1. Update line 63 in .../starter/start.c to your path: .../starter/sh_helper/helps.sh
  2. Update line 3 in .../starter/sh_helper/helps.sh to your bash. 

# Future changes
1. I will soon make this so that everything will be in one utilities file and create a main()
2. If I become interested in storing data in c, I would make it so that it would either store your bash or grab it somehow, maybe i will look more into tihs. 
