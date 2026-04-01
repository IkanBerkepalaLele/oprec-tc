#!/bin/bash
echo $FLAG > /home/compfest18/flag.txt
exec socat TCP-LISTEN:4321,reuseaddr,fork EXEC:./gema