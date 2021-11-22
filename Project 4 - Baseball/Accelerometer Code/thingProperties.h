#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "cbf11135-58f7-4239-b3cb-9b9c5bd170ba";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onXAxisChange();
void onYAxisChange();
void onZAxisChange();

int xAxis;
int yAxis;
int zAxis;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(xAxis, READWRITE, ON_CHANGE, onXAxisChange);
  ArduinoCloud.addProperty(yAxis, READWRITE, ON_CHANGE, onYAxisChange);
  ArduinoCloud.addProperty(zAxis, READWRITE, ON_CHANGE, onZAxisChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
