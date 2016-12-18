//
//  main.c
//  4 million seconds (BNR Ch.11 Challenge)
//
//  Created by Jake Wojtas on 8/22/16.
//  Copyright (c) 2016 Big Nerd Ranch. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    long todaysDate = time(NULL);
    
    struct tm now;
    localtime_r(&todaysDate, &now);
    
    
    float month = now.tm_mon + 1;
    float day = now.tm_mday;
    float year = now.tm_year + 1900;
    float hours = now.tm_hour;
    float minutes = now.tm_min;
    float seconds = now.tm_sec;
    
    if (hours > 12)
    {
        hours = hours - 12;
    }
    else
        hours = hours;
    
   
    printf("The date today is %.0f-%.0f-%.0f\n", month, day, year);
    printf("The time today is %.0f:%.0f and %.0f seconds\n", hours, minutes, seconds);
    
    month++;
    
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10))
    {
        if (day > 16)
        {
            day = day + 15;
            month++;
            day = day - 31;
        }
        else
        {
            day = day + 15;
            
        }
    }
    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        if (day > 15)
        {
            day = day + 15;
            month++;
            day = day - 30;
        }
        else
        {
            day = day + 15;
        }
    }
    else if (month == 2) //leap year does not work
    {
        if (day > 14)
        {
            day = day + 15;
            month++;
            day = day - 29;
        }
        else
        {
            day = day + 15;
        }
    }
    else if (month == 12)
    {
        if (day > 16)
        {
            day = day + 15;
            year++;
            month++;
            day = day - 31;
        }
        else
        {
            day = day + 15;
        }
    }
    
    if (((int)year % 4 == 0) && (month == 2))
        {
            if (day > 13)
            {
                day = day + 15;
                month++;
                day = day - 28;
            }
            else
            {
                day = day + 15;
            }
        }
     
    
    if (hours < 4)
    {
        hours = hours + 21;
        hours = hours - 12;
    }
    else
    {
        hours = hours + 21;
        hours = hours - 24;
    }
    
    if (minutes > 53)
    {
        minutes = minutes + 6;
        hours++;
        minutes = minutes - 60;
    }
    else
    {
        minutes = minutes + 6;
    }
    
    if (seconds > 22)
    {
        seconds = seconds + 37;
        minutes++;
        seconds = seconds - 60;
    }
    else
    {
        seconds = seconds + 37;
    }
    
    
    printf("The date in 4 million seconds will be %.0f-%.0f-%.0f and the time will be %.0f:%.0f and %.0f seconds\n", month, day, year, hours, minutes, seconds);
    
    return 0;
}

