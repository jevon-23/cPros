#! /bin/zsh

cd utils

gcc -c -o utils utils.c
wait

cd ..
wait
ls
gcc -o main utils/utils main.c

exit
