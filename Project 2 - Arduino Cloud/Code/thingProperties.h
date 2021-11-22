#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "00089241-b802-45b6-a74b-ba6f0c587c74";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onEDSwitchChange();

bool lEDSwitch;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(lEDSwitch, READWRITE, ON_CHANGE, onlEDSwitchChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
