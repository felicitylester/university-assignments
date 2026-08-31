// 06/13/2023

#include <iostream>

using namespace std;

class Test {
private:
    int a;
public:
    Test(int A) {
        a=A;
        cout << "I'm making a Test." << endl;
    }
    ~Test() {
        cout << "I'm destructing a Test." << endl;
    }
};

void testFunc(){
    Test a(3);
}

// varaible can be out of scope and still in memory

int main (int arg, char** argv) {
    testFunc();
    cout << "back in main" << endl;
    
//    Test *a = new Test(3);
//    delete a;
//    a = new Test(3);
    
    return 0;
};
                                  
