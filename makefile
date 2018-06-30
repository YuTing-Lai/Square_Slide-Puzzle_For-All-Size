Puzzle-Game:Puzzle-Game.o
	$(cc) -o $@ $^
.c.o:
	$(cc) -c $<

clean:
	rm -r Puzzle-Game.o