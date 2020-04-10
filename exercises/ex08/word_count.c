#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>


#define  MAXCHAR 1000

void hash_pairs(const char *key, const int value) {
  g_print("%s: %d\n", key, value);
}

int main() {

  // Create hash table
  GHashTable *ht = g_hash_table_new(g_str_hash, g_str_equal);
  char *buffer = malloc(MAXCHAR*sizeof(char*));

  // Open text file with excerpt from Project Gutenburg
  FILE *file = fopen("pg17208.txt","rb");
  if (file == NULL) {
    puts("ERROR: NO FILE FOUND\n");
    exit(1);
  }

  // Read file line by line until the end of the file is reached
  while (fscanf(file, "%s\n", buffer) != EOF) {

    // Determine if key is in hash table
    if (g_hash_table_contains(ht,buffer)){
      // Increment the value of key by one
      g_hash_table_replace(ht, g_strdup(buffer), g_hash_table_lookup(ht, buffer)+1);
    } else {
      // Add key to hash table with value of 1
      g_hash_table_insert(ht, g_strdup(buffer), GINT_TO_POINTER(1));
    }
  }

  fclose(file);
  g_hash_table_foreach(ht, (GHFunc)hash_pairs, NULL);

}
