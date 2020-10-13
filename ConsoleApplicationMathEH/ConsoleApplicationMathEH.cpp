// ConsoleApplicationMathEH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Integrer f(x) = cos(x)-x
#include <iomanip>
#include <iostream>


void BeregnIntegrert(float fra, float til, float arr[2][10]);
void BeregnRiemann(float fra, float til, float arr[2][10]);
int main()
{
	float arrIntegrert[2][10]{};
	float arrRiemann[2][10]{};
	//beregn ved å bruke formelen for den integrerte: F(x)=sin(x)-(x^2)/2
	BeregnIntegrert(0, 0.6, arrIntegrert);
	
	BeregnRiemann(0.0f, 0.6f, arrRiemann);

	std::cout << "X1\t\tY1\t\tY2\t\tX2" << std::endl;
	for (int ix = 0; ix < 10; ix++)
	{
		std::cout << std::setprecision(2) << arrIntegrert[0][ix] << "\t-\t" << arrIntegrert[1][ix];
		std::cout << "\t-\t" << arrRiemann[1][ix] << "\t-\t" << arrRiemann[0][ix] << std::endl;
	}
}

void BeregnIntegrert(float fra, float til, float arr[2][10]) 
{
	float deltaX = (til - fra) / 10;
	float x = fra + deltaX;

	for (int ix = 0; ix < 10; ix++)
	{
		float fx = sin(x) - pow(x, 2) * 0.5f;
		arr[0][ix] = x;
		arr[1][ix] = fx;
		x += deltaX;
	}
}

void BeregnRiemann(float fra, float til, float arr[2][10]) 
{
	float deltaX = (til - fra) / 10;
	float x = fra + deltaX;
	float RSum = 0;

	for (int ix = 0; ix < 10; ix++)
	{
		float fx = cos(x) - x;
		RSum = RSum + fx * deltaX;
		arr[0][ix] = x;
		arr[1][ix] = RSum;
		x += deltaX;
	}
}
/* Jan Erik sin versjon av matte applikasjonen. 
* 
* 
//TODO: Sett riktig verdi på konstanten
const int NO_OF_STEPS_TO_STORE = 3;

bool numericFxA(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]);
bool IntegratedFxA(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]);
bool IntegratedCosxMx(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]);
bool RiemannCosxMx(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]);
bool Display2(float arr[2][NO_OF_STEPS_TO_STORE]);




int main()
{
	//TODO: Sett fra og til verdi for simuleringa her
	const float FromX = 0;
	const float ToX = 0.6;

	float fxArray[2][NO_OF_STEPS_TO_STORE]{};
	float fxArray2[2][NO_OF_STEPS_TO_STORE]{};

	/*bool aOK = IntegratedFxA(0, 2.5, fxArray);
	bool bOK = numericFxA(0, 2.5, fxArray);*//*

bool aOK = IntegratedCosxMx(FromX, ToX, fxArray);
bool bOK = RiemannCosxMx(FromX, ToX, fxArray2);



//Overskrift
std::cout << "X1\t" << "Y1\t" << "Y2\t" << "X2\t" << std::endl;

for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {
	std::cout << std::setprecision(2) << fxArray[0][ix] << "  ";
	std::cout << "\t" << fxArray[1][ix] << "  ";
	std::cout << "\t" << fxArray2[1][ix] << "  ";
	std::cout << "\t" << fxArray2[0][ix] << std::endl;

}

std::cout << "Hello World!\n";

}


// g(x) = cosx - x og G(x)=sinx- (x^2)/2
bool IntegratedCosxMx(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE])
{
	float t = tStart;
	float dt = (tEnd - tStart) / NO_OF_STEPS_TO_STORE;
	int ix = 0;
	t += dt;;// / 2;
	while (t <= tEnd && ix < NO_OF_STEPS_TO_STORE) {
		fArr[0][ix] = t;
		float fx = sin(t) - pow(t, 2) / 2; //G(x)= sinx - (x^2)/2
		fArr[1][ix] = fx;
		++ix;
		t += dt;
	}
	return true;
}
bool RiemannCosxMx(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]) {
	float delta = (tEnd - tStart) / NO_OF_STEPS_TO_STORE;
	float x = tStart + delta;// / 2;
	//float x = tStart + delta;
	float fx;
	float R = 0;

	for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {
		fx = cos(x) - (x); //g(x) = cosx - x

		fArr[0][ix] = x;
		R += fx * delta;
		fArr[1][ix] = R;

		x = x + delta;
	}
	return true;
}

bool numericFxA(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]) {
	float delta = (tEnd - tStart) / NO_OF_STEPS_TO_STORE;
	float x = tStart + delta / 2;
	float fx;
	float R = 0;

	for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {
		fx = pow(x, 3) - 3 * pow(x, 2) + 2 * x + 1;
		R += fx * delta;

		fArr[0][ix] = x;
		fArr[1][ix] = R;

		x = x + delta;
	}
	return true;
}

bool IntegratedFxA(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE])
{
	float t = tStart;
	float dt = (tEnd - tStart) / NO_OF_STEPS_TO_STORE;
	int ix = 0;
	t += dt / 2;
	while (t < tEnd && ix < NO_OF_STEPS_TO_STORE) {
		fArr[0][ix] = t;
		float fx = pow(t, 4) / 4 - pow(t, 3) + pow(t, 2) + t;
		fArr[1][ix] = fx;
		++ix;
		t += dt;
	}
	return true;
}

bool Display2(float arr[2][NO_OF_STEPS_TO_STORE])
{
	for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {
		std::cout << arr[0][ix] << std::endl;
	}
	return true;
}
*/