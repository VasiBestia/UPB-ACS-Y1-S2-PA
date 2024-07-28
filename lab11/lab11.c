#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NODES 10
#define DENSITY 0.2
#define REGENERATE_GRAPH 1

int adj[NODES][NODES] = {0};

void generate_vertices(int* i, int* j) {
  *i = rand() % NODES;
  *j = rand() % NODES;
  while (*i == *j) {
    *j = rand() % NODES;
  }
  printf("i: %d, j: %d\n", *i, *j);
}

void generate_adj(int adj[NODES][NODES]) {
  int num_of_edges =
      rand() % ((int)(DENSITY * (NODES * (NODES - 1) / 2)) + 1) + 1;

  printf("Number of edges: %d\n", num_of_edges);
  int i, j;

  while (num_of_edges--) {
    generate_vertices(&i, &j);

    while (adj[i][j] != 0)
      generate_vertices(&i, &j);

    adj[i][j] = rand() % 30 + 1;
    adj[j][i] = adj[i][j];
  }
}

void print_adj(int adj[NODES][NODES]) {
  for (int i = 0; i < NODES; i++) {
    for (int j = 0; j < NODES; j++) {
      printf("%2d  ", adj[i][j]);
    }
    printf("\n");
  }
}

int num_of_connected_comp(int adj[NODES][NODES]) {
  int visited[NODES] = {0};
  int stack[NODES] = {0};
  int top = 0;
  int num_of_comp = 0;

  for (int i = 0; i < NODES; i++) {
    if (!visited[i]) {
      stack[top++] = i;
      visited[i] = 1;
      num_of_comp++;
    }

    while (top) {
      int node = stack[--top];
      for (int i = 0; i < NODES; i++) {
        if (adj[node][i] != 0 && !visited[i]) {
          stack[top++] = i;
          visited[i] = 1;
        }
      }
    }
  }

  return num_of_comp;
}

int check_connected(int adj[NODES][NODES]) {
  int visited[NODES] = {0};
  int stack[NODES] = {0};
  int top = 0;

  stack[top++] = 0;
  visited[0] = 1;

  while (top) {
    int node = stack[--top];
    for (int i = 0; i < NODES; i++) {
      if (adj[node][i] != 0 && !visited[i]) {
        stack[top++] = i;
        visited[i] = 1;
      }
    }
  }

  for (int i = 0; i < NODES; i++) {
    if (!visited[i]) {
      return 0;
    }
  }

  return 1;
}

void add_edges_to_make_connected(int adj[NODES][NODES]) {
  int visited[NODES] = {0};
  int stack[NODES] = {0};
  int top = 0;
  int last_visited = -1;

  for (int start_node = 0; start_node < NODES; start_node++) {
    if (!visited[start_node]) {
      // If this isn't the first component, connect it to the previous component
      if (last_visited != -1) {
        adj[last_visited][start_node] = rand() % 30 + 1;
        adj[start_node][last_visited] = adj[last_visited][start_node];
        printf("Added edge between %d and %d\n", last_visited, start_node);
      }

      // DFS
      stack[top++] = start_node;
      visited[start_node] = 1;
      while (top) {
        int node = stack[--top];
        for (int i = 0; i < NODES; i++) {
          if (adj[node][i] != 0 && !visited[i]) {
            stack[top++] = i;
            visited[i] = 1;
          }
        }
      }

      last_visited = start_node;
    }
  }
}

void save_adj_to_file(int adj[NODES][NODES]) {
  FILE* file = fopen("adj_matrix.txt", "w");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  for (int i = 0; i < NODES; i++) {
    for (int j = 0; j < NODES; j++) {
      fprintf(file, "%d ", adj[i][j]);
    }
    fprintf(file, "\n");
  }

  fclose(file);
}

void read_adj_from_file(int adj[NODES][NODES]) {
  FILE* file = fopen("adj_matrix.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  for (int i = 0; i < NODES; i++) {
    for (int j = 0; j < NODES; j++) {
      fscanf(file, "%d", &adj[i][j]);
    }
  }

  fclose(file);
}

// Djikstra's functions

int min_distance(int dist[], int visited[]) {
  int min = INT_MAX, min_index;

  for (int i = 0; i < NODES; i++) {
    if (visited[i] == 0 && dist[i] <= min) {
      min = dist[i];
      min_index = i;
    }
  }

  return min_index;
}

void dijkstra(int adj[NODES][NODES], int src) {
  int dist[NODES];
  int spset[NODES];

  for (int i = 0; i < NODES; i++) {
    dist[i] = INT_MAX;
    spset[i] = 0;
  }

  dist[src] = 0;

  for (int count = 0; count < NODES - 1; count++) {
    int u = min_distance(dist, spset);
    spset[u] = 1;

    for (int v = 0; v < NODES; v++) {
      if (!spset[v] && adj[u][v] && dist[u] != INT_MAX &&
          dist[u] + adj[u][v] < dist[v]) {
        dist[v] = dist[u] + adj[u][v];
      }
    }
  }

  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < NODES; i++) {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

int main() {
  srand(time(NULL));
  if (REGENERATE_GRAPH) {
    printf("Generating new graph...\n");
    generate_adj(adj);

    print_adj(adj);

    printf("Number of connected components: %d\n", num_of_connected_comp(adj));

    if (check_connected(adj)) {
      printf("The graph is connected\n");
    } else {
      printf("The graph is not connected\n");
      add_edges_to_make_connected(adj);
    }

    print_adj(adj);

    if (check_connected(adj)) {
      printf("The graph is now connected\n");
      save_adj_to_file(adj);
    } else {
      printf("The graph is still not connected\n");
    }
  } else {
    printf("Reading graph from file...\n");
    read_adj_from_file(adj);
    print_adj(adj);
    printf("Number of connected components: %d\n", num_of_connected_comp(adj));
  }

  dijkstra(adj, 0);

  return 0;
}