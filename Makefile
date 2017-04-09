rect: rectCombine.o
	g++ rectCombine.0 -o rect
rectCombine.o: rectCombine.cpp rect.h testdata.hpp
	g++ -c rectCombine.cc -o rectCombine.o
clean:
	rm -rf *.o rect
