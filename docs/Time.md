# `module Time`

# Types and aliases

## `namespace Time`

### `type DateTime = unbox struct { ...fields... }`

The type to represent date and time.

#### field `nanosec : Std::U32`

#### field `sec : Std::U8`

#### field `min : Std::U8`

#### field `hour : Std::U8`

#### field `day_in_month : Std::U8`

#### field `month : Std::U8`

#### field `day_in_week : Std::U8`

#### field `day_in_year : Std::U32`

#### field `year : Std::I32`

#### field `is_dst : Std::Option Std::Bool`

### `type Time = unbox struct { ...fields... }`

The type that represents time by the number of seconds and micro seconds elapsed since the unix epoch.
This struct has two fields, `sec: I64` and `nanosec: U32`.

#### field `sec : Std::I64`

#### field `nanosec : Std::U32`

# Traits and aliases

# Trait implementations

# Values

## `namespace Time`

### `_datetime_to_time_inner : Std::Bool -> Time::DateTime -> Std::Result Std::ErrMsg Time::Time`

Convert datetime to time.
`_datetime_to_time_inner(false)` treats the argument as UTC datetime, and `_datetime_to_time_inner(true)` treats the argument as local datetime.
Note that "local time" depends on timezone, so this function is violating purity.

### `_time_to_datetime_inner : Std::Bool -> Time::Time -> Std::Result Std::ErrMsg Time::DateTime`

Convert time to datetime.
`_time_to_datetime_inner(false)` returns utc datetime, and `_time_to_datetime_inner(true)` returns local datetime.
Note that "local time" depends on timezone, so this function is violating purity.

### `from_local : Time::DateTime -> Std::IO::IOFail Time::Time`

Convert local datetime to time.
This function depends on timezone, so it returns `IOFail` value.

### `from_utc : Time::DateTime -> Std::Result Std::ErrMsg Time::Time`

Convert UTC datetime to time.

### `get_now : Std::IO Time::Time`

Get current time.

### `get_now_monotonic : Std::IO Time::Time`

Get current time using CLOCK_MONOTONIC.

### `to_F64 : Time::Time -> Std::F64`

Convert time to 64-bit floating value.

### `to_local : Time::Time -> Std::IO::IOFail Time::DateTime`

Convert time to local time.
This function depends on timezone, so it returns `IOFail` value.

### `to_utc : Time::Time -> Std::Result Std::ErrMsg Time::DateTime`

Convert time to UTC datetime.