#include "tree.h"

char *tree_from_index(Index *index) {
    // Simplified: single-level tree
    char *tree_data = malloc(1024);
    tree_data[0] = '\0';

    for (int i = 0; i < index->count; i++) {
        char line[256];
        sprintf(line, "%o blob %s %s\n",
                index->entries[i].mode,
                index->entries[i].hash,
                index->entries[i].path);
        strcat(tree_data, line);
    }

    char *hash = malloc(65);
    object_write("tree", tree_data, strlen(tree_data), hash);

    free(tree_data);
    return hash;
}