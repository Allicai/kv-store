#include "kvstore.h"


// Exercise 4: finish implementing kvstore
// TODO: define your synchronization variables here
// (hint: don't forget to initialize them)



/* read a key from the key-value store.
 *
 * if key exists, set "val" to be the value and return 0.
 * if key doesn't exist, return 1.
 *
 * NOTE: kv-store must be implemented as a monitor.
 */
int kv_read(kvstore_t *kv, char *key, int *val) {
    /* TODO: your code here */


    // delete this later cuz printing is slow
    printf("[INFO] read key[%s]\n", key);
    return 0;
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

    // delete this later cuz printing is slow
    printf("[INFO] write key[%s]=val[%d]\n", key, val);
    return 0;
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


    // delete this later cuz printing is slow
    printf("[INFO] delete key[%s]\n", key);
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


    // delete this later cuz printing is slow
    printf("[INFO] increase key[%s]+=val[%d]\n", key, val);
    return 0;
}

// print kv-store's contents to stdout
// note: use any format that you like; this is mostly for debugging purpose
void kv_dump(kvstore_t *kv) {
    /* TODO: your code here */


    printf("TODO: dump key-value store\n");
}
