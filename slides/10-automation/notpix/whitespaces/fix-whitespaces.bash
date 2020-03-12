#!/usr/bin/env bash

cp main.cpp main.cpp.bak && cat main.cpp.bak | sed 's/\t/    /g' | sed 's/\s*$//' >main.cpp
