#include <stdio.h> // Will remove this later.
#include "base.h"
#include "mem.h"
#include "mem_malloc.h"
#include "utils.h"

#define eval_print(x)    printf("%s = %d\n", #x, (s32)(x))
#define eval_print_ll(x)  printf("%s = %ld\n", #x, (s64)(x))
#define eval_print_u(x)   printf("%s = %u\n", #x, (u32)(x))
#define eval_print_ull(x) printf("%s = %lu\n", #x, (u64)(x))

int main()
{
  printf("[Context]\n");
  printf("COMPILER_CL    %d\n", COMPILER_CL   );
  printf("COMPILER_CLANG %d\n", COMPILER_CLANG);
  printf("COMPILER_GCC   %d\n", COMPILER_GCC  );
  printf("OS_WINDOWS     %d\n", OS_WINDOWS    );
  printf("OS_LINUX       %d\n", OS_LINUX      );
  printf("OS_MAC         %d\n", OS_MAC        );
  printf("ARCH_X64       %d\n", ARCH_X64      );
  printf("ARCH_X86       %d\n", ARCH_X86      );
  printf("ARCH_ARM       %d\n", ARCH_ARM      );
  printf("ARCH_ARM64     %d\n", ARCH_ARM64    );
  printf("CPP            %d\n", LANG_CPP      );
  assert(1 > 100);


  printf("\n[Limit Constants]\n");
  // Minimum Limits (Signed)
  eval_print(min_s8);
  eval_print(min_s16);
  eval_print(min_s32);
  eval_print_ll(min_s64);

  // Maximum Limits (Signed)
  eval_print(max_s8);
  eval_print(max_s16);
  eval_print(max_s32);
  eval_print_ll(max_s64);

  // Maxmimum Limits (Unsigned)
  eval_print_u(max_u8);
  eval_print_u(max_u16);
  eval_print_u(max_u32);
  eval_print_ull(max_u64);


  // Generic printing
  gprint("\n[Generic Printing]");
  gprint(42);
  gprint("Hello world");
  gprint((float)23123.3);
  gprint((double)123123.61321232);

  // Creating a memory arena
  MemoryArena arena = make_arena();
  free_arena(&arena);

  // Base mem interface style malloc
  M_BaseMemory *base_memory = m_malloc_base_memory();
  u32* a = (u32*)base_memory->reserve(base_memory->ctx, sizeof(u32));
  *a = 5;
  gprint(*a);
  base_memory->release(base_memory->ctx, cast_voidp(a), 0);
  return 0; 
}
