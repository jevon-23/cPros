#! /bin/zsh
cd Utils

gcc -c -o commands commands.c
wait

cd ..
wait
ls
gcc -o main Utils/commands main.c

exit
