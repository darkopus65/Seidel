# sidel

This code realize the sidel's algoritm for the all-pairs-shortest-path problem for undirected, unweighted, connected graphs. 

A function sidel get connection square matrix and size of it and return new matrix where at each row and column intersection stay the count of edges from shortest path between these two vertices. 

Three help functions:
1. multiply - matrix multiplication 
2. readfile - read matrix from file
3. writefile - write matrix in file


To run code:
1. Open root of project in terminal
2. Run commands:
  ccmake . 
  make
