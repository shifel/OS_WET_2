#include "hw2_test.h"
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <sys/wait.h>
#include "queue"

using namespace std;

#define EE 0
#define CS 1

enum Tests {f_EE=0, f_CS=1, Fork, SetFacultie, GetFacultie, Register, getCsSum, EndFork};


class Process{
public:
    Process(){
        cout << "############# New Process #############" << endl;
        cout << "############# PID == " << pid() << " #############" << endl;
        cout << "############# facultie == " << Facultie() << " #############" << endl;
    }
    ~Process(){
    
    }
    pid_t pid(){
        return getpid();
    }
    long Facultie(){
        return get_status();
    }
    long SetFacultie(int facultie){
        if (facultie != EE && facultie != CS){
            cout << "SetFacultie:: INVALID facultie" << endl;
        }
        cout << "Process(" << pid() << ")::SetFacultie:: facultie == " << facultie << endl;
        return set_status();
    }
    void Register(){
        cout << "Process(" << pid() << "):: Registered" << endl;
        register_process();
    }
    long getCsSum(){
        return get_all_cs();
    }
    
    void Fork(queue<Tests> testQ, string name){
        pid_t pid = fork();
        if(pid == 0){
            Process();
            Test(testQ, name)
            std::cin >> x;
        }
        else{
            int a;
            //wait(&a);
        }
    }
    
    bool Test(queue<Tests> testQ, string name){
        cout << "#######################################" << endl;
        cout << "############# " << name << " Started #############" << endl;
        
        Tests current_task;
        while (!testQ.empty()){
            current_task = testQ.pop();
            cout << "current_task: ";
    
            switch(current_task)
            {
                case Tests::Fork:
                    std::cout << "Fork\n";
                    //Fork();
                    break;
                case Tests::GetFacultie:
                    std::cout << "GetFacultie\n";
                    cout << Facultie() << endl;
                    break;
                case Tests::Register:
                    std::cout << "Register\n";
                    cout << Register << endl;
                    break;
                case Tests::SetFacultie:
                    std::cout << "SetFacultie\n";
                    cout << SetFacultie(testQ.pop()) << endl;
                    break;
                case Tests::getCsSum:
                    std::cout << "getCsSum\n";
                    cout << getCsSum() << endl;
                    break;
            }
        }
        cout << "############# " << name << " Ended #############" << endl;
        cout << "#######################################" << endl;
    }
    
};

int main() {
    queue<Tests> testQ;
    testQ.push(Tests::getCsSum);
    testQ.push(Tests::SetFacultie);
    testQ.push(Tests::f_CS);
    testQ.push(Tests::getCsSum);
    testQ.push(Tests::Register);
    testQ.push(Tests::getCsSum);
    Process Parent;
    Parent.Test(testQ, "sum Test");
    
    
    return 0;
}
