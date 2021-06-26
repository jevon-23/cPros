#! /bin/zsh
cd Utils

gcc -c -o Utils Utils.c
wait

cd ..
wait
ls
gcc -o main Utils/Utils main.c

exit
