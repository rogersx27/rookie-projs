#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

const int numero_de_empleados = 2;

float nominaEmpleado[numero_de_empleados];
string basicInfo[numero_de_empleados][5];
float labores[numero_de_empleados][4];

void funcion_ingreso_basicInfo();
void funcion_ingreso_labores(int numero_de_empleados);
void funcion_calculo_nomina();
void funcion_calculo_pagoNomina();
void buscador_nombre();

int main()
{
    cout << "Bienvenido al sistema de nómina de la empresa XYZ" << endl;
    int menu_;

    do
    {
    cout << " " << endl;
    cout << "¿Qué desea hacer?" << endl;
    cout << "1. Saber la cantidad de empleados" << endl;
    cout << "2. Ingresar información básica de los empleados" << endl;
    cout << "3. Ingresar información de las labores de los empleados" << endl;
    cout << "4. Calcular la nómina de los empleados" << endl;
    cout << "5. Pagar nómina del empleado" << endl;
    cout << "6. Salir" << endl;
    cin >> menu_;

        switch (menu_)
        {
            case 1: 
            {
                system("cls");
                cout << " " << endl;
                cout << "La cantidad de empleados es:" << numero_de_empleados << endl;
                break;
            }

            case 2:
            {
                funcion_ingreso_basicInfo();

                cout << " " << endl;
                cout << "Información Ingresada con éxito!" << endl;
                cout << " " << endl;

                system("pause");
                system("cls");
                break;
            }

            case 3: 
            {
                cout << " " << endl;
                funcion_ingreso_labores(numero_de_empleados);
                cout << " " << endl;

                system("pause");
                system("cls");
                break;
            }

            case 4:
            {
                cout << " " << endl;
                funcion_calculo_nomina();
                cout << " " << endl;

                system("pause");
                system("cls");
                break;
            }

            case 5:
                {
                    cout << " " << endl;
                    funcion_calculo_pagoNomina();
                    cout << " " << endl;

                    cout << "Pago en curso..." << endl;

                    system("pause");
                    system("cls");
                    break;
                }

            case 6:
                {
                    cout << " " << endl;
                    cout << "¡Gracias por usar el sistema de nómina! Hasta luego." << endl;
                    return 0; // Salir del programa
                }
        
        default:
            break;
        }
    } while (menu_ != 6);
}

void funcion_ingreso_basicInfo()
{
    // Matriz que almacena la información básica de los empleados (nombre, cédula, teléfono, salario, cargo).
    for (int i = 0; i < numero_de_empleados; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                cout << "Ingrese el nombre del empleado " << i + 1 << ": "; // Valor 0 de la fila i
            } else if (j == 1)
                {
                cout << "Ingrese la cédula del empleado " << basicInfo[i][0] << ": "; // Valor 1 de la fila i
            } else if (j == 2)
            {
                cout << "Ingrese el teléfono del empleado " << basicInfo[i][0] << ": "; // Valor 2 de la fila i
            } else if (j == 3)
            {
                cout << "Ingrese el salario del empleado " << basicInfo[i][0] << ": "; // Valor 3 de la fila i
            } else
            {
                cout << "Ingrese el cargo del empleado " << basicInfo[i][0] << ": "; // Valor 4 de la fila i
            }
            cout << " " << endl;
            cin >> basicInfo[i][j];
        }
        
    }
}

void funcion_ingreso_labores(int numero_de_empleados)
{
    // Matriz que almacena la información de las labores de los empleados (horas extras laboradas, descuentos por
    // préstamos, ahorro voluntario, descuentos por seguridad social).

    for (int i = 0; i < numero_de_empleados; i++) // Avanzar entre filas
    {
        for (int j = 0; j < 4; j++) // Avanzar entre columnas
        {
            // Preguntar por cada uno de los datos de las labores
            if (j == 0)
            {
                cout << "Ingrese las horas extras laboradas del empleado " << basicInfo[i][0] << ": "; // Valor 0 de la fila i
            } else if (j == 1)
                {
                cout << "Ingrese los descuentos por préstamos del empleado " << basicInfo[i][0] << ": "; // Valor 1 de la fila i
            } else if (j == 2)
            {
                cout << "Ingrese el ahorro voluntario del empleado " << basicInfo[i][0] << ": "; // Valor 2 de la fila i
            } else if (j == 3)
            {
                cout << "Ingrese los descuentos por seguridad social del empleado " << basicInfo[i][0] << ": "; // Valor 3 de la fila i
            }
            cout << " " << endl;
            cin >> labores[i][j];
        }
    }
}

