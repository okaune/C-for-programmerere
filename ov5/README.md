# Øving 5

Det er ikke ofte en burde bruke polymorfi, men et greit eksempel er å definere forskjeller på brikker i et sjakkspill gjennom polymorfi. 

Ta utgangspunkt i det forenkla sjakkspillet i `main.cpp` og fullfør implementasjonene der det står `// missing implementations`. Til slutt, når dere har fullført alle implementasjonene, skal dere få denne utskriften når dere kjører `main.cpp`:
```
Invalid moves:
no piece at e3
can not move white king from e1 to e3
can not move white knight from b1 to b2

A simulated game:
white king is moving from e1 to e2
black knight is moving from g8 to h6
white knight is moving from b1 to c3
black knight is moving from h6 to g8
white knight is moving from c3 to d5
black knight is moving from g8 to h6
white knight is moving from d5 to f6
black knight is moving from h6 to g8
white knight is moving from f6 to e8
black king is being removed from e8
black lost the game
```