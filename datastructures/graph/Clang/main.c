typedef struct g_linked_list_t {
   struct g_node_t *node;
   struct g_node_t *next;
} g_linked_list_t;

typedef struct g_node_t {
  int value;
  struct g_linked_list_t *neighbours;
} g_node_t;

typedef struct graph_t {
  struct ...;
} graph_t;

int main(void) {

  return 0;
}
