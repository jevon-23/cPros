#! /bin/zsh

echo $1
exec ~/programs/cpros/starter/start $1 &
exec /usr/local/bin/atom $1