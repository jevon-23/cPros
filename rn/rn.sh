#! /bin/zsh

echo $1
exec ~/programs/cpros/rn/rn $1 &
exec /usr/local/bin/atom $1
