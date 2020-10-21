
.PHONY: build

build:
	g++ ./cmdparser.cpp -o cmdpar

help:
	./cmdpar -h

.PHONY: example

example:
	./cmdpar -V20 --value=10 -l -L

default_goal: build example 

.DEFAULT_GOAL:=default_goal