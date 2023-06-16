#include <syscall.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int main(int argc, char **argv);
int entry_call(int argc, char **argv);

int entry(int argc, char **argv) {
    // we need to call a other entry function
    return entry_call(argc, argv);
}

int entry_call(int argc, char **argv) {
    // patch argv

    int new_argc = argc - 1;
    if (new_argc < 1) new_argc = 1;
    char **new_argv = malloc(sizeof(char *) * (new_argc + 1));
    // printf("new_argc = %d\n", new_argc);

    for (int i = 0; i <= new_argc; i++) {
        if (i == 0) {
            new_argv[i] = "vlink";
        } else if (i == new_argc) {
            // printf("argv[%d] = NULL\n", i);
            new_argv[i] = NULL;
            break;
        } else {
            new_argv[i] = argv[i + 1];
        }
        // printf("argv[%d] = %s\n", i, new_argv[i]);
    }

    // call main and setup exit
    int val;

    main(new_argc, new_argv);

    free(new_argv);

    // free memory
    int freed = c_mem_free_all(c_process_get_pid());
    printf("%d alloc freed\n", freed);

    return 0;
}
