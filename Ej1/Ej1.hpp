#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
using namespace std;
class momento {
private:
    unsigned hour;
    unsigned minutes;
    unsigned secs;
    string morning;

public:
    momento();
    momento(unsigned new_hora, unsigned new_minutos, unsigned new_segundos, string new_morning);
    momento(unsigned new_hora);
    momento(unsigned new_hora, unsigned new_mins);
    momento(unsigned new_hora, unsigned new_mins, unsigned new_sec);

    string GetTime();
    string GetHour();
    void SetHour(unsigned new_hour);
    string GetMinutes();
    void SetMinutes(unsigned new_mins);
    string GetSeconds();
    void SetSeconds(unsigned new_secs);
    string GetMorning();
    void SetMorning(string new_mor);
    void print_24hour();
};;