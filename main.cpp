#include <iostream>
#include "scheduler.h"
using namespace std;

int main() {
    // SJF test
    SJF sjf;
    sjf.numPro = 3;
    sjf.pro_arr[0] = Process("P1", 2, 6);
    sjf.pro_arr[1] = Process("P2", 4, 1);
    sjf.pro_arr[2] = Process("P3", 10, 2);
    sjf.scheduling();
    cout << "*** SJF TEST ***" << endl;
    for(int i = 0; i < sjf.totalExecTime; ++i) {
        cout << i << " : " << sjf.schedule_arr[i].name << endl;
    }

    // FIFO test
    FIFO fifo;
    fifo.numPro = 3;
    fifo.pro_arr[0] = Process("P1", 2, 1);
    fifo.pro_arr[1] = Process("P2", 9, 4);
    fifo.pro_arr[2] = Process("P3", 1, 2);
    fifo.scheduling();
    cout << "*** FIFO TEST ***" << endl;
    for(int i = 0; i < fifo.totalExecTime; ++i) {
        cout << i << " : " << fifo.schedule_arr[i].name << endl;
    }

    // PSJF test
    PSJF psjf;
    psjf.numPro = 3;
    psjf.pro_arr[0] = Process("P1", 2, 6);
    psjf.pro_arr[1] = Process("P2", 4, 1);
    psjf.pro_arr[2] = Process("P3", 6, 2);
    psjf.scheduling();
    cout << "*** PSJF TEST ***" << endl;
    for(int i = 0; i < psjf.totalExecTime; ++i) {
        cout << i << " : " << psjf.schedule_arr[i].name << endl;
    }

    return 0;
}
