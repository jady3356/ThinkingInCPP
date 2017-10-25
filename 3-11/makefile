gc=g++

main: main.o employee.o 
	g++ -o $@ $^ #$@表示当前目标名，main？$^ 表示所有的依赖: main.o 和employee.o

#main.o: main.cpp employee.h
#	$(gc) -c $< #$<表示第一个依赖文件main.cpp

#employee.o: employee.cpp employee.h
#	$(gc) -c $<
.cpp.o:
	$(gc) -c $<
clean:
	rm *.o main