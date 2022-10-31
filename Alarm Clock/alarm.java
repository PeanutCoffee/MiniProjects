  1
  5: public class AlarmClock extends Clock
  6: {
  7:         public int alarmHour;
  8:         public int alarmMinute;
  9:         public int alarmSecond;
 10: 
 11:         //Constructors
 12:         public AlarmClock()
 13:         {
 14:                 super();
 15:                 alarmHour = 0;
 16:                 alarmMinute = 0;
 17:                 alarmSecond = 0;
 18:         }
 19: 
 20:         public AlarmClock(int theHour, int theMinute, int theSecond, int alarmH, int alarmM, int alarmS)
 21:         {
 22:                 super(theHour, theMinute, theSecond);
 23:                 setAlarmHour(alarmH);
 24:                 setAlarmMinute(alarmM);
 25:                 setAlarmSecond(alarmS);
 26:         }
 27: 
 28:         //Accessors
 29:         public void setAlarmHour(int alarmH)
 30:         {
 31:                 if((alarmH >= 0) && (alarmH <= 24))
 32:                         alarmHour = alarmH;
 33:                 else
 34:                         System.out.println("Fatal error: invalid alarm hour");
 35:         }
 36: 
 37:         public void setAlarmMinute(int alarmM)
 38:         {
 39:                 if((alarmM >= 0) && (alarmM <= 59))
 40:                         alarmMinute = alarmM;
 41:                 else
 42:                         System.out.println("Fatal error: invalid alarm minute");
 43:         }
 44: 
 45:         public void setAlarmSecond(int alarmS)
 46:         {
 47:                 if((alarmS >= 0) && (alarmS <= 59))
 48:                         alarmSecond = alarmS;
 49:                 else
 50:                         System.out.println("Fatal error: invalid alarm second");
 51:         }
 52:         //Mutators
 53:         public int getAlarmHour()
 54:         {
 55:                 return alarmHour;
 56:         }
 57: 
 58:         public int getAlarmMinute()
 59:         {
 60:                 return alarmMinute;
 61:         }
 62: 
 63:         public int getAlarmSecond()
 64:         {
 65:                 return alarmSecond;
 66:         }
 67: 
 68:         public String getCurrentAlarmTime()
 69:         {
 70:                 return "The alarm is set to " + alarmHour + ":" + alarmMinute + ":" + alarmSecond;
 71:         }
 72: 
 73:         //Facilitators
 74:         public String toString()
 75:         {
 76:                 return "The current time is " + getHour() + ":" + getMinute() + ":" +
 77:                                 getSecond() + "\nThe alarm is set to " + getAlarmHour() + ":" +
 78:                                 getAlarmMinute() + ":" + getAlarmSecond();
 79:         }
 80: 
 81:         public boolean equals(Object o)
 82:         {
 83:                 if(o == null)
 84:                         return false;
 85:                 else if(getClass() != o.getClass())
 86:                         return false;
 87:                 else
 88:                 {
 89:                         AlarmClock otherClock = (AlarmClock) o;
 90:                         return((getHour() == otherClock.getHour()) && (getMinute() == otherClock.getMinute())
 91:                                         && (getSecond() == otherClock.getSecond()) && (alarmHour == otherClock.alarmHour)
 92:                                         && (alarmMinute == otherClock.alarmMinute) && (alarmSecond == otherClock.alarmSecond));
 93:                 }
 94: 
 95:         }
 96: 
 97: }
