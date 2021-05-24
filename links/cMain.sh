#! /bin/zsh
cd Utils

gcc -c -o Utils Utils.c
wait
cd ..
ls
gcc -g -o  main Utils/Utils main.c
wait
echo init
exec ./main init&
wait
echo adding google
exec ./main add google web www.google.com&
wait
echo adding amazon
exec ./main add amazon web www.amazon.com&
wait
echo adding reddit
exec ./main add reddit web www.reddit.com&
wait
echo printing
exec ./main print&
wait
echo deleting
exec ./main delete amazon web&
wait
echo printing
exec ./main print&
wait
exec ./main open reddit web
