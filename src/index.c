#include "index.h"

void index_load(Index *idx) {
    FILE *f = fopen(".pes/index", "r");
    idx->count = 0;

    if (!f) return;

    while (!feof(f)) {
        IndexEntry *e = &idx->entries[idx->count];
        fscanf(f, "%o %s %ld %ld %s",
               &e->mode, e->hash, &e->mtime, &e->size, e->path);
        idx->count++;
    }
    fclose(f);
}

void index_save(Index *idx) {
    FILE *f = fopen(".pes/index", "w");

    for (int i = 0; i < idx->count; i++) {
        IndexEntry *e = &idx->entries[i];
        fprintf(f, "%o %s %ld %ld %s\n",
                e->mode, e->hash, e->mtime, e->size, e->path);
    }
    fclose(f);
}

void index_add(Index *idx, const char *path) {
    FILE *f = fopen(path, "rb");

    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);

    char *data = malloc(size);
    fread(data, 1, size, f);
    fclose(f);

    char hash[65];
    object_write("blob", data, size, hash);

    IndexEntry *e = &idx->entries[idx->count++];
    strcpy(e->path, path);
    strcpy(e->hash, hash);
    e->size = size;
    e->mode = 100644;

    free(data);
}