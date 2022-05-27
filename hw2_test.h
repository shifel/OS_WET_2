#ifndef test_hw2_H_
#define test_hw2_H_

#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

// System call wrappers
long set_status(int status);
long get_status();
long register_process();
long get_all_cs();

#endif // test_hw2_H_