#include "Ej1.hpp"

momento::momento(unsigned new_hora, unsigned new_minutos, unsigned new_segundos, std::string new_morning) 
    : hour(new_hora), minutes(new_minutos), secs(new_segundos), morning(new_morning) {
    if (morning != "a.m" && morning != "p.m") {
        throw std::invalid_argument("morning must be 'a.m' or 'p.m'");
    }
    if (hour > 12) {
        throw std::invalid_argument("hora must be between 0 and 12");
    }
    if (minutes > 60) {
        throw std::invalid_argument("minutos must be between 0 and 60");
    }
    if (secs > 60) {
        throw std::invalid_argument("segundos must be between 0 and 60");
    }
}

momento::momento(unsigned new_hora) : hour(new_hora), minutes(0), secs(0), morning("a.m") {}

momento::momento(unsigned new_hora, unsigned new_mins) : hour(new_hora), minutes(new_mins), secs(0), morning("a.m") {}

momento::momento(unsigned new_hora, unsigned new_mins, unsigned new_sec) : hour(new_hora), minutes(new_mins), secs(new_sec), morning("a.m") {}

std::string momento::GetTime() {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hour << ":"
       << std::setfill('0') << std::setw(2) << minutes << ":"
       << std::setfill('0') << std::setw(2) << secs << " " << morning;
    return ss.str();
}

std::string momento::GetHour() {
    std::stringstream hh;
    hh << std::setfill('0') << std::setw(2) << hour;
    return hh.str();
}

void momento::SetHour(unsigned new_hour) {
    hour = new_hour;
}

std::string momento::GetMinutes() {
    std::stringstream mm;
    mm << std::setfill('0') << std::setw(2) << minutes;
    return mm.str();
}

void momento::SetMinutes(unsigned new_mins) {
    minutes = new_mins;
}

std::string momento::GetSeconds() {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << secs;
    return ss.str();
}

void momento::SetSeconds(unsigned new_secs) {
    secs = new_secs;
}

std::string momento::GetMorning() {
    return morning;
}

void momento::SetMorning(std::string new_mor) {
    if (new_mor != "a.m" && new_mor != "p.m") {
        throw std::invalid_argument("morning must be 'a.m' or 'p.m'");
    }
    morning = new_mor;
}

void momento::print_24hour() {
    unsigned true_hour = hour;
    if (morning == "p.m") {
        true_hour += 12;
    }
    std::stringstream message;
    message << std::setfill('0') << std::setw(2) << true_hour << ":"
            << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << secs << std::endl;

    std::cout << message.str();
}
