
dotS: main.s main-mor.s main-relacq.s main-vol.s

show-mor: dotS
	tkdiff main.s main-mor.s&

show-relacq: dotS
	tkdiff main.s main-relacq.s&

show-relacq-mor: dotS
	tkdiff main-mor.s main-relacq.s&

main.s: main.cpp
	g++ -std=c++11 -m64 -S -O2 main.cpp

main-mor.s: main-mor.cpp
	g++ -std=c++11 -m64 -S -O2 main-mor.cpp

main-relacq.s: main-relacq.cpp
	g++ -std=c++11 -m64 -S -O2 main-relacq.cpp

main-vol.s: main-volatile.cpp
	g++ -std=c++11 -m64 -S -O2 main-volatile.cpp

clean:
	rm -rf *.s
