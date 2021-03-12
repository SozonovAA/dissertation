//входные параметры
double wt=0;//фаза вектора в градусах
double ud=0; //амплитуда питающего напряжения
double us_a=0; //амплитуда  выходного вектора фазного напряжения

//выходные параметры
double betta=0; //угол внутри сектора
double Ta=0; //сигнал на фазу А
double Tb=0; //сигнал на фазу B
double Tc=0; //сигнал на фазу C
double Us=0; //амплитуда линейного напряжения на выходе

double pi=3.14159;

void svpwm(double wt, double ud, double us_a){
	//БУФФЕРНЫЕ ПЕРЕМЕННЫЕ
	static int v=0; //номер сектора
	double T_0, T_1, T_2;
	double t_1, t_2, t_3;
	//раскоменти следующую строку если фаза в радианах
	//wt=wt*57.295779;

	if(us_a*sqrt(3)>ud) us_a=ud/sqrt(3);
	
	Us = sqrt(3)*us_a/ud;


	if (wt >= 0 && wt < 60) v=1;//сектор 1
	if (wt > 60 && wt < 120) v=2;//сектор 2
	if (wt > 120 && wt < 180) v=3;//сектор 3
	if (wt > 180 && wt < 240) v=4;//сектор 4
	if (wt > 240 && wt < 300) v=5; //сектор 5
	if (wt > 300 && wt <= 360) v=6;//сектор 6
		  
	betta=60-(v*60-wt);

	T_1=Us*sin((60-betta)*2*pi/360);
	T_2=Us*sin((betta)*2*pi/360);
	T_0=1-T_1-T_2;

	t_1=T_1+T_2+(T_0/2);
	t_2=T_2+(T_0/2);
	t_3=T_1+(T_0/2);

	switch(v){
		case 1:
			Ta=t_1;
			Tb=t_2;
			Tc=T_0/2;
			break;
		case 2:
			Ta=t_3;
			Tb=t_1;
			Tc=T_0/2;
			break;
		case 3:
			Ta=T_0/2;
			Tb=t_1;
			Tc=t_2;
			break;
		case 4:
			Ta=T_0/2;
			Tb=t_3;
			Tc=t_1;
			break;
		case 5:
			Ta=t_2;
			Tb=T_0/2;
			Tc=t_1;
			break;
		case 6:
			Ta=t_1;
			Tb=T_0/2;
			Tc=t_3;
			break;
		default:
			Ta=777;
			Tb=777;
			Tc=777;
			break;
	}
	
}
