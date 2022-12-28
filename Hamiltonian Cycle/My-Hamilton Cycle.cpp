/*
A cycle/path can be both an Euler cycle/path and a Hamilton cycle/path.

V – E + R = 2 Euler path
a Hamiltonian cycle is a path traveling from a point back
to itself, visiting every node/vertex exactly once en route.
Eulerian cycle is a path traveling from a point back
to itself, passing through every edge exactly once.

If a graph with more than one node (i.e. a non-singleton graph)
has a Hamiltonian cycle, we call it a Hamiltonian graph.
The graph of every platonic solid is a Hamiltonian graph.
 a cube, a tetrahedron, an octahedron, or
an icosahedron are all Hamiltonian graphs with Hamiltonian cycles.

There are no loops in Halmiltonian cycles/circuits
*/

/*
Backtracking Algorithm
Create an empty path array and add vertex 0 to it.
Add other vertices, starting from the vertex 1.
Before adding a vertex, check for whether it is adjacent
to the previously added vertex and not already added.
        If we find such a vertex,
            add the vertex as part of the solution.
        Else then
            return false.
*/



//Begin
//   0.function displaytheSolution() actually prints out
//  the solution to the screen
//   1.function isSafe() is used to check for whether
//        it is adjacent to the previously added vertex
//        and already not added.
//   2. function hamiltonianCycle() solves the hamiltonian problem.
//   3. function hamCycle() uses hamiltonianCycle() to solve the
//        hamiltonian problem. - aaccepts input
//      It returns false if there is no Hamiltonian Cycle possible, otherwise return true and prints the path.
//End

#include <iostream>
//#include <cstdio>
//#include <cstdlib>
#define N 5         //5 Nodes/Vertices
using namespace std;
//const int N = 5;  alternative way to define N

void displaytheSolution(int path[]);//prototyping the displaytheSolution function first
bool isSafe(int n, bool graph[N][N],
            int path[], int pos) {
   /* Check if this vertex is an adjacent
    node/vertex of the previously added node/vertex. */
    /* Checks if there is no edge */
   if (graph [path[pos-1]][n] == 0)
      return false;
   /* Check if the node/vertex has already been included.
    This step can be optimized by creating
    an array of size n */
   for (int i = 0; i < pos; i++)
      if (path[i] == n)
         return false;
   return true;
}
bool hamiltonianCycle(bool graph[N][N],
                      int path[], int pos) {
   //If all vertices are included in Hamiltonian Cycle
   if (pos == N) {
      if (graph[ path[pos-1] ][ path[0] ] == 1)
         return true;
      else
         return false;
   }
   for (int n = 1; n < N; n++) {
      if (isSafe(n, graph, path, pos)) { //Check if this vertex can be added to Hamiltonian Cycle
         path[pos] = n;
         //recur to construct rest of the path
         if (hamiltonianCycle (graph, path, pos+1) == true)
            return true;
         path[pos] = -1; //remove vertex if it doesn’t lead to the solution
      }
   }
   return false;
}
bool hamCycle(bool graph[N][N]) {
   int *path = new int[N];
   for (int i = 0; i < N; i++)
   path[i] = -1;
   //put the vertex 0 as the first vertex in the path.
   //If there is a Hamiltonian Cycle, then the path can be started from any point
   //of the cycle as the graph is undirected
   path[0] = 0;
   if (hamiltonianCycle(graph, path, 1) == false) {
      cout<<"\nCycle does not exist"<<endl;
      return false;
   }
   displaytheSolution(path);
   return true;
}
void displaytheSolution(int p[]) {
   cout<<"Cycle Exists:";
   cout<<" Following is one Hamiltonian Cycle \n"<<endl;
   for (int i = 0; i < N; i++){
      cout<<p[i]<<" ";
   }
   cout << p[0] << endl;    //prints the first vertex/node again
}
int main() {

//    Adjacency matrix A[n][n] where n is the number of rows and columns
//    If i and j are adjacent:
//       fill with 1
//    Else:
//       fill with 0
//    Time Complexity: Theta(n ^ 2)
//    Better for dense graphs(all nodes are interconnected)
//
//    Adjacency list
//    Number of adjacent nodes and nodes added to a linked linked list
//    Time Complexity: Theta(n + 2e)
//    Better for sparse graphs
/* Let us create the following graph
         (3)--------(1)
          \ `       , |
           \  `   ,   |
            \   (2) (0)
             \   |   /
              \  |  /
               \ | /
                (4)
*/
//   bool graph[N][N] = {
//      {0, 1, 0, 0, 1},
//      {1, 0, 1, 1, 0},
//      {0, 1, 0, 1, 1},
//      {0, 1, 1, 0, 1},
//      {1, 0, 1, 1, 0},
//   };0 1 2 3 4 0


/* Let us create the following graph
        (0)--(1)--(2)
        |    / \    |
        |   /   \   |
        |  /     \  |
        (3)-------(4)
    */
//   bool graph[N][N] = {
//       {0, 1, 0, 1, 0},
//       {1, 0, 1, 1, 1},
//       {0, 1, 0, 0, 1},
//       {1, 1, 0, 0, 1},
//       {0, 1, 1, 1, 0},
//    };//0 1 2 4 3 0
/* Let us create the following graph
              _
             / \
        (0)--(1)--(2)
        |    / \    |
        |   /   \   |
        |  /     \  |
        (3)-------(4)
    */
//    bool graph[N][N] = {
//       {0, 1, 0, 1, 0},
//       {1, 1, 1, 1, 1},
//       {0, 1, 0, 0, 1},
//       {1, 1, 0, 0, 1},
//       {0, 1, 1, 1, 0},
//    };//No cycle as there is a loop at graph(2,2) which is (1,1)
/*
                    ,^,
        (0)--(1)--(2)/
        |    / \    |
        |   /   \   |
        |  /     \  |
        (3)       (4)
    */
//    bool graph[N][N] = {
//       {0, 1, 0, 1, 0},
//       {1, 0, 1, 1, 1},
//       {0, 1, 1, 0, 1},
//       {1, 1, 0, 0, 0},
//       {0, 1, 1, 0, 0},
//    };//No cycle as there is a loop at graph(2,2)

//       (0)---------(1)
//          \       /
//           \     /
//            \   /
//             (2)
//            /   \
//           /     \
//          /       \
//       (3)---------(4)

//   bool graph[N][N] = {
//       {0, 1, 1, 0, 0},
//       {1, 0, 1, 0, 0},
//       {1, 1, 0, 1, 1},
//       {0, 0, 1, 0, 1},
//       {0, 0, 1, 1, 0},
//    };//No Hamiltonian cycle, but there is an Euler Cycle
    hamCycle(graph);
   return 0;
}


