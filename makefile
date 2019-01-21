#*****************************************************************************
# Nicholas Rucker                                                            *
# nrucker                                                                    *
# CPSC 1020 Fall 2018                                                        *
# Section 2 (M.W.F 10:10 - 11:00)                                            *
# PA 3                                                                       *
# Make file.  Offers make and make run commands.			     									 *
#****************************************************************************/ 
make:
	@echo " "
	@echo "About to compile"
	@echo " "
	g++ -Wall -g  -std=c++11 mainDriver.cpp picture.cpp header.cpp pixel.cpp circle.cpp point.cpp triangle.cpp quad.cpp shape.cpp
	@echo " "
	@echo "Your program has compiled!"
	@echo " "
run:
	@echo " "
	@echo "About to run executable"
	@echo " "
	./a.out input.txt opticalIllusion.ppm
	@echo " "
	@echo "Program has been run"
	@echo " "