rect: rectCombine.o
	g++ rectCombine.o -o rect
rectCombine.o: rectCombine.cpp rect.h testdata.hpp
	g++ -c rectCombine.cpp -o rectCombine.o
clean:
	rm -rf *.o rect
