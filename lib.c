#ifndef __MINGW32__
#include <sys/time.h>
#endif // __MINGW32__
#include <time.h>
#include <stdint.h>

#ifdef __MINGW32__
#define timegm _mkgmtime

struct tm *localtime_r(const time_t *timer, struct tm *buf)
{
    if (localtime_s(buf, timer))
    {
        return NULL;
    }
    return buf;
}

struct tm *gmtime_r(const time_t *timer, struct tm *buf)
{
    if (gmtime_s(buf, timer))
    {
        return NULL;
    }
    return buf;
}
#endif // __MINGW32__

void fixtime_clock_gettime(int64_t *ret)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ret[0] = (int64_t)ts.tv_sec;
    ret[1] = (int64_t)ts.tv_nsec;
}

void fixtime_clock_gettime_monotonic(int64_t *ret)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    ret[0] = (int64_t)ts.tv_sec;
    ret[1] = (int64_t)ts.tv_nsec;
}

void fixtime_gmlocaltime(uint8_t is_local, uint64_t sec, int64_t *ret)
{
    // struct tm *gmtime_r(const time_t *timep, struct tm *result);
    time_t time = (time_t)sec;
    struct tm datetime;
    struct tm *is_suc;
    if (is_local > 0)
    {
        is_suc = localtime_r(&time, &datetime);
    }
    else
    {
        is_suc = gmtime_r(&time, &datetime);
    }
    ret[0] = (int64_t)datetime.tm_sec;
    ret[1] = (int64_t)datetime.tm_min;
    ret[2] = (int64_t)datetime.tm_hour;
    ret[3] = (int64_t)datetime.tm_mday;
    ret[4] = (int64_t)datetime.tm_mon;
    ret[5] = (int64_t)datetime.tm_year;
    ret[6] = (int64_t)datetime.tm_wday;
    ret[7] = (int64_t)datetime.tm_yday;
    ret[8] = (int64_t)datetime.tm_isdst;
    ret[9] = (int64_t)(is_suc == NULL);
}

int64_t fixtime_timegmlocal(uint8_t is_local, int64_t *data)
{
    struct tm datetime;
    datetime.tm_sec = (int)data[0];
    datetime.tm_min = (int)data[1];
    datetime.tm_hour = (int)data[2];
    datetime.tm_mday = (int)data[3];
    datetime.tm_mon = (int)data[4];
    datetime.tm_year = (int)data[5];
    datetime.tm_wday = (int)data[6];
    datetime.tm_yday = (int)data[7];
    datetime.tm_isdst = (int)data[8];
    time_t ret;
    if (is_local > 0)
    {
        ret = mktime(&datetime);
    }
    else
    {
        ret = timegm(&datetime);
    }
    return (int64_t)ret;
}