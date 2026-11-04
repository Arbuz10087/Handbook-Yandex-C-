const int DAYS_WITHOUT_FEBRUARY = 337;

#include <iostream>
#include <string>

class Date {
    private:
    
    int totaldays;


        int DaysInFebruary (int y) const {
      if ((!(y%4) && y%100) || !(y%400)) {
          return 29;
      } else {
          return 28;
      }
    }

    int DaysInYear(int y) const {
        return DAYS_WITHOUT_FEBRUARY + DaysInFebruary(y);
    }

    int DaysInMonth(int m, int y) const {
        if (m==1 || m == 3 || m ==5 || m == 7 || m == 8|| m == 10 || m == 12) {
            return 31;
        } else if (m == 2) {
            return DaysInFebruary(y);
        } else {
           return 30;
        }
    }

    int TotalDays(int day, int month, int year) const {
        int days=0;
        for (int i = 1970; i< year; ++i) {
            days += DaysInYear(i);
        }
        for (int j = 1; j < month; ++j) {
            days+=DaysInMonth(j, year);
        }
        days+=day;
        return days;
    }

    bool IsCorrectDate(int day, int month, int year) const {
        return month>=1 && month <= 12 && day <= DaysInMonth(month, year) && day >0;
    }


        Date MakeDate(int days) const {
         int day_n = 1;
         int month_n = 1;
         int year_n = 1970;
         while (days> DaysInYear(year_n)) {
             days-=DaysInYear(year_n);
             ++year_n;
         }
         while (days> DaysInMonth(month_n, year_n)) {
             days-=DaysInMonth(month_n, year_n);
             ++month_n;
         }
         day_n+=days-1;
      return Date(day_n, month_n, year_n);
    }


    
    public:

    Date (int d, int m, int y):
         totaldays(TotalDays(d, m, y))
          {
              if (!IsCorrectDate(d, m, y)) {
               totaldays = 0;
              }
          }

    int GetDay() const {
        int days = totaldays;
        int day = 1;
         int month = 1;
         int year = 1970;
         while (days> DaysInYear(year)) {
             days-=DaysInYear(year);
             ++year;
         }
         while (days> DaysInMonth(month, year)) {
             days-=DaysInMonth(month, year);
             ++month;
         }
         day+=days-1;
        return day;
    }

    int GetMonth() const {
        int days = totaldays;
        int month = 1;
         int year = 1970;
         while (days> DaysInYear(year)) {
             days-=DaysInYear(year);
             ++year;
         }
         while (days> DaysInMonth(month, year)) {
             days-=DaysInMonth(month, year);
             ++month;
         }
        return month;
    }


    int GetYear() const {
        int year=1970;
        int days = totaldays;
         while (days> DaysInYear(year)) {
             days-=DaysInYear(year);
             ++year;
         }

        return year;
    } 

    int GetTotalDays() const {
        return totaldays;
    }
     
    Date operator+ (int days) const {
            return MakeDate(totaldays+days);
        }
    

    Date operator- (int days) const {
        return MakeDate(totaldays-days);
    }

 
};

   int operator- (const Date& lhs, const Date& rhs)  {
      return lhs.GetTotalDays() - rhs.GetTotalDays();
    }