#include <string>
using namespace std;

class Agenda{

    private:   
        string names[3];
        string nameValidation(string);

    public:
        void setNames();
        void getNames();           
};