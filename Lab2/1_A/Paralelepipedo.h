class Paralelepipedo{

    public:
        Paralelepipedo(double,double,double);
        void setX(double x);
        void setY(double y);
        void setZ(double z);
        double getVolume();

    private:
        double computeVolume(double,double,double);
        double x;
        double y;
        double z;
};