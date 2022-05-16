# CPSC2620 Winter 2016
# Prof: Dr. John Anvik
# Assignment: 4
# File: Makefile
# Purpose: Makefile for assignment 4 compilation
# Written by: Mitchel Fletcher (001162631)
# Date: 24 Feb 2016
# Adapted from the Makefile by Arie Bomhof

# Compiler choice
CCC= g++11

# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11

# all targets
all : bankTest

# the targets are dependent on .o files
# the line following  is the required executable
# Note: executables always begin with a tab.
# $^ = this target
# $@ = this/these dependencies
bankTest : config.o result.o customer.o bank.o bankTest.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
# $< = the corresponding .cc file
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# Not required lines, but convienient to have
# In the following lines, make knows that the .cc file is required in the
# current dependency so you can leave it out.  You can also leave out the
# corresponding executable line

bankTest.o : bank.h
bank.o: bank.h

bankTest.o : customer.h
customer.o : customer.h

bankTest.o : result.h
result.o : result.h

bankTest.o : config.h
config.o : config.h

clean:
	rm -f *.o *~ *% *# .#* *.out

clean-all: clean
	rm -f bankTest
