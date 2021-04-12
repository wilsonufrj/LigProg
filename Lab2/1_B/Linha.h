#include"Ponto.h"
class Linha{
    public:
        Linha(Ponto,Ponto);
        void setPoint1(double,double,double);
        void setPoint2(double,double,double);
        double getComprimento();

    private:
        Ponto point1;
        Ponto point2;

};