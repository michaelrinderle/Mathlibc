#pragma once
#include <datatypes/data/hash.h>

void*
hash_init(hash_type type)
{
    switch (type)
    {
        case HASH_I32_T:
        {
            hash_i32_t* hash = (hash_i32_t*)malloc(sizeof(hash_i32_t));
            hash->hash_info.type = type;
            hash->hash_info.table_size = INITIAL_HASH_TABLE_SIZE;
            hash->hash_info.size = 0;
            hash->table = (hashkv_i32_t*)calloc(INITIAL_HASH_TABLE_SIZE, sizeof(hashkv_i32_t));
            return hash;
        }
        case HASH_I64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)malloc(sizeof(hash_i64_t));
            hash->hash_info.type = type;
            hash->hash_info.table_size = INITIAL_HASH_TABLE_SIZE;
            hash->hash_info.size = 0;
            hash->table = (hashkv_i64_t*)calloc(INITIAL_HASH_TABLE_SIZE, sizeof(hashkv_i64_t));
            return hash;
        }
        case HASH_U32_T:
        {
            hash_u32_t* hash = (hash_u32_t*)malloc(sizeof(hash_u32_t));
            hash->hash_info.type = type;
            hash->hash_info.table_size = INITIAL_HASH_TABLE_SIZE;
            hash->hash_info.size = 0;
            hash->table = (hashkv_u32_t*)calloc(INITIAL_HASH_TABLE_SIZE, sizeof(hashkv_u32_t));
            return hash;
        }
        case HASH_U64_T:
        {
            hash_u64_t* hash = (hash_u64_t*)malloc(sizeof(hash_u64_t));
            hash->hash_info.type = type;
            hash->hash_info.table_size = INITIAL_HASH_TABLE_SIZE;
            hash->hash_info.size = 0;
            hash->table = (hashkv_u64_t*)calloc(INITIAL_HASH_TABLE_SIZE, sizeof(hashkv_u64_t));
            return hash;
        }
        case HASH_F32_T:
        {
            hash_f32_t* hash = (hash_f32_t*)malloc(sizeof(hash_f32_t));
            hash->hash_info.type = type;
            hash->hash_info.table_size = INITIAL_HASH_TABLE_SIZE;
            hash->hash_info.size = 0;
            hash->table = (hashkv_f32_t*)calloc(INITIAL_HASH_TABLE_SIZE, sizeof(hashkv_f32_t));
            return hash;
        }
        case HASH_F64_T:
        {
            hash_f64_t* hash = (hash_f64_t*)malloc(sizeof(hash_f64_t));
            hash->hash_info.type = type;
            hash->hash_info.table_size = INITIAL_HASH_TABLE_SIZE;
            hash->hash_info.size = 0;
            hash->table = (hashkv_f64_t*)calloc(INITIAL_HASH_TABLE_SIZE, sizeof(hashkv_f64_t));
            return hash;
        }
        default:
        {
            fprintf(stderr, "[*] hash_init: unsupported list type\n");
            return NULL;
        }
    }
}

bool
hash_free(void* self)
{
    if (!self) return false;

    hash_info_t* hash_info = (hash_info_t*)self;

    switch (hash_info->type)
    {
        case HASH_I32_T:
        {
            free(((hash_i32_t*)self)->table);
            break;
        }
        case HASH_I64_T:
        {
            free(((hash_i64_t*)self)->table);
            break;
        }
        case HASH_U32_T:
        {
            free(((hash_u32_t*)self)->table);
            break;
        }
        case HASH_U64_T:
        {
            free(((hash_u64_t*)self)->table);
            break;
        }
        case HASH_F32_T:
        {
            free(((hash_f32_t*)self)->table);
            break;
        }
        case HASH_F64_T:
        {
            free(((hash_f64_t*)self)->table);
            break;
        }
        default:
                return false;
    }

    free(self);
    return true;
}

