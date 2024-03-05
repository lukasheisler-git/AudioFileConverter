#pragma once

#include <string>

namespace cpp_assignment
{
enum class Sensor_reading_type
{
  BLE,
  WiFi
};

class Sensor_reading
{
public:
  Sensor_reading();
  virtual ~Sensor_reading();
  virtual std::string to_string() = 0;
  virtual Sensor_reading_type type() = 0;

protected:
  std::string m_ssid;
  std::string m_bssid;
  std::int32_t m_rssi;
  std::int32_t m_timestamp;
};

class BLE_reading : public Sensor_reading
{
public:
  BLE_reading();
  virtual ~BLE_reading();
  std::string to_string() override;
  Sensor_reading_type type() override;
};

class WiFi_reading : public Sensor_reading
{
public:
  WiFi_reading();
  virtual ~WiFi_reading();
  std::string to_string() override;
  Sensor_reading_type type() override;
};

} // namespace cpp_assignment