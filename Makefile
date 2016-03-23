#Lisa Carter Justin Rice Section 1
# build an executable named amazing 
all: amazing

amazing: amazing.cpp
	g++ amazing.cpp -o amazing

clean: 
	$(RM) amazing
