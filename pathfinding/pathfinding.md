# Maze Algorithm

This year, we want diagonals, we're fancy people. In order to do this, we need to redo the maze algorithm. Our previous algorithm was floodfill, but it was quite a constraint. 


## Modifications

- The maze needs to be twice as big, to account for the spot between two cells. For this, we need to use floats instead of integer types. 

```cpp
typedef struct{
  float weight;
  point parent;
  bool visited;
} cell;
```

For exploration, we'll use floodfill, and for the final run, we'll use A star to find the destination.

### Encodings

- When we initialize, we initialize everything to -1. 
- We encode walls as -2

### Floodfill

Floodfill is a popular algorithm for micromouse. Even if you don't know what the maze looks like, you can find the center without exploring a lot of nodes, or cells. There are many resources on it, so it's not worth opening up that can of worms. 

#### Floodfill changes

- In the previous version, we used characters for the turns:
  - n: north
  - s: south
  - e: east
  - w: west

Because of the use of A star, we need to change the encodings, because we can no longer use characters for the diagonal directions.

### A Star Algorithm

The A 