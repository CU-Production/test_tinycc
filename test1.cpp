#include <iostream>
extern "C" {
#include "libtcc.h"
}

extern "C" {
    void callme(int x) {
        printf("hello, %d\n", x);
    }

    void error_func(void * user, const char * msg) {
        printf("TCC Error: %s\n", msg);
        exit(1);
    }
}

int main(int argc, char ** argv) {
    std::cout << "Hello, libtcc!" << std::endl;

    int err;
    TCCState * s = tcc_new();
    // tcc_set_lib_path(s, "./libtcc");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    tcc_compile_string(s, "void callme(int); int main() { callme(42); }");
    tcc_set_error_func(s, 0, error_func);
    tcc_add_symbol(s, "callme", callme);
    tcc_run(s, argc, argv);
    tcc_delete(s);

    return 0;
}