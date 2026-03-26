#include <iostream>
using namespace std;
int recursion(int num){
    cout << num << endl;
    num = num + 1;
    return recursion(num);
}

int main(){
    recursion(1);
    return 0;
}