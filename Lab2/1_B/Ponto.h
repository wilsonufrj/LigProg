class Ponto{
    public:
        Ponto(double = 1.0,double = 1.0 ,double= 1.0);

        void setX(double);
        void setY(double);
        void setZ(double);

        double getX();
        double getY();
        double getZ();

    private:
        double X,Y,Z;
};