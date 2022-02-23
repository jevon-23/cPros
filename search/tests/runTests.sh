#! /bin/zsh

cd ../utils
ls

gcc -c -o utils utils.c
wait

cd ../tests
wait
ls
gcc -o tester ../utils/utils test.c

./tester
exit
