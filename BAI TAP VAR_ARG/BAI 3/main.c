#include <stdio.h>
#include <stdarg.h>

typedef enum
{
    LIGHT,
    AIR_CONDITIONER,
    FINGERPRINT_LOCK,
    MUSIC_PLAYER
} DeviceType;

typedef enum
{
    ON,
    OFF,
    SET_TEMPERATURE,
    SET_MODE,
    UNLOCK,
    LOCK,
    INCREASE_VOLUME,
    DECREASE_VOLUME,
    CHANGE_TRACK
} CommandType;

void controlDevice(DeviceType type, ...)
{
    va_list args;
    va_start(args, type);

    switch (type)
    {
    case LIGHT:
    {
        CommandType lightSet = va_arg(args, CommandType);
        if (lightSet == ON)
        {
            printf("Light turned ON\n");
        }
        else if (lightSet == OFF)
        {
            printf("Light turned OFF\n");
        }
        else
        {
            printf("Light ERROR\n");
        }
        break;
    }
    case AIR_CONDITIONER:
    {
        CommandType airSet = va_arg(args, CommandType);
        if (airSet == SET_TEMPERATURE)
        {
            int temperature = va_arg(args, int);
            printf("Air Conditioner temperature set to %d degrees\n", temperature);
        }
        else if (airSet == SET_MODE)
        {
            printf("Air Conditioner mode set\n");
        }
        else
        {
            printf("Air Conditioner ERROR\n");
        }
        break;
    }
    case FINGERPRINT_LOCK:
    {
        CommandType fingerSet = va_arg(args, CommandType);
        if (fingerSet == UNLOCK)
        {
            printf("Fingerprint Lock unlocked\n");
        }
        else if (fingerSet == LOCK)
        {
            printf("Fingerprint Lock locked\n");
        }
        else
        {
            printf("Fingerprint Lock ERROR\n");
        }
        break;
    }
    case MUSIC_PLAYER:
    {
        CommandType musicSet = va_arg(args, CommandType);
        int value = va_arg(args, int);
        if (musicSet == INCREASE_VOLUME)
        {

            printf("Volume increased +%d\n", value);
        }
        else if(musicSet == DECREASE_VOLUME )
        {
            
            printf("Volume decrease -%d\n", value);
        }else if (musicSet == CHANGE_TRACK)
        {
            printf("Change track\n");
        }else printf("ERROR MUSIC_PLAYER\n");
        
        break;
    }

    default:
        printf("Unknown device type\n");
    }

    va_end(args);
}

int main()
{
    controlDevice(LIGHT, ON);
    controlDevice(LIGHT, OFF);
    controlDevice(LIGHT, SET_TEMPERATURE);
    controlDevice(AIR_CONDITIONER, SET_TEMPERATURE, 25);
    controlDevice(AIR_CONDITIONER, SET_MODE);
    controlDevice(FINGERPRINT_LOCK, UNLOCK);
    controlDevice(FINGERPRINT_LOCK, LOCK);
    controlDevice(MUSIC_PLAYER, INCREASE_VOLUME, 10);
    controlDevice(MUSIC_PLAYER, DECREASE_VOLUME, 5);
    controlDevice(MUSIC_PLAYER, CHANGE_TRACK);
    return 0;
}
