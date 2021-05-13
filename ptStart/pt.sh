#! /bin/zsh

echo $1
exec ~/programs/cpros/ptStart/pt $1 &
exec /usr/local/bin/atom $1
