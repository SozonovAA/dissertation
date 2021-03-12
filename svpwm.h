//входные параметры
extern double wt;//фаза вектора в градусах
extern double ud; //амплитуда питающего напряжения
extern double us_a; //амплитуда  выходного вектора

//выходные параметры
extern double betta; //угол внутри сектора
extern double Ta; //сигнал на фазу А
extern double Tb; //сигнал на фазу B
extern double Tc; //сигнал на фазу C
extern double Us; //???

void svpwm(double, double, double);