#include "hw2_test.h"
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <sys/wait.h>

using namespace std;

int main() {
    int x = get_status();
    cout << "status: " << x << endl;
    assert(x == 0);
    x = set_status(1);
    cout << "set_status returns: " << x << endl;
    assert(x == 0);
    x = get_status();
    cout << "new status: " << x << endl;
    assert(x == 1);
    cout << "===== SUCCESS =====" << endl;
    register_process();
    int sum = 0;
    sum = get_all_cs();
    cout << "Sum: " << sum << endl;
    pid_t pid_1 = getpid();
    cout << "pid_1: " << pid_1 << endl;
    pid_t pid = fork();
    if(pid == 0){
        pid_t pid_2 = getpid();
        cout << "pid_2: " << pid_2 << endl;
        register_process();
        std::cin >> x;
    }
    else{
        int a;
        wait(&a);
        
    }
    std::cin >> x;
    return 0;
}
