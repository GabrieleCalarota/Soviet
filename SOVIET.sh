#!/bin/bash
make clean
make
PS1="\[\e]0;SOVIET (by Gabriele Calarota & Alberto Drusiani)\a\]\u@\h:\w$"
./Soviet
make clean
rm Soviet
exit

