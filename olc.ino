 #include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int Htime;              //integer for storing high time
int Ltime;                //integer for storing low time
float Ttime;            // integer for storing total time of a cycle
float frequency;        //storing frequency

void setup()
{
    pinMode(4,INPUT);
    lcd.begin(16, 2);
}
void loop()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Frequency = ");

    Htime=pulseIn(4,HIGH);      //read high time
    Ltime=pulseIn(4,LOW);        //read low time
   
    Ttime = Htime+Ltime;

    frequency=1000000/Ttime;    //getting frequency with Ttime is in Micro seconds
    lcd.setCursor(0,1);
    lcd.print(frequency);
    lcd.print(" Hz");
    delay(500);
}