bool
hash_append(void* self, char* key, void* data)
{
    if (!self || !key || !data) return false;

    hash_info_t* hash_info = (hash_info_t*)self;

    // check load factor and resize if necessary
    if (hash_info->size * 2 >= hash_info->table_size)
    {
        if (!_hash_resize(self))
        {
            return false;
        }
    }

    uint hash_index = _hash_key(key) % hash_info->table_size;
    uint original_index = hash_index;

    switch (hash_info->type)
    {
        case HASH_I32_T:
        {
            hash_i32_t* hash = (hash_i32_t*)self;
            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].data = *(i32*)data;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) return false; // Table is full
            }
            strcpy(hash->table[hash_index].key, key);
            hash->table[hash_index].data = *(i32*)data;
            hash_info->size++;
            break;
        }
        case HASH_I64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)self;
            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].data = *(i64*)data;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) return false; // Table is full
            }
            strcpy(hash->table[hash_index].key, key);
            hash->table[hash_index].data = *(i64*)data;
            hash_info->size++;
            break;
        }
        case HASH_U32_T:
        {
            hash_u32_t* hash = (hash_u32_t*)self;
            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].data = *(u32*)data;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) return false; // Table is full
            }
            strcpy(hash->table[hash_index].key, key);
            hash->table[hash_index].data = *(u32*)data;
            hash_info->size++;
            break;
        }
        case HASH_U64_T:
        {
            hash_u64_t* hash = (hash_u64_t*)self;
            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].data = *(u64*)data;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) return false; // Table is full
            }
            strcpy(hash->table[hash_index].key, key);
            hash->table[hash_index].data = *(u64*)data;
            hash_info->size++;
            break;
        }
        case HASH_F32_T:
        {
            hash_f32_t* hash = (hash_f32_t*)self;
            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].data = *(f32*)data;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) return false; // Table is full
            }
            strcpy(hash->table[hash_index].key, key);
            hash->table[hash_index].data = *(f32*)data;
            hash_info->size++;
            break;
        }
        case HASH_F64_T:
        {
            hash_f64_t* hash = (hash_f64_t*)self;
            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].data = *(f64*)data;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) return false; // Table is full
            }
            strcpy(hash->table[hash_index].key, key);
            hash->table[hash_index].data = *(f64*)data;
            hash_info->size++;
            break;
        }
        default:
        {
            fprintf(stderr, "[*] hash_append: unsupported hash type\n");
            return false;
        }
    }

    return true;
}

bool
hash_clear(void* self)
{
    if (!self) return false;

    hash_info_t* hash_info = (hash_info_t*)self;

    switch (hash_info->type)
    {
        case HASH_I32_T:
        {
            hash_i32_t* hash = (hash_i32_t*)self;
            for (uint i = 0; i < hash_info->table_size; i++)
            {
                hash->table[i].key[0] = '\0';
            }
            hash_info->size = 0;
            break;
        }
        case HASH_I64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)self;
            for (uint i = 0; i < hash_info->table_size; i++)
            {
                hash->table[i].key[0] = '\0';
            }
            hash_info->size = 0;
            break;
        }
        case HASH_U32_T:
        {
            hash_u32_t* hash = (hash_u32_t*)self;
            for (uint i = 0; i < hash_info->table_size; i++)
            {
                hash->table[i].key[0] = '\0';
            }
            hash_info->size = 0;
            break;
        }
        case HASH_U64_T:
        {
            hash_u64_t* hash = (hash_u64_t*)self;
            for (uint i = 0; i < hash_info->table_size; i++)
            {
                hash->table[i].key[0] = '\0';
            }
            hash_info->size = 0;
            break;
        }
        case HASH_F32_T:
        {
            hash_f32_t* hash = (hash_f32_t*)self;
            for (uint i = 0; i < hash_info->table_size; i++)
            {
                hash->table[i].key[0] = '\0';
            }
            hash_info->size = 0;
            break;
        }
        case HASH_F64_T:
        {
            hash_f64_t* hash = (hash_f64_t*)self;
            for (uint i = 0; i < hash_info->table_size; i++)
            {
                hash->table[i].key[0] = '\0';
            }
            hash_info->size = 0;
            break;
        }
        default:
        {
            fprintf(stderr, "[*] hash_clear: unsupported hash type\n");
            return false;
        }
    }

    return true;
}

