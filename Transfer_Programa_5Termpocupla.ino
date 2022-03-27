#include <max6675.h>

//DEFINIR VARIABLES GLOBABLES

unsigned long start;

double temperatura1 = 0; // Variable para almacenar temperatura de termocupla 1
double temperatura2 = 0; // Variable para almacenar temperatura de termocupla 2
double temperatura3 = 0; // Variable para almacenar temperatura de termocupla 2
double temperatura4 = 0; // Variable para almacenar temperatura de termocupla 2
double temperatura5 = 0; // Variable para almacenar temperatura de termocupla 2

//DEFINIR FUNCIONES GLOBALES

void MostrarTemperatura();

// Definir los pines para el modulo MAX 6675
  //TERMOCUPLA 1 
    int ktcSO1 = 11;
    int ktcCS1 = 12;
    int ktcCLK1 = 13;

  //TERMOCUPLA 2 
    int ktcSO2 = 8;
    int ktcCS2 = 9;
    int ktcCLK2 = 10;

  //TERMOCUPLA 3
    int ktcSO3 = 5;
    int ktcCS3 = 6;
    int ktcCLK3 = 7;

   //TERMOCUPLA 4 
    int ktcSO4 = 2;
    int ktcCS4 = 3;
    int ktcCLK4 = 4;

   //TERMOCUPLA 5 
    int ktcSO5 = A0;
    int ktcCS5 = A1;
    int ktcCLK5 = A2; 

MAX6675 ktc1(ktcCLK1, ktcCS1, ktcSO1);
MAX6675 ktc2(ktcCLK2, ktcCS2, ktcSO2);
MAX6675 ktc3(ktcCLK3, ktcCS3, ktcSO3);
MAX6675 ktc4(ktcCLK4, ktcCS4, ktcSO4);
MAX6675 ktc5(ktcCLK5, ktcCS5, ktcSO5);

void setup() {
  // put your setup code here, to run once:
    //activa comunicacion serial.
       Serial.begin(9600);
       
}

void loop() {
  // put your main code here, to run repeatedly:
  // Para que se repita cada 1 segundos 
       if (millis() - start >= 1000UL){
           start = millis();
           MostrarTemperatura(); //Llamamos a la funcion que mostrará la temperatura en la pantalla
       }        
}

void MostrarTemperatura()
{         
           temperatura1=ktc1.readCelsius();
           Serial.print(millis());    // Se imprime el tiempo en la simulacion
           Serial.print('\t');        // Se da un TAB para separar valores
           Serial.print(temperatura1);

           temperatura2=ktc2.readCelsius();    
           Serial.print('\t');        // Se da un TAB para separar valroes
           Serial.print(temperatura2);

           temperatura3=ktc3.readCelsius();
           Serial.print('\t');
           Serial.print(temperatura3);

           temperatura4=ktc4.readCelsius();    
           Serial.print('\t');
           Serial.print(temperatura4);

           temperatura5=ktc5.readCelsius();    
           Serial.print('\t');
           Serial.println(temperatura5); // Se pone println porque aqui y solo aqui cambia de linea
           
  }
