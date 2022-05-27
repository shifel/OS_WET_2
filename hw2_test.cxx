#include "hw2_test.h"

long set_status(int status) {
    long r = syscall(334, status);
    return r;
}

long get_status() {
    long r = syscall(335);
    return r;
}

long register_process() {
	long r = syscall(336);
    return r;
}

long get_all_cs() {
	long r = syscall(337);
    return r;
}