#include <stdio.h>
#include <list>

using namespace std;

int tc_1(void) {
    int i;
    list<int> sl;

    for(i=0;i<10000000;i++) {
        sl.push_back(1);
    }
}

int main(int argc, char *argv[]) {
    tc_1();
}
