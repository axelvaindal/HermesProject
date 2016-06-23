#include <ChibiOS_AVR.h>

volatile uint32_t count = 0;

//Définition de la mémoire dynamique pour chaque thread
static WORKING_AREA(waThread1, 1);
static WORKING_AREA(waThread2, 1);
static WORKING_AREA(waThread3, 1);
static WORKING_AREA(waThread4, 1);
static WORKING_AREA(waThread5, 1);
static WORKING_AREA(waThread6, 1);
static WORKING_AREA(waThread7, 1);
static WORKING_AREA(waThread8, 1);
static WORKING_AREA(waThread9, 1);

//Thread de count
static msg_t Thread1(void *arg) 
{
    while (TRUE) 
    {
        //Pause de 1000 milliseconds
        chThdSleepMilliseconds(1000);
        count++;
    }
    return 0;
}

//Thead qui fait clignoter la LED
static msg_t Thread2(void *arg) 
{
    int outpin = 13;
    pinMode(outpin, OUTPUT);

    while(true)
    {
        // Make a dot signal
        digitalWrite(outpin, HIGH);
        chThdSleepMilliseconds( 50 );
        digitalWrite(outpin, LOW);
        chThdSleepMilliseconds( 50 );
    }
}

//Thread ayant une priorité normal pour afficher un message
static msg_t Thread3(void *arg) 
{
    while (TRUE) 
    {
        Serial.begin(9600);
        Serial.println("Thread 3 : J'ai une priorité normal");
        chThdSleepMilliseconds(1000);
    }
    return 0;
}

//Thread ayant une priorité haute pour afficher un message
static msg_t Thread4(void *arg) 
{
    while (TRUE) 
    {
        Serial.begin(9600);
        Serial.println("Thread 4 : J'ai une priorité haute");
        chThdSleepMilliseconds(1000);
    }
    return 0;
}

static msg_t Thread5(void *arg) 
{
    while (TRUE) 
    {
        chThdSleepMilliseconds(1200);
        count++;
    }
    return 0;
}

static msg_t Thread6(void *arg) 
{
    while (TRUE) 
    {
        chThdSleepMilliseconds(3000);
        count++;
    }
    return 0;
}

static msg_t Thread7(void *arg) 
{
    while (TRUE) 
    {
        chThdSleepMilliseconds(1000);
        count++;
    }
    return 0;
}

static msg_t Thread8(void *arg) 
{
    while (TRUE) 
    {
        chThdSleepMilliseconds(1000);
        count++;
    }
    return 0;
}

static msg_t Thread9(void *arg) 
{
    while (TRUE) 
    {
        Serial.println(count);
        chThdSleepMilliseconds(1000);
        count++;
    }
    return 0;
}

//------------------------------------------------------------------------------
void setup() 
{
    //Initialisation de Chibi
    cli();
    halInit();
    chSysInit();

    chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

    // Start le thread de clignotement
    chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2, NULL);
  
    // Start le thread d'affichage de prio normal
    chThdCreateStatic(waThread3, sizeof(waThread3), NORMALPRIO, Thread3, NULL);

    // Start le thread d'affichage prioritaire
    chThdCreateStatic(waThread4, sizeof(waThread4), HIGHPRIO, Thread4, NULL);

    chThdCreateStatic(waThread5, sizeof(waThread5), NORMALPRIO, Thread5, NULL);

    chThdCreateStatic(waThread6, sizeof(waThread6), NORMALPRIO, Thread6, NULL);

    chThdCreateStatic(waThread7, sizeof(waThread7), NORMALPRIO, Thread7, NULL);

    chThdCreateStatic(waThread8, sizeof(waThread8), NORMALPRIO, Thread8, NULL);

    chThdCreateStatic(waThread9, sizeof(waThread9), NORMALPRIO, Thread9, NULL);
}

//------------------------------------------------------------------------------
// idle loop runs at NORMALPRIO
void loop() 
{

}
