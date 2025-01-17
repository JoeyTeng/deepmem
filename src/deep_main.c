
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "deep_mem.h"
#include "deep_log.h"
#define WASM_FILE_SIZE 1024
#define DEEPVM_MEMPOOL_SIZE 30*1024
uint8_t deepvm_mempool[DEEPVM_MEMPOOL_SIZE]= {0};
uint8_t example[100]= {"This is a example for logsys."};

static void
log_memory (void *buff, size_t size)
{
  for (int i = 0; i < size; i++)
    {
      char string[9] = "";
      for (int j = 0; j < 4; i++, j++)
        {
          sprintf (string + 2 * j, "%02x", *(uint8_t *)(buff + i));
        }
      if (strncmp (string, "00000000", 8) != 0)
        {
          printf ("%03d: 0x%s\n", i, string);
        }
    }
}

int main(void) {
    // deep_info("This a log for information");
    // deep_debug("This a log for debuging");
    // deep_warn("This a log for warning");
    // deep_error("This a log for error");
    // deep_dump("example", example, 100);
    deep_mem_init(deepvm_mempool, DEEPVM_MEMPOOL_SIZE);
    for(int i = 0; i < 1000; i++) {
        uint8_t *p = deep_malloc(100);
        deep_info("malloc %d times, @%p", i, p);
        if (i >= 290) {
            // log_memory(deepvm_mempool, DEEPVM_MEMPOOL_SIZE);
        }
        if (p == NULL) {
            deep_error("malloc fail @%d", i);
            break;
        }
        *p = 0xFF;
        deep_free(p);
    }
    return 0;
}
