/*
ClockAngles

Problem:

Write a program to convert digital times (given in the format hh:mm:ss) to the angles between the various hands of an analog clock displaying the corresponding time.

Details:

0) Compute the angles between the hour hand and minute hand, hour hand and second hand, and the minute hand and second hand.
1) Assume that all three hands move once per second. Each time they move, they move an equal distance forward so that at noon and midnight the hour hand is at exactly     0 degrees, at the top of every hour the minute hand is at exactly 0 degrees, and at the beginning of every minute the second hand is at exactly 0 degrees.
2) The hour values in the digital time you are given will be between 1 and 12, inclusive, and will always be integers. The minute and second values will be between 0  and 59, inclusive and will always be integers.
3) The angle values you return as answers always need to be the positive angle between the two hands.
4) All of your answers should be between 0 and 180, inclusive.
5) The first line of the input will be a positive integer, n, corresponding to the number of input times in the file.
6) The next n lines will each contain one digital time value given in the format hh:mm:ss.
7) The first line of your output should contain a positive integer n and the next n lines should contain the three angle answer values for the corresponding input         line.
8) You should print them in the format "hour to minute angle, hour to second angle, minute to second angle".
9) Your answers should be accurate to two decimal places (rounded) and should display both decimal places even if they are not significant. (i.e if the angle is 0 you     should print out 0.00).

 */

#include<stdio.h>
#include<string.h>

void convert(int hh, int mm, int ss)
{
    float ss_ang, hh_ang, mm_ang, ss_sec, mm_sec, hh_sec;
    float hh_ss, hh_mm, mm_ss;
    printf("\n Recieved %d %d %d", hh, mm, ss);
    ss_sec = ss;
    mm_sec = ss + 60*mm;
    hh_sec = mm_sec + 3600*hh;
   printf("\n ss_sec %f mm_sec %f hh_sec %f", ss_sec, mm_sec, hh_sec);
    /* Sec: In 1 sec, sec hand moves = 6 deg
      Min: In 1 min(60 sec), min hand moves = 6 deg
      	   In 1 sec, min moves = 6/60 deg
      Hrs: In 1 hr(3600 sec), hr hand moves = 360/12 = 30 deg
           In 1 sec, hr moves = 30/3600 deg
   */
    ss_ang = 6.0 * ss_sec;
    mm_ang = 6.0/60.0 * mm_sec;
    hh_ang = 30.0/3600.0 * hh_sec;
    printf("\nInitial angles %f %f %f", ss_ang, mm_ang, hh_ang);
    while(ss_ang > 360.0)
    {
	ss_ang = ss_ang - 360.00;
    }
    while(mm_ang > 360.00)
    {
	mm_ang = mm_ang - 360.00;
    }

    while(hh_ang > 360.00)
    {
	hh_ang = hh_ang - 360.00;
    }
    printf("\nWithin 360 %f %f %f", ss_ang, mm_ang, hh_ang);
   
    if((hh_ang - mm_ang) > 180.00)
    {
	hh_mm =(hh_ang - mm_ang) -180.00;
    }
    else
	hh_mm =(hh_ang - mm_ang); 

    printf("\n Angle between hour and minute hand = %f", hh_mm);

    if((hh_ang - ss_ang) > 180.00)
    {
	hh_ss =(hh_ang - ss_ang) -180.00;
    }
    else
	hh_ss = (hh_ang - ss_ang); 

    printf("\n Angle between hour and sec hand = %f", hh_ss);

    if((mm_ang - ss_ang) > 180.00)
    {
	mm_ss = (mm_ang - ss_ang) -180.00;
    }
    else
	mm_ss = (mm_ang - ss_ang); 
    printf("\n Angle between min and sec hand = %f", mm_ss);

}




    
void main()
{
    char time[] = "               ";
    int hh, mm, ss,sec;

    printf("Enter time in hh:mm:ss");
    scanf("%s", time);
    time[2]=' ';
    time[5]=' ';
    
    sscanf(time, "%d %d %d", &hh, &mm, &ss);
    printf("\nhh = %d mm = %d ss= %d", hh, mm, ss);
    convert(hh,mm,ss);

 }
