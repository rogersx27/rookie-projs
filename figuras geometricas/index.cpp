#include <iostream>
#include <cmath>

using namespace std;

double area;
double perimetro;

void calcularAreaPerimetroCirculo(double radio);
void calcularAreaPerimetroCuadrado(double lado);
void calcularAreaPerimetroTriangulo(double base, double altura);
void calcularAreaPerimetroRectangulo(double base, double altura);

int main()
{
    int menu;
    double radio, lado, base, altura;

    do
    {
        cout << "Seleccione la figura geometrica para calcular el area y el perimetro:" << endl;
        cout << "1. Circulo" << endl;
        cout << "2. Cuadrado" << endl;
        cout << "3. Triangulo" << endl;
        cout << "4. Rectangulo" << endl;
        cout << "5. Salir" << endl;
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            calcularAreaPerimetroCirculo(radio);
            cout << "El area del circulo es: " << area << endl;
            cout << "El perimetro del circulo es: " << perimetro << endl;

            system("pause");
            system("cls");
            break;

        case 2:
            cout << "Ingrese el lado del cuadrado: ";
            cin >> lado;
            calcularAreaPerimetroCuadrado(lado);
            cout << "El area del cuadrado es: " << area << endl;
            cout << "El perimetro del cuadrado es: " << perimetro << endl;

            system("pause");
            system("cls");
            break;

        case 3:
            cout << "Ingrese la base del triangulo: ";
            cin >> base;
            cout << "Ingrese la altura del triangulo: ";
            cin >> altura;
            calcularAreaPerimetroTriangulo(base, altura);
            cout << "El area del triangulo es: " << area << endl;
            cout << "El perimetro del triangulo es: " << perimetro << endl;

            system("pause");
            system("cls");
            break;

        case 4:
            cout << "Ingrese la base del rectangulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectangulo: ";
            cin >> altura;
            calcularAreaPerimetroRectangulo(base, altura);
            cout << "El area del rectangulo es: " << area << endl;
            cout << "El perimetro del rectangulo es: " << perimetro << endl;

            system("pause");
            system("cls");
            break;

        case 5:
            cout << "Gracias por usar el programa. Hasta luego." << endl;

            system("pause");
            system("cls");
            break;

        default:
            cout << "Opción inválida. Intente nuevamente." << endl;

            system("pause");
            system("cls");
            break;
        }

        cout << endl;

    } while (menu != 5);

    return 0;
}

void calcularAreaPerimetroCirculo(double radio)
{
    // A = PI * r^2
    double pi = 3.14159265359;
    area = pi * pow(radio, 2);

    // P = 2 * PI * r
    perimetro = 2 * pi * radio;
}

void calcularAreaPerimetroCuadrado(double lado)
{
    // A = l^2
    area = pow(lado, 2);

    // P = 4 * l
    perimetro = 4 * lado;
}

void calcularAreaPerimetroTriangulo(double base, double altura)
{
    // A = (b * h) / 2
    area = (base * altura) / 2;

    // P = 3 * b (equilatero)
    perimetro = 3 * base;
}

void calcularAreaPerimetroRectangulo(double base, double altura)
{
    // A = b * h
    area = base * altura;

    // P = 2 * (b + h)
    perimetro = 2 * (base + altura);
}
