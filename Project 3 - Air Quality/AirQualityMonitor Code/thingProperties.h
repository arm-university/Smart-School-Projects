#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "3ea10f1a-d4b0-49ce-8d0d-a9eaf375d248";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onReadingChange();

int reading;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(reading, READWRITE, 1 * SECONDS, onReadingChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
