#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][2] = {1,2,69,4,5,6};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int ele = *(a+0)[1];
    int ele2 = *(a+1)[1];

    printf("%d\n%d\n",ele,ele2);
}