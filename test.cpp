#include <iostream>
using namespace std;

class Base {
public:
    void showPublic() { cout << "Base Public Method\n"; }
protected:
    void showProtected() { cout << "Base Protected Method\n"; }
private:
    void showPrivate() { cout << "Base Private Method\n"; }
};

class DerivedProtected : protected Base {
public:
    void showDerived() {
        showPublic();    // Accessible
        showProtected(); // Accessible
        // showPrivate(); // Not accessible
    }
};

class hhh : public DerivedProtected 
{
    public :
        void showDeriveddd() {
        showPublic();    // Accessible
        showProtected(); // Accessible
        // showPrivate(); // Not accessible
    }

}


int main() {
    DerivedProtected obj;
    obj.showDerived();
    // obj.showPublic();    // Not accessible
    // obj.showProtected(); // Not accessible
    return 0;
}

