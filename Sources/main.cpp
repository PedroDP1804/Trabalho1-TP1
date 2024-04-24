#include "..\Headers\Dominios.h"

int main() {
    Data data;
    string a;
    cin >> a;
    data.setData(a);
    cout << data.getData() << endl;
    system("pause");
}