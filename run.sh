#!/bin/sh

if [ $1 = "caca" ]
then LD_LIBRARY_PATH=./lib ./arcade ./lib/lib_arcade_caca.so
elif [ $1 = "opengl" ]
then LD_LIBRARY_PATH=./lib ./arcade ./lib/lib_opengl_caca.so
elif [ $1 = "sfml" ]
then LD_LIBRARY_PATH=./lib ./arcade ./lib/lib_sfml_caca.so

fi
