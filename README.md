# LemiPC
Semaphores and Segments of SharedMemory

The goal is to fight players (divided between several teams) on a two-dimensional game board.
The last team standing wins.  

To kill a player, a minimum of two players from the same team (and different from the first) must be
in contact with the other player. This means on a square next to the one where the player you want
to kill is standing (including diagonally).  

The players will be able to move both vertically and horizontally.  

When a player realizes he/she is surrounded by at least 2 players from the opposing team,
he/she must leave the game board.  

A square cannot hold more than one player at a time.

./lemipc PATH TEAM_NUMBER
-------------------------


| Parameters       | Description                                              |
| ---------------: | ---------------------------------------------------------|
| **PATH**         | path you’ll give to ftok (file, folder ... valid path !) |
| **TEAM_NUMBER**  | team number of the current champion (greater than 0)     |
