#include <iostream>

using namespace std;

class Data {
    private:
        string data;
        void validar(string);
    public:
        string getData();
        void setData(string);
};

inline string Data::getData() {
    return data;
}