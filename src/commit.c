#include "commit.h"

void commit_create(Index *idx, const char *message) {
    char *tree_hash = tree_from_index(idx);

    char content[1024];
    sprintf(content,
            "tree %s\nauthor %s\n\n%s\n",
            tree_hash,
            pes_author(),
            message);

    char hash[65];
    object_write("commit", content, strlen(content), hash);

    FILE *f = fopen(".pes/refs/heads/main", "w");
    fprintf(f, "%s", hash);
    fclose(f);

    printf("Committed: %s\n", hash);
}