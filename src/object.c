#include "pes.h"
#include <openssl/sha.h>

int object_write(const char *type, const void *data, size_t size, char *hash_out) {
    char header[64];
    int header_len = sprintf(header, "%s %zu", type, size) + 1;

    size_t total = header_len + size;
    unsigned char *buffer = malloc(total);
    memcpy(buffer, header, header_len);
    memcpy(buffer + header_len, data, size);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(buffer, total, hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(hash_out + i * 2, "%02x", hash[i]);

    char dir[256], path[256];
    sprintf(dir, ".pes/objects/%.2s", hash_out);
    mkdir(dir, 0755);

    sprintf(path, "%s/%s", dir, hash_out + 2);

    FILE *f = fopen(path, "wb");
    fwrite(buffer, 1, total, f);
    fclose(f);

    free(buffer);
    return 0;
}

int object_read(const char *hash, char **type, void **data, size_t *size) {
    char path[256];
    sprintf(path, ".pes/objects/%.2s/%s", hash, hash + 2);

    FILE *f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    size_t total = ftell(f);
    rewind(f);

    char *buffer = malloc(total);
    fread(buffer, 1, total, f);
    fclose(f);

    *type = buffer;
    char *nul = memchr(buffer, '\0', total);
    *size = total - (nul - buffer + 1);

    *data = nul + 1;
    return 0;
}