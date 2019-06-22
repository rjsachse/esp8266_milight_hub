#include <BulbId.h>

BulbId::BulbId()
  : deviceId(0),
    groupId(0),
    deviceType(REMOTE_TYPE_UNKNOWN)
{ }

BulbId::BulbId(const BulbId &other)
  : deviceId(other.deviceId),
    groupId(other.groupId),
    deviceType(other.deviceType)
{ }

BulbId::BulbId(
  const uint16_t deviceId, const uint8_t groupId, const MiLightRemoteType deviceType
)
  : deviceId(deviceId),
    groupId(groupId),
    deviceType(deviceType)
{ }

void BulbId::operator=(const BulbId &other) {
  deviceId = other.deviceId;
  groupId = other.groupId;
  deviceType = other.deviceType;
}

// determine if now BulbId's are the same.  This compared deviceID (the controller/remote ID) and
// groupId (the group number on the controller, 1-4 or 1-8 depending), but ignores the deviceType
// (type of controller/remote) as this doesn't directly affect the identity of the bulb
bool BulbId::operator==(const BulbId &other) {
  return deviceId == other.deviceId
    && groupId == other.groupId
    && deviceType == other.deviceType;
}