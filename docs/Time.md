# Time

Defined in time@1.1.0

## Values

### namespace Time

#### from_local

Type: `Time::DateTime -> Std::IO::IOFail Time::Time`

Convert local datetime to time.
This function depends on timezone, so it returns `IOFail` value.

#### from_utc

Type: `Time::DateTime -> Std::Result Std::ErrMsg Time::Time`

Convert UTC datetime to time.

#### get_now

Type: `Std::IO Time::Time`

Get current time.

#### get_now_monotonic

Type: `Std::IO Time::Time`

Get current time using CLOCK_MONOTONIC.

#### to_F64

**Deprecated**: Use the trait member `ToF64::f64` instead.

Type: `Time::Time -> Std::F64`

Convert time to 64-bit floating value.

#### to_local

Type: `Time::Time -> Std::IO::IOFail Time::DateTime`

Convert time to local time.
This function depends on timezone, so it returns `IOFail` value.

#### to_utc

Type: `Time::Time -> Std::Result Std::ErrMsg Time::DateTime`

Convert time to UTC datetime.

## Types and aliases

### namespace Time

#### DateTime

Defined as: `type DateTime = unbox struct { ...fields... }`

The type to represent date and time.

##### field `nanosec`

Type: `Std::U32`

##### field `sec`

Type: `Std::U8`

##### field `min`

Type: `Std::U8`

##### field `hour`

Type: `Std::U8`

##### field `day_in_month`

Type: `Std::U8`

##### field `month`

Type: `Std::U8`

##### field `day_in_week`

Type: `Std::U8`

##### field `day_in_year`

Type: `Std::U32`

##### field `year`

Type: `Std::I32`

##### field `is_dst`

Type: `Std::Option Std::Bool`

#### Time

Defined as: `type Time = unbox struct { ...fields... }`

The type that represents time by the number of seconds and micro seconds elapsed since the unix epoch.
This struct has two fields, `sec: I64` and `nanosec: U32`.

##### field `sec`

Type: `Std::I64`

##### field `nanosec`

Type: `Std::U32`

## Traits and aliases

## Trait implementations

### impl `Time::Time : Std::ToF64`