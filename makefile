
build = build
CPP_FLAGS = -I/home/chakra/projects/CPP/boost_1_77_0/

all : heirarchy sorted_array

heirarchy : $(build)/heirarchy.o $(build)/read_csv.o $(build)/main.o
	g++ -o $@ -O3 -std=c++14 $^

sorted_array : $(build)/sorted_vector.o $(build)/read_csv.o 
	g++ -o $@ -O3 -std=c++14 $^

$(build)/sorted_vector.o : sorted_vector.cpp heirarchy.hpp
	g++ -c -o $@ -O3 -std=c++14 $<

$(build)/main.o : main.cpp heirarchy.hpp
	g++ -c -o $@ -O3 -std=c++14 $<

$(build)/heirarchy.o : heirarchy.cpp heirarchy.hpp
	g++ -c -o $@ -O3 -std=c++14 $<
    
$(build)/read_csv.o : read_csv.cpp heirarchy.hpp
	g++ -c -o $@ -O3 -std=c++14 $(CPP_FLAGS) $<

.PHONY: clean

clean:
	rm $(build)/heirarchy.o $(build)/read_csv.o heirarchy $(build)/main.o