void funcion_calculo_nomina()
{
    // Para pagar nomina necesito: nominaEmpleado = (salario) + (horas extras laboradas) - (descuentos por préstamos) - (ahorro voluntario) - (descuentos por seguridad social)
    // El salario es el valor de la columna 3 de la matriz basicInfo
    // Las horas extras laboradas son el valor de la columna 0 de la matriz labores
    // Los descuentos por préstamos son el valor de la columna 1 de la matriz labores
    // El ahorro voluntario es el valor de la columna 2 de la matriz labores
    // Los descuentos por seguridad social son el valor de la columna 3 de la matriz labores

    int idEmpleado;

    buscador_nombre();
    
    cout << "Ingrese el número del empleado al cual desea calcular el pago de nómina: " << endl;
    cout << " " << endl;
    cin >> idEmpleado;

    float salario = (stof(basicInfo[idEmpleado - 1][3]));
    float horasExtra = (labores[idEmpleado - 1][0]) * (salario / 8); // Se asume que el salario es por un día laboral de 8h
    float prestamos = (labores[idEmpleado - 1][1]);
    float ahorroVoluntario = (labores[idEmpleado - 1][2]);
    float descuentoSeguridadSocial = (labores[idEmpleado - 1][3]);

    nominaEmpleado[idEmpleado - 1] = salario + horasExtra - (prestamos - ahorroVoluntario - descuentoSeguridadSocial);

    cout << " " << endl;
    cout << "El salario a pagar del empleado " << basicInfo[idEmpleado - 1][0] << " es " << nominaEmpleado[idEmpleado - 1] << endl;
    cout << " " << endl;
}

void funcion_calculo_pagoNomina()
{
    // Para pagar nomina necesito nominaEmpleado, que es el valor calculado en la función anterior
    // Mostrar Nombre, Cedula, Cargo y Salario a pagar

    int idEmpleadoPago;
    string nombreEmpleado;

    buscador_nombre();

    cout << "Ingrese el nombre del empleado al cual desea pagar la nómina: " << endl;
    cin.ignore();
    cout << " " << endl;
    getline(cin, nombreEmpleado);

    int idEmpleado= -1;
    for (int i = 0; i < numero_de_empleados; i++)
    {
        if (basicInfo[i][0] == nombreEmpleado)
        {
            idEmpleado = i;
            break;
        }
    }

    if (idEmpleado != -1 && nominaEmpleado[idEmpleado ] > 0)
    {
        cout << " " << endl;
        cout << "El empleado " << basicInfo[idEmpleado][0] << " con cédula " << basicInfo[idEmpleado][1] << " y cargo " << basicInfo[idEmpleado][4] << " tiene un salario a pagar de " << nominaEmpleado[idEmpleado] << endl;
        cout << " " << endl;
    }
    else
    {
        cout << " " << endl;
        cout << "El empleado no fue encontrado o no se ha calculado su nómina. Por favor, asegúrese de calcular la nómina primero." << endl;
        cout << " " << endl;
    }
}

void buscador_nombre()
{
    // Buscar el nombre del empleado en la matriz basicInfo
    // Mostrar Nombre
    
    for (int i = 0; i < numero_de_empleados; i++)
        {
            cout << " " << endl;
            cout << "Empleado " << i + 1 << " es : " << basicInfo[i][0] <<endl;
            cout << " " << endl;
        }
}