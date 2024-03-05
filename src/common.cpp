#include "common.h"

namespace cpp_assignment
{
Sensor_reading::Sensor_reading() = default;
Sensor_reading::~Sensor_reading() = default;

BLE_reading::BLE_reading() = default;
BLE_reading::~BLE_reading() = default;
std::string BLE_reading::to_string()
{
  // TODO: add implementation
}

Sensor_reading_type BLE_reading::type()
{
  // TODO: add implementation
}

WiFi_reading::WiFi_reading() = default;
WiFi_reading::~WiFi_reading() = default;
std::string WiFi_reading::to_string()
{
  // TODO: add implementation
}

Sensor_reading_type WiFi_reading::type()
{
  // TODO: add implementation
}
} // namespace cpp_assignment
