using namespace std;
#include <iostream>
#include <iomanip>

class momento {
private:
    unsigned hour;
    unsigned minutes;
    unsigned secs;
    string morning;

public:
    momento(unsigned new_hora = 0, unsigned new_minutos = 0, unsigned new_segundos = 0, string new_morning = "a.m") :
        hour(new_hora), minutes(new_minutos), secs(new_segundos), morning(new_morning) {
        if (morning != "a.m" && morning != "p.m") {
            throw invalid_argument("morning must be 'a.m' or 'p.m'");
        }
        if (hour > 12) {
            throw invalid_argument("hora must be between 0 and 12");
        }
        if (minutes > 60) {
            throw invalid_argument("minutos must be between 0 and 60");
        }
        if (secs > 60) {
            throw invalid_argument("segundos must be between 0 and 60");
        }
    }
    momento(unsigned new_hora = 0): 
        hour(new_hora), minutes(0),secs(0), morning("a.m"){}
    momento(unsigned new_hora = 0, unsigned new_mins = 0): 
        hour(new_hora), minutes(new_mins),secs(0), morning("a.m"){}
    momento(unsigned new_hora = 0, unsigned new_mins = 0, unsigned new_sec = 0): 
        hour(new_hora), minutes(new_mins),secs(new_sec), morning("a.m"){}

    

    string GetTime() {
        stringstream ss;
        ss << setfill('0') << setw(2) << hour << ":"
           << setfill('0') << setw(2) << minutes << ":"
           << setfill('0') << setw(2) << secs << " " << morning;
        return ss.str();
    }

    string GetHour() {
        stringstream hh;
        hh << setfill('0') << setw(2) << hour;
        return hh.str();
    }
    void SetHour(unsigned new_hour){
        hour = new_hour;
    }

    string GetMinutes() {
        stringstream mm;
        mm << setfill('0') << setw(2) << minutes;
        return mm.str();
    }
    void SetMinutes(unsigned new_mins){
        minutes = new_mins;
    }

    string GetSeconds() {
        stringstream ss;
        ss << setfill('0') << setw(2) << secs;
        return ss.str();
    }
    void SetSeconds(unsigned new_secs){
        secs = new_secs;
    }

    string GetMorning() {
        return morning;
    }
    void SetMorning(string new_mor){
        if (new_mor != "a.m" && new_mor != "p.m") {
            throw invalid_argument("morning must be 'a.m' or 'p.m'");
        }
        else{
            morning = new_mor;
        }
    }

    void print_24hour(){ 
        unsigned true_hour = hour;
        if (morning == "p.m"){
            true_hour += 12;
        }
        stringstream message;
        message << setfill('0') << setw(2) << true_hour << ":"
        << setfill('0') << setw(2) << minutes << ":"
        << setfill('0') << setw(2) << secs << endl;

        cout << message.str();


    }

};
