#! /bin/zsh

cd Utils

gcc -c -o Utils Utils.c
wait
cd ..
ls
gcc -g -o  tester Utils/Utils test.c
wait
exec ./tester
