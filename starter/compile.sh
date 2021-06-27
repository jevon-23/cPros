#! /bin/zsh
cd Utils

gcc -c -o commands commands.c
wait

cd ..
wait

gcc -o main Utils/commands main.c

exit
