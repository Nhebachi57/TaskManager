#include "Utils.h"
#include <ctime>
#include <sstream>
#include <iomanip>

inline std::string getCurrentTime() {
    time_t now = time(0);
    tm localtm;
    localtime_s(&localtm, &now);
    std::ostringstream oss;
    oss << std::put_time(&localtm, "%d-%m-%Y %H-%M-%S");
    return oss.str();
}
