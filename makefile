Puzzle-Game:Puzzle-Game.o
	g++ -o $@ $^
.cpp.o:
	g++ -c $<

clean:
	rm -r Puzzle-Game.o
	rm -r Puzzle-Game
