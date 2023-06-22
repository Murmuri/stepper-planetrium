const int PIN_1 = 2;
const int PIN_2 = 3;
const int PIN_3 = 4;
const int PIN_4 = 5;
const int SPEED_PIN = 0;
boolean side = false;
boolean power = false;
int speed = 1;

void unStepMotor(int pin_1,int pin_2,int pin_3,int pin_4,int speedMotor)
{
    digitalWrite(pin_1,HIGH);
    digitalWrite(pin_2,LOW);
    digitalWrite(pin_3,LOW);
    digitalWrite(pin_4,LOW);
    delay(speedMotor);
    //
    digitalWrite(pin_1,HIGH);
    digitalWrite(pin_2,HIGH);
    digitalWrite(pin_3,LOW);
    digitalWrite(pin_4,LOW);
    delay(speedMotor);
    //
    digitalWrite(pin_1,LOW);
    digitalWrite(pin_2,HIGH);
    digitalWrite(pin_3,LOW);
    digitalWrite(pin_4,LOW);
    delay(speedMotor);
    //
    digitalWrite(pin_1,LOW);
    digitalWrite(pin_2,HIGH);
    digitalWrite(pin_3,HIGH);
    digitalWrite(pin_4,LOW);
    delay(speedMotor);
    //
    digitalWrite(pin_1,LOW);
    digitalWrite(pin_2,LOW);
    digitalWrite(pin_3,HIGH);
    digitalWrite(pin_4,LOW);
    delay(speedMotor);
    //
    digitalWrite(pin_1,LOW);
    digitalWrite(pin_2,LOW);
    digitalWrite(pin_3,HIGH);
    digitalWrite(pin_4,HIGH);
    delay(speedMotor);
    //
    digitalWrite(pin_1,LOW);
    digitalWrite(pin_2,LOW);
    digitalWrite(pin_3,LOW);
    digitalWrite(pin_4,HIGH);
    delay(speedMotor);
    //
    digitalWrite(pin_1,HIGH);
    digitalWrite(pin_2,LOW);
    digitalWrite(pin_3,LOW);
    digitalWrite(pin_4,HIGH);
    delay(speedMotor);
}

int getSpeed() 
{
    int value = analogRead(SPEED_PIN);
    value = map(value,0,1023,-35,35);
    Serial.println(value);
    return value;
}

void setup(){
    Serial.begin(9600);
    //
    pinMode(PIN_1,OUTPUT);
    pinMode(PIN_2,OUTPUT);
    pinMode(PIN_3,OUTPUT);
    pinMode(PIN_4,OUTPUT);
}

void loop(){
    speed = getSpeed();
    if (speed < -5) 
    {
        power = true;
        side = true;
        speed = speed + 7;
        speed = speed * -1;
        speed = 30 - speed;
        Serial.println(speed);
    }
    else if (speed > 5)
    {
        power = true;
        side = false;
        speed = speed - 7;
        speed = 30 - speed;
        Serial.println(speed);
    }
    else 
    {
        power = false;
    }
    Serial.println(speed);
    //
    if (!power) 
    {
        digitalWrite(PIN_1,LOW);
        digitalWrite(PIN_2,LOW);
        digitalWrite(PIN_3,LOW);
        digitalWrite(PIN_4,LOW);
    }
    else if (side) 
    {
        unStepMotor(PIN_1,PIN_2,PIN_3,PIN_4,speed);
    }
    else 
    {
        unStepMotor(PIN_4,PIN_3,PIN_2,PIN_1,speed);
    }
}