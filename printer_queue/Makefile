PRG=gnu.exe
GCC=g++
GCCFLAGS=-O2 -Wall -Wextra -ansi -Weffc++ -Wold-style-cast -Woverloaded-virtual -Wsign-promo  -Wctor-dtor-privacy -Wnon-virtual-dtor -Wreorder

MSC=cl
MSCFLAGS=/EHa /W4 /Za /Zc:forScope /nologo /D_CRT_SECURE_NO_DEPRECATE /D"_SECURE_SCL 0" /O2i /GL

VALGRIND_OPTIONS=-q --leak-check=full
DIFF_OPTIONS=-y --strip-trailing-cr --suppress-common-lines --ignore-trailing-space

OBJECTS0=printjob.cpp print_queue.cpp
DRIVER0=driver.cpp
OBJECTS_S=printjob.cpp print_queue.cpp
DRIVER_S=driver-example.cpp

OSTYPE := $(shell uname)
#ifeq ($(OSTYPE),Linux)
ifeq (,$(findstring CYGWIN,$(OSTYPE)))
CYGWIN=
else
CYGWIN=-Wl,--enable-auto-import
endif

gcc-sample:
	$(GCC) -o $@.exe $(CYGWIN)   $(DRIVER_S) $(OBJECTS_S) $(GCCFLAGS)
msc-sample:                                                         
	$(MSC) /Fe$@.exe             $(DRIVER_S) $(OBJECTS_S) $(MSCFLAGS) 
gcc0:
	$(GCC) -o $(PRG) $(CYGWIN) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS)
msc0:
	$(MSC) /Fe$@.exe           $(DRIVER0) $(OBJECTS0) $(MSCFLAGS) 
0 1 2 3 4 5 6 7:
	echo "running test$@"
	@echo "should run in less than 200 ms"
	./$(PRG) $@ >studentout$@
	@echo "lines after the next are mismatches with master output -- see out$@"
	diff out$@ studentout$@ $(DIFF_OPTIONS)
mem0 mem1 mem2 mem3 mem4 mem5 mem6 mem7:
	echo "running memory test $@"
	@echo "should run in less than 2000 ms"
	valgrind $(VALGRIND_OPTIONS) ./$(PRG) $(subst mem,,$@) 1>/dev/null 2>difference$@
	@echo "lines after this are memory errors"; cat difference$@
clean:
	rm -f *gcno *gcda *gcov *.exe *.o *.obj *.tds *.exe.manifest
