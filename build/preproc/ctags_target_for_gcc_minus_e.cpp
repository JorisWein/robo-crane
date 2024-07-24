# 1 "C:\\Users\\J&V\\Jorio\\Arduino\\robo-arm\\robo-arm.ino"
# 2 "C:\\Users\\J&V\\Jorio\\Arduino\\robo-arm\\robo-arm.ino" 2

Servo servo1;
Servo servo2;
int pos1 = 90;
int pos2 = 90;
int button1 = 5; // pin of the first button, red
int button2 = 4; // pin of the second button, red
int button3 = 3; // pin of the third button, yellow
int button4 = 2; // pin of the fourth button, yellow

void setup()
{
    servo1.attach(8); // pin  used by the servo
    servo2.attach(7); // pin  used by the servo
    pinMode(button1, 0x2); // define buttons as input pullup
    pinMode(button2, 0x2);
    pinMode(button3, 0x2);
    pinMode(button4, 0x2);

    // INPUT_PULLUP send to arduino LOW signal, so, when you press  the button, you send a LOW signal to arduino
    // Move servos to initial positions
    servo1.write(pos1);
    servo2.write(pos2);
}

void loop()
{
    if (digitalRead(button1) == 0x0)
    {
        if (pos1 < 180) // Ensure servo1 doesn't move past 180 degrees
        {
            pos1++;
            servo1.write(pos1);
            delay(15); // 15 milliseconds of delay
        }
    }

    if (digitalRead(button2) == 0x0)
    {
        if (pos1 > 0) // Ensure servo1 doesn't move below 0 degrees
        {
            pos1--;
            servo1.write(pos1);
            delay(15);
        }
    }
    if (digitalRead(button3) == 0x0)
    {
        if (pos2 > 70) // Ensure servo2 doesn't move past 180 degrees
        {
            pos2--;
            servo2.write(pos2);
            delay(15);
        }
    }

    if (digitalRead(button4) == 0x0)
    {
        if (pos2 < 160) // Ensure servo2 doesn't move below 0 degrees
        {
            pos2++;
            servo2.write(pos2);
            delay(15);
        }
    }
}
