#! /bin/zsh

echo $1
exec ~/programs/cpros/starter/main $1 $2 &
exec /usr/local/bin/atom $1