bool
hash_contains(void* self, char* key)
{
    if (!self || !key) return false;

    hash_info_t* hash_info = (hash_info_t*)self;

    switch (hash_info->type)
    {
        case HASH_I32_T:
        {
            hash_i32_t* hash = (hash_i32_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_I64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_U32_T:
        {
            hash_u32_t* hash = (hash_u32_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_U64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_F32_T:
        {
            hash_f32_t* hash = (hash_f32_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_F64_T:
        {
            hash_f64_t* hash = (hash_f64_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        default:
        {
            fprintf(stderr, "[*] hash_contains: unsupported hash type\n");
            return false;
        }
    }

    return false;
}

bool
hash_remove(void* self, char* key)
{
    if (!self || !key) return false;

    hash_info_t* hash_info = (hash_info_t*)self;

    switch (hash_info->type)
    {
        case HASH_I32_T:
        {
            hash_i32_t* hash = (hash_i32_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].key[0] = '\0'; // mark slot as empty
                    hash_info->size--;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_I64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].key[0] = '\0'; // mark slot as empty
                    hash_info->size--;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_U32_T:
        {
            hash_u32_t* hash = (hash_u32_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].key[0] = '\0'; // mark slot as empty
                    hash_info->size--;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_U64_T:
        {
            hash_u64_t* hash = (hash_u64_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].key[0] = '\0'; // mark slot as empty
                    hash_info->size--;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_F32_T:
        {
            hash_f32_t* hash = (hash_f32_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].key[0] = '\0'; // mark slot as empty
                    hash_info->size--;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        case HASH_F64_T:
        {
            hash_f64_t* hash = (hash_f64_t*)self;
            uint hash_index = _hash_key(key) % hash_info->table_size;
            uint original_index = hash_index;

            while (hash->table[hash_index].key[0] != '\0')
            {
                if (strcmp(hash->table[hash_index].key, key) == 0)
                {
                    hash->table[hash_index].key[0] = '\0'; // mark slot as empty
                    hash_info->size--;
                    return true;
                }
                hash_index = (hash_index + 1) % hash_info->table_size;
                if (hash_index == original_index) break;
            }
            break;
        }
        default:
        {
            fprintf(stderr, "[*] hash_remove: unsupported hash type\n");
            return false;
        }
    }

    return false;
}

bool
hash_replace(void* self, char* key, void* data) {
    if (!self || !key || !data) return false;

    switch (((hash_info_t*)self)->type)
    {
        case HASH_I32_T:
        {
            hash_i32_t* hash = (hash_i32_t*)self;
            uint index = _hash_key(key) % hash->hash_info.table_size;
            for (uint i = 0; i < hash->hash_info.table_size; ++i)
            {
                if (strcmp(hash->table[index].key, key) == 0)
                {
                    hash->table[index].data = *(i32*)data;
                    return true;
                }
                index = (index + 1) % hash->hash_info.table_size;
            }

            return false;
        }
        case HASH_I64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)self;
            uint index = _hash_key(key) % hash->hash_info.table_size;
            for (uint i = 0; i < hash->hash_info.table_size; ++i)
            {
                if (strcmp(hash->table[index].key, key) == 0)
                {
                    hash->table[index].data = *(i64*)data;
                    return true;
                }
                index = (index + 1) % hash->hash_info.table_size;
            }

            return false;
        }
        case HASH_U32_T:
        {
            hash_u32_t* hash = (hash_u32_t*)self;
            uint index = _hash_key(key) % hash->hash_info.table_size;
            for (uint i = 0; i < hash->hash_info.table_size; ++i)
            {
                if (strcmp(hash->table[index].key, key) == 0)
                {
                    hash->table[index].data = *(u32*)data;
                    return true;
                }
                index = (index + 1) % hash->hash_info.table_size;
            }

            return false;
        }
        case HASH_U64_T:
        {
            hash_u64_t* hash = (hash_u64_t*)self;
            uint index = _hash_key(key) % hash->hash_info.table_size;
            for (uint i = 0; i < hash->hash_info.table_size; ++i)
            {
                if (strcmp(hash->table[index].key, key) == 0)
                {
                    hash->table[index].data = *(u64*)data;
                    return true;
                }
                index = (index + 1) % hash->hash_info.table_size;
            }

            return false;
        }
        case HASH_F32_T:
        {
            hash_f32_t* hash = (hash_f32_t*)self;
            uint index = _hash_key(key) % hash->hash_info.table_size;
            for (uint i = 0; i < hash->hash_info.table_size; ++i)
            {
                if (strcmp(hash->table[index].key, key) == 0)
                {
                    hash->table[index].data = *(f32*)data;
                    return true;
                }
                index = (index + 1) % hash->hash_info.table_size;
            }

            return false;
        }
        case HASH_F64_T:
        {
            hash_f64_t* hash = (hash_f64_t*)self;
            uint index = _hash_key(key) % hash->hash_info.table_size;
            for (uint i = 0; i < hash->hash_info.table_size; ++i)
            {
                if (strcmp(hash->table[index].key, key) == 0)
                {
                    // Key found, replace the data
                    hash->table[index].data = *(f64*)data;
                    return true;
                }
                index = (index + 1) % hash->hash_info.table_size;
            }

            return false;
        }
        default: {
            fprintf(stderr, "[*] hash_replace: unsupported hash type\n");
            return false;
        }
    }
}

u32
hash_size(void* self)
{
    if (!self) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;

    return hash_info->size;
}

u32
_hash_key(char* key)
{
    // djb2 hash algorithm
    uint hash = 5381;
    uint c;

    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return (u32)hash;
}

i32
_hash_get_i32(void* self, char* key)
{
    if (!self || !key) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;

    if (hash_info->type != HASH_I32_T)
    {
        fprintf(stderr, "[*] hash_get_i32: wrong hash type\n");
        return NULL_VAL;
    }

    hash_i32_t* hash = (hash_i32_t*)self;
    uint hash_index = _hash_key(key) % hash_info->table_size;
    uint original_index = hash_index;

    while (hash->table[hash_index].key[0] != '\0')
    {
        if (strcmp(hash->table[hash_index].key, key) == 0)
        {
            return hash->table[hash_index].data;
        }
        hash_index = (hash_index + 1) % hash_info->table_size;
        if (hash_index == original_index) break;
    }

    fprintf(stderr, "[*] hash_get_i32: key not found\n");
    return NULL_VAL;
}

i64
_hash_get_i64(void* self, char* key)
{
    if (!self || !key) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;

    if (hash_info->type != HASH_I64_T)
    {
        fprintf(stderr, "[*] hash_get_i64: wrong hash type\n");
        return NULL_VAL;
    }

    hash_i64_t* hash = (hash_i64_t*)self;
    uint hash_index = _hash_key(key) % hash_info->table_size;
    uint original_index = hash_index;

    while (hash->table[hash_index].key[0] != '\0')
    {
        if (strcmp(hash->table[hash_index].key, key) == 0)
        {
            return hash->table[hash_index].data;
        }
        hash_index = (hash_index + 1) % hash_info->table_size;
        if (hash_index == original_index) break;
    }

    fprintf(stderr, "[*] hash_get_i64: key not found\n");
    return NULL_VAL;
}

u32
_hash_get_u32(void* self, char* key)
{
    if (!self || !key) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;

    if (hash_info->type != HASH_U32_T)
    {
        fprintf(stderr, "[*] hash_get_u32: wrong hash type\n");
        return NULL_VAL;
    }

    hash_u32_t* hash = (hash_u32_t*)self;
    uint hash_index = _hash_key(key) % hash_info->table_size;
    uint original_index = hash_index;

    while (hash->table[hash_index].key[0] != '\0')
    {
        if (strcmp(hash->table[hash_index].key, key) == 0)
        {
            return hash->table[hash_index].data;
        }
        hash_index = (hash_index + 1) % hash_info->table_size;
        if (hash_index == original_index) break;
    }

    fprintf(stderr, "[*] hash_get_i32: key not found\n");
    return NULL_VAL;
}

u64
_hash_get_u64(void* self, char* key)
{
    if (!self || !key) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;

    if (hash_info->type != HASH_U64_T)
    {
        fprintf(stderr, "[*] hash_get_u64: wrong hash type\n");
        return NULL_VAL;
    }

    hash_u64_t* hash = (hash_u64_t*)self;
    uint hash_index = _hash_key(key) % hash_info->table_size;
    uint original_index = hash_index;

    while (hash->table[hash_index].key[0] != '\0')
    {
        if (strcmp(hash->table[hash_index].key, key) == 0)
        {
            return hash->table[hash_index].data;
        }
        hash_index = (hash_index + 1) % hash_info->table_size;
        if (hash_index == original_index) break;
    }

    fprintf(stderr, "[*] hash_get_i64: key not found\n");
    return NULL_VAL;
}

f32
_hash_get_f32(void* self, char* key)
{
    if (!self || !key) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;

    if (hash_info->type != HASH_F32_T)
    {
        fprintf(stderr, "[*] hash_get_f32: wrong hash type\n");
        return NULL_VAL;
    }

    hash_f32_t* hash = (hash_f32_t*)self;
    uint hash_index = _hash_key(key) % hash_info->table_size;
    uint original_index = hash_index;

    while (hash->table[hash_index].key[0] != '\0')
    {
        if (strcmp(hash->table[hash_index].key, key) == 0)
        {
            return hash->table[hash_index].data;
        }
        hash_index = (hash_index + 1) % hash_info->table_size;
        if (hash_index == original_index) break;
    }

    fprintf(stderr, "[*] hash_get_f32: key not found\n");
    return NULL_VAL;
}

f64
_hash_get_f64(void* self, char* key)
{
    if (!self || !key) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;

    if (hash_info->type != HASH_F64_T)
    {
        fprintf(stderr, "[*] hash_get_f64: wrong hash type\n");
        return NULL_VAL;
    }

    hash_f64_t* hash = (hash_f64_t*)self;
    uint hash_index = _hash_key(key) % hash_info->table_size;
    uint original_index = hash_index;

    while (hash->table[hash_index].key[0] != '\0')
    {
        if (strcmp(hash->table[hash_index].key, key) == 0)
        {
            return hash->table[hash_index].data;
        }
        hash_index = (hash_index + 1) % hash_info->table_size;
        if (hash_index == original_index) break;
    }

    fprintf(stderr, "[*] hash_get_f64: key not found\n");
    return NULL_VAL;
}

f32
_hash_load_factor(void* self) {
    if (!self) return NULL_VAL;

    hash_info_t* hash_info = (hash_info_t*)self;
    return (f32)hash_info->size / (f32)hash_info->table_size;
}

bool
_hash_resize(void* self)
{
    if (!self) return false;

    hash_info_t* hash_info = (hash_info_t*)self;
    uint new_table_size = hash_info->table_size * 2;
    if (new_table_size > MAX_HASH_TABLE_SIZE) return false; // Prevent excessive resizing

    switch (hash_info->type) {
        case HASH_I32_T:
        {
            hash_i32_t* hash = (hash_i32_t*)self;
            hashkv_i32_t* new_table = (hashkv_i32_t*)calloc(new_table_size, sizeof(hashkv_i32_t));
            if (!new_table) return false;

            for (uint i = 0; i < hash_info->table_size; i++)
            {
                if (hash->table[i].key[0] != '\0')
                {
                    u32 new_index = _hash_key(hash->table[i].key) % new_table_size;
                    while (new_table[new_index].key[0] != '\0')
                    {
                        new_index = (new_index + 1) % new_table_size;
                    }
                    strcpy(new_table[new_index].key, hash->table[i].key);
                    new_table[new_index].data = hash->table[i].data;
                }
            }

            free(hash->table);
            hash->table = new_table;
            hash_info->table_size = new_table_size;
            break;
        }
        case HASH_I64_T:
        {
            hash_i64_t* hash = (hash_i64_t*)self;
            hashkv_i64_t* new_table = (hashkv_i64_t*)calloc(new_table_size, sizeof(hashkv_i64_t));
            if (!new_table) return false;

            for (uint i = 0; i < hash_info->table_size; i++)
            {
                if (hash->table[i].key[0] != '\0')
                {
                    uint new_index = _hash_key(hash->table[i].key) % new_table_size;
                    while (new_table[new_index].key[0] != '\0')
                    {
                        new_index = (new_index + 1) % new_table_size;
                    }
                    strcpy(new_table[new_index].key, hash->table[i].key);
                    new_table[new_index].data = hash->table[i].data;
                }
            }

            free(hash->table);
            hash->table = new_table;
            hash_info->table_size = new_table_size;
            break;
        }
        case HASH_U32_T:
        {
            hash_u32_t* hash = (hash_u32_t*)self;
            hashkv_u32_t* new_table = (hashkv_u32_t*)calloc(new_table_size, sizeof(hashkv_u32_t));
            if (!new_table) return false;

            for (uint i = 0; i < hash_info->table_size; i++)
            {
                if (hash->table[i].key[0] != '\0')
                {
                    uint new_index = _hash_key(hash->table[i].key) % new_table_size;
                    while (new_table[new_index].key[0] != '\0')
                    {
                        new_index = (new_index + 1) % new_table_size;
                    }
                    strcpy(new_table[new_index].key, hash->table[i].key);
                    new_table[new_index].data = hash->table[i].data;
                }
            }

            free(hash->table);
            hash->table = new_table;
            hash_info->table_size = new_table_size;
            break;
        }
        case HASH_U64_T:
        {
            hash_u64_t* hash = (hash_u64_t*)self;
            hashkv_u64_t* new_table = (hashkv_u64_t*)calloc(new_table_size, sizeof(hashkv_u64_t));
            if (!new_table) return false;

            for (uint i = 0; i < hash_info->table_size; i++)
            {
                if (hash->table[i].key[0] != '\0')
                {
                    uint new_index = _hash_key(hash->table[i].key) % new_table_size;
                    while (new_table[new_index].key[0] != '\0')
                    {
                        new_index = (new_index + 1) % new_table_size;
                    }
                    strcpy(new_table[new_index].key, hash->table[i].key);
                    new_table[new_index].data = hash->table[i].data;
                }
            }

            free(hash->table);
            hash->table = new_table;
            hash_info->table_size = new_table_size;
            break;
        }
        case HASH_F32_T:
        {
            hash_f32_t* hash = (hash_f32_t*)self;
            hashkv_f32_t* new_table = (hashkv_f32_t*)calloc(new_table_size, sizeof(hashkv_f32_t));
            if (!new_table) return false;

            for (uint i = 0; i < hash_info->table_size; i++)
            {
                if (hash->table[i].key[0] != '\0')
                {
                    uint new_index = _hash_key(hash->table[i].key) % new_table_size;
                    while (new_table[new_index].key[0] != '\0')
                    {
                        new_index = (new_index + 1) % new_table_size;
                    }
                    strcpy(new_table[new_index].key, hash->table[i].key);
                    new_table[new_index].data = hash->table[i].data;
                }
            }

            free(hash->table);
            hash->table = new_table;
            hash_info->table_size = new_table_size;
            break;
        }
        case HASH_F64_T:
        {
            hash_f64_t* hash = (hash_f64_t*)self;
            hashkv_f64_t* new_table = (hashkv_f64_t*)calloc(new_table_size, sizeof(hashkv_f64_t));
            if (!new_table) return false;

            for (uint i = 0; i < hash_info->table_size; i++)
            {
                if (hash->table[i].key[0] != '\0')
                {
                    uint new_index = _hash_key(hash->table[i].key) % new_table_size;
                    while (new_table[new_index].key[0] != '\0')
                    {
                        new_index = (new_index + 1) % new_table_size;
                    }
                    strcpy(new_table[new_index].key, hash->table[i].key);
                    new_table[new_index].data = hash->table[i].data;
                }
            }

            free(hash->table);
            hash->table = new_table;
            hash_info->table_size = new_table_size;
            break;
        }
        default:
        {
            fprintf(stderr, "[*] _hash_resize: unsupported hash type\n");
            return NULL;
        }
    }

    return true;
}