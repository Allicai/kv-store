#include "kvstore.h"


// Exercise 4: finish implementing kvstore
// TODO: define your synchronization variables here
// (hint: don't forget to initialize them)

static pthread_mutex_t kv_mutex = PTHREAD_MUTEX_INITIALIZER;

/* read a key from the key-value store.
 *
 * if key exists, set "val" to be the value and return 0.
 * if key doesn't exist, return 1.
 *
 * NOTE: kv-store must be implemented as a monitor.
 */
int kv_read(kvstore_t *kv, char *key, int *val) {
    /* TODO: your code here */


    pthread_mutex_lock(&kv_mutex);
    // Critical section
    for (int i = 0; i < TABLE_MAX; ++i) {
        if (kv->keys[i].stat == 1 && strcmp(kv->keys[i].key, key) == 0) {
            *val = kv->values[i];
            pthread_mutex_unlock(&kv_mutex);
            return 0; // Key found, return success
        }
    }
    pthread_mutex_unlock(&kv_mutex);
    return 1; // Key not found, return failure
}


/* write a key-value pair into the kv-store.
 *
 * - if the key exists, overwrite the old value.
 * - if key doesn't exit,
 *     -- insert one if the number of keys is smaller than TABLE_MAX
 *     -- return failure if the number of keys equals TABLE_MAX
 * - return 0 for success; return 1 for failures.
 *
 * notes:
 * - the input "key" locates somewhere out of your control, you must copy the
 *   string to kv-store's own memory. (hint: use strcpy)
 *
 * NOTE: kv-store must be implemented as a monitor.
 */

int kv_write(kvstore_t *kv, char *key, int val) {
    /* TODO: your code here */

    pthread_mutex_lock(&kv_mutex);
    // Critical section
    for (int i = 0; i < TABLE_MAX; ++i) {
        if (kv->keys[i].stat == 1 && strcmp(kv->keys[i].key, key) == 0) {
            kv->values[i] = val; // Update value
            pthread_mutex_unlock(&kv_mutex);
            return 0; // Key found, value updated, return success
        }
    }
    for (int i = 0; i < TABLE_MAX; ++i) {
        if (kv->keys[i].stat == 0) {
            strcpy(kv->keys[i].key, key); // Insert new key
            kv->values[i] = val; // Insert value
            kv->keys[i].stat = 1; // Mark as used
            pthread_mutex_unlock(&kv_mutex);
            return 0; // Inserted new key-value pair, return success
        }
    }
    pthread_mutex_unlock(&kv_mutex);
    return 1; // Table full, return failure
}


/* delete a key-value pair from the kv-store.
 *
 * - if the key exists, delete it.
 * - if the key doesn't exits, do nothing.
 *
 * NOTE: kv-store must be implemented as a monitor.
 */
void kv_delete(kvstore_t *kv, char *key) {
    /* TODO: your code here */


    pthread_mutex_lock(&kv_mutex);
    // Critical section
    for (int i = 0; i < TABLE_MAX; ++i) {
        if (kv->keys[i].stat == 1 && strcmp(kv->keys[i].key, key) == 0) {
            kv->keys[i].stat = 0; // Mark as free
            pthread_mutex_unlock(&kv_mutex);
            return; // Key found and deleted, return
        }
    }
    pthread_mutex_unlock(&kv_mutex);
}


/* increase the value of a key
 *
 * - if the key exists, increase "val" on top of the old value.
 * - if key doesn't exit,
 *     -- insert one if the number of keys is smaller than TABLE_MAX
 *     -- return failure if the number of keys equals TABLE_MAX
 * - return 0 for success; return 1 for failures.
 *
 * NOTE: kv-store must be implemented as a monitor.
 */
int kv_increase(kvstore_t *kv, char *key, int val) {
    /* TODO: your code here */


    pthread_mutex_lock(&kv_mutex);
    // Critical section
    for (int i = 0; i < TABLE_MAX; ++i) {
        if (kv->keys[i].stat == 1 && strcmp(kv->keys[i].key, key) == 0) {
            kv->values[i] += val; // Increase value
            pthread_mutex_unlock(&kv_mutex);
            return 0; // Key found, value increased, return success
        }
    }
    for (int i = 0; i < TABLE_MAX; ++i) {
        if (kv->keys[i].stat == 0) {
            strcpy(kv->keys[i].key, key); // Insert new key
            kv->values[i] = val; // Insert value
            kv->keys[i].stat = 1; // Mark as used
            pthread_mutex_unlock(&kv_mutex);
            return 0; // Inserted new key-value pair, return success
        }
    }
    pthread_mutex_unlock(&kv_mutex);
    return 1; // Table full, return failure
}

// print kv-store's contents to stdout
// note: use any format that you like; this is mostly for debugging purpose
void kv_dump(kvstore_t *kv) {
    /* TODO: your code here */
    printf("=== kv-store ===\n");
    pthread_mutex_lock(&kv_mutex);
    // Critical section
    for (int i = 0; i < TABLE_MAX; ++i) {
        if (kv->keys[i].stat == 1) {
            printf("[%d] %s: %d\n", i, kv->keys[i].key, kv->values[i]);
        }
    }
    pthread_mutex_unlock(&kv_mutex);
}
