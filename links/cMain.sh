#! /bin/zsh
cd Utils

gcc -c -o Utils Utils.c
wait
cd ..
ls
gcc -g -o  main Utils/Utils main.c
wait
exec ./main init&
wait
exec ./main add google web www.google.com&
wait
exec ./main open google web&
wait
exec ./main print
cat .allClases
